//
// DeplacementSystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/systems
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Wed May 11 15:59:24 2016 Barthelemy Gouby
// Last update Sun Jun 12 12:10:20 2016 Thomas Bogard
//

#include "../Engine.hh"

void			Engine::movementSystem()
{
  std::vector<Entity*>  *movableEntities =
    this->_entityManager.getEntitiesWithComponents({Component::POSITION_COMPONENT,
	  Component::SPEED_COMPONENT});
  std::vector<Entity*>  *solidEntities =
    this->_entityManager.getEntitiesWithComponents({Component::POSITION_COMPONENT,
	  Component::SOLIDITY_COMPONENT});
  SpeedComponent	*speedComponent;
  PositionComponent	*positionComponent;
  unsigned int		newX;
  unsigned int		newY;
  bool			blocked;

  for (Entity *movable: *movableEntities)
    {
      blocked = false;
      speedComponent = (SpeedComponent*) movable->getComponent(Component::SPEED_COMPONENT);
      if (speedComponent->getSpeedX() || speedComponent->getSpeedY())
	{
	  positionComponent = (PositionComponent*) movable->getComponent(Component::POSITION_COMPONENT);
	  newX = positionComponent->getX() + speedComponent->getSpeedX();
	  newY = positionComponent->getY() + speedComponent->getSpeedY();
	  this->_display.updateModelPosition(movable->getId(),
					     positionComponent->getRotation(),
					     newX,
					     newY);

	  // rotation
	  if (speedComponent->getSpeedX() < 0)
	    positionComponent->setRotation(90);
	  else if (speedComponent->getSpeedX() > 0)
	    positionComponent->setRotation(270);
	  else if (speedComponent->getSpeedY() < 0)
	    positionComponent->setRotation(360);
	  else if (speedComponent->getSpeedY() > 0)
	    positionComponent->setRotation(180);

	  for (Entity *solid: *solidEntities)
	    {
	      if (solid != movable && this->_display.collision(movable->getId(), solid->getId()))
		{
		  blocked = true;
		  break;
		}
	    }
	  if (blocked)
	    {
	      this->_display.updateModelPosition(movable->getId(), positionComponent->getRotation(),
						 positionComponent->getX(), positionComponent->getY());
	      this->_display.updateModel(movable, ModelComponent::DEFAULT);
	    }
	  else
	    {
	      this->_display.updateModel(movable, ModelComponent::RUN);
	      positionComponent->setX(newX);
	      positionComponent->setY(newY);
	    }
	}
      else if (!this->_isDropped)
	{
	  this->_display.updateModel(movable, ModelComponent::DEFAULT);
	}
    }
}
