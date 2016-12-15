//
// guiSystem.cpp for indie studio
//
// Made by Thomas Bogard
// Login   <bogard_t@epitech.net>
//
// Started on  Tue May 24 20:12:10 2016 Thomas Bogard
// Last update Thu Jun  2 20:34:50 2016 Barthelemy Gouby
//

# include "../Engine.hh"

void		Engine::guiSystem()
{
  PlayerInputComponent  *playerInputComponent;
  HealthComponent	*healthComponent;
  std::vector<Entity*>  *playerEntities =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  unsigned int		playerIndex = 1;
  int			x = -1;
  unsigned int		y = 300;

  for (Entity *player : *playerEntities)
    {
      playerInputComponent = (PlayerInputComponent*) player->getComponent(Component::PLAYER_INPUT_COMPONENT);
      healthComponent = (HealthComponent*) player->getComponent(Component::HEALTH_COMPONENT);

      const unsigned int& speedIndex = ((playerInputComponent->getSpeed() % 50) / 10) - 1;
      const unsigned int& bombIndex = playerInputComponent->getMaxBombs() - 1;
      const unsigned int& fireIndex = playerInputComponent->getExplosionSize() - 2;
      const unsigned int& lifeIndex = healthComponent->getLives() - 1;

      if (healthComponent->getLives() > 1)
	{
	  if (playerIndex == 1)
	    x = 200 * (lifeIndex - 1);
	  else if (playerIndex == 2)
	    x = (lifeIndex ? (8000 - (200 * (lifeIndex - 1))) : (8000));
	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/heart.png",
					x, 300, irr::core::vector3df(90, 270, 90), 150);

	  if (playerIndex == 1)
	    this->_display.guiRemoveModel(200 * (lifeIndex), 300);
	  else if (playerIndex == 2)
	    this->_display.guiRemoveModel(8000 - (200 * (lifeIndex)), 300);
	}

      if (x == -1 && playerIndex == 1)
	this->_display.guiRemoveModel(0, 300);
      if (x == 200 && playerIndex == 2)
	this->_display.guiRemoveModel(8000, 300);

      if (playerInputComponent->getMaxBombs() >= 1)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * bombIndex;
      	  else if (playerIndex == 2)
      	    x = (bombIndex ? (8000 - (200 * bombIndex)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/bombup.png",
					x, 500, irr::core::vector3df(90, 270, 90), 150);
      	}

      if (playerInputComponent->getSpeed() >= 60)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * speedIndex;
      	  else if (playerIndex == 2)
      	    x = (speedIndex ? (8000 - (200 * speedIndex)) : (8000));
      	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/speedup.png",
					x, 700, irr::core::vector3df(90, 270, 90), 150);
      	}

      if (playerInputComponent->getExplosionSize() > 1)
      	{
      	  if (playerIndex == 1)
      	    x = 200 * fireIndex;
      	  else if (playerIndex == 2)
      	    x = (fireIndex ? (8000 - (200 * fireIndex)) : (8000));
       	  this->_display.guiCreateModel("./models/cube.obj", "./textures/powerup/fireup.png",
					x, 900, irr::core::vector3df(90, 270, 90), 150);
      	}

      ++playerIndex;
    }

  if (this->_display._receiver->IsKeyDown(irr::KEY_ESCAPE))
    this->_gameIsOn = false;
}
