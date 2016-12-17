//
// Bomberman
//

#include "../Engine.hh"

void				Engine::_addNewExplosion(const unsigned int &x,
							 const unsigned &y,
							 bool &isBlocked)
{
  Entity			*newExplosion;
  bool				canAddExplosion = true;
  std::vector<Entity*>		*solids =
    this->_entityManager.getEntitiesWithComponents({Component::SOLIDITY_COMPONENT});
  HealthComponent		*healthComponent;

  if (!isBlocked)
    {
      for (Entity *solid: *solids)
  	{
  	  if (this->_display.tileIsOccupied(x, y, solid))
  	    {
  	      if ((healthComponent = (HealthComponent*) solid->getComponent(Component::HEALTH_COMPONENT)))
		healthComponent->setLives(healthComponent->getLives() - 1);
  	      else
		canAddExplosion = false;
  	      isBlocked = true;
	      break;
  	    }
  	}
      if (canAddExplosion)
  	{
  	  newExplosion = this->_entityFactory.createExplosion(x, y, 0);
  	  this->_entityManager.addEntity(newExplosion);
  	  this->_display.createModel(newExplosion);
  	}
    }
}

void				Engine::ExplosiveSystem()
{
  std::vector<Entity*>		*explosives =
    this->_entityManager.getEntitiesWithComponents({Component::EXPLOSIVE_COMPONENT});
  std::vector<Entity*>		*solids;
  PositionComponent		*bombPosition;
  ExplosiveComponent		*explosiveComponent;
  Entity			*newExplosionCenter;
  Entity			*owner;
  bool				leftIsBlocked;
  bool				rightIsBlocked;
  bool				downIsBlocked;
  bool				upIsBlocked;

  for (Entity *explosive: *explosives)
    {
      explosiveComponent = (ExplosiveComponent*) explosive->getComponent(Component::EXPLOSIVE_COMPONENT);
      if (explosiveComponent->getTimerLength() <= 0)
	{
	  leftIsBlocked = false;
	  rightIsBlocked = false;
	  downIsBlocked = false;
	  upIsBlocked = false;
	  bombPosition = (PositionComponent*) explosive->getComponent(Component::POSITION_COMPONENT);
	  newExplosionCenter =
	    this->_entityFactory.createExplosion(bombPosition->getX(),
						 bombPosition->getY(),
						 0);
	  this->_entityManager.addEntity(newExplosionCenter);
	  this->_display.createModel(newExplosionCenter);
	  for (unsigned int i = 1; i <= explosiveComponent->getExplosionSize(); i++)
	    {
	      this->_addNewExplosion(bombPosition->getX() - i * TILE_SIZE,
				     bombPosition->getY(),
				     leftIsBlocked);
	      this->_addNewExplosion(bombPosition->getX() + i * TILE_SIZE,
				     bombPosition->getY(),
				     rightIsBlocked);
	      this->_addNewExplosion(bombPosition->getX(),
				     bombPosition->getY() - i * TILE_SIZE,
				     downIsBlocked);
	      this->_addNewExplosion(bombPosition->getX(),
				     bombPosition->getY() + i * TILE_SIZE,
				     upIsBlocked);
	    }
	  owner = this->_entityManager.getEntity(explosiveComponent->getOwnerId());
	  if (owner && explosiveComponent->getOwnerType() == ExplosiveComponent::PLAYER)
	    ((PlayerInputComponent*)(owner->getComponent(Component::PLAYER_INPUT_COMPONENT)))
	      ->decrementActiveBombs();
	  this->_display.removeModel(explosive);
	  this->_entityManager.destroyEntity(explosive->getId());
	  this->_audio.makeSound("./sound/explosion.wav");
	}
      else
	explosiveComponent->setTimerLength(explosiveComponent->getTimerLength() - 1);
    }
}
