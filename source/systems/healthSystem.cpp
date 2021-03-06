//
// Bomberman
//

#include "../Engine.hh"

void			Engine::healthSystem()
{
  std::vector<Entity*>	*destructibles =
    this->_entityManager.getEntitiesWithComponents({Component::HEALTH_COMPONENT});
  HealthComponent	*healthComponent;
  ContainerComponent	*containerComponent;
  PositionComponent	*positionComponent;
  Entity		*powerUp;

  for (Entity *destructible: *destructibles)
    {
      healthComponent = (HealthComponent*) destructible->getComponent(Component::HEALTH_COMPONENT);
      if (healthComponent->getInvincibleTimer() > 0)
	{
	  if (healthComponent->getInvincibleTimer() % 10 > 5)
	    this->_display.changeMaterialType(destructible, irr::video::EMT_TRANSPARENT_ADD_COLOR);
	  else
	    this->_display.changeMaterialType(destructible, irr::video::EMT_SOLID);
	  healthComponent->setInviciblesTimer(healthComponent->getInvincibleTimer() - 1);
	}
      else
	this->_display.changeMaterialType(destructible, irr::video::EMT_SOLID);
      if (healthComponent->getLives() <= 0)
	{
	  containerComponent = (ContainerComponent*) destructible->getComponent(Component::CONTAINER_COMPONENT);
	  if (containerComponent)
	    {
	      positionComponent = (PositionComponent*) destructible->getComponent(Component::POSITION_COMPONENT);
	      powerUp = this->_entityFactory.createPowerUp(positionComponent->getX(),
							   positionComponent->getY(),
							   containerComponent->getContainedType());
	      this->_entityManager.addEntity(powerUp);
	      this->_display.createModel(powerUp);
	    }
	  if (destructible->getComponent(Component::PLAYER_INPUT_COMPONENT))
	    this->_audio.makeSound("sound/humiliation.wav");
	  this->_display.removeModel(destructible);
	  this->_entityManager.destroyEntity(destructible->getId());
	}
    }
}
