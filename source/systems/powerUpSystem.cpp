//
// Bomberman
//

#include "../Engine.hh"

void			Engine::powerUpSystem()
{
  std::vector<Entity*>	*powerUps =
    this->_entityManager.getEntitiesWithComponents({Component::POWER_UP_COMPONENT});
  std::vector<Entity*>	*players =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  PlayerInputComponent	*playerInputComponent;
  PowerUpComponent	*powerUpComponent;
  HealthComponent	*healthComponent;

  for (Entity *powerUp: *powerUps)
    {
      for (Entity *player: *players)
	{
	  if (this->_display.collision(powerUp->getId(), player->getId()))
	    {
	      playerInputComponent =
		(PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
	      powerUpComponent =
		(PowerUpComponent*) powerUp->getComponent(Component::POWER_UP_COMPONENT);
	      switch (powerUpComponent->getType())
		{
		case PowerUpComponent::BOMB_UP:
		  playerInputComponent->setMaxBombs(playerInputComponent->getMaxBombs() + 1);
		  break;
		case PowerUpComponent::FIRE_UP:
		  playerInputComponent->setExplosionSize(playerInputComponent->getExplosionSize() + 1);
		  break;
		case PowerUpComponent::SPEED_UP:
		  playerInputComponent->setSpeed(playerInputComponent->getSpeed() + 10);
		  break;
		case PowerUpComponent::LIVE_UP:
		  healthComponent = (HealthComponent*) player->getComponent(Component::HEALTH_COMPONENT);
		  healthComponent->setLives(healthComponent->getLives() + 1);
		  break;

		default:
		  break;
		}
	      this->_audio.makeSound("sound/firearm.ogg");
	      this->_display.removeModel(powerUp);
	      this->_entityManager.destroyEntity(powerUp->getId());
	      break;
	    }
	}
    }
}
