//
// Bomberman
//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>
#include "Engine.hh"

Engine::Engine()
  : _systems({	&Engine::playerInputSystem,
		&Engine::movementSystem,
		&Engine::ExplosiveSystem,
		&Engine::ExplosionSystem,
		&Engine::powerUpSystem,
		&Engine::healthSystem,
		&Engine::guiSystem,
		&Engine::basicEnemySystem})
{
  this->_entityManager.setDisplay(&this->_display);
}

Engine::~Engine()
{
}

static std::string				getLayout(void)
{
  int		i = 0;
  bool		spaces = false;
  bool		end_spaces = false;
  FILE		*in;
  char		buff[512];
  std::string	layout;

  if (!(in = popen("setxkbmap -query | grep layout", "r")))
    exit(1);
  while (fgets(buff, sizeof(buff), in));
  pclose(in);
  while (buff[i])
    {
      if (buff[i] == ' ')
	spaces = true;
      if (spaces)
	{
	  if (buff[i] != ' ')
	    end_spaces = true;
	}
      if (end_spaces)
	layout += buff[i];
      i++;
    }
  return (layout);
}

void					Engine::initMap(const std::vector<int> &map)
{
  Entity				*entity;
  bool					layoutIsFr = false;;

  if (getLayout() == "fr")
    layoutIsFr = true;
  for (unsigned int i = 0; i < map.size(); i++)
    {
      if (map[i] != EntityFactory::EMPTY)
	{
	  switch (map[i])
	    {
	    case EntityFactory::SOLID_BLOCK:
	      entity = this->_entityFactory.createSolidBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							     (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
	      break;
	    case EntityFactory::DESTRUCTIBLE_BLOCK:
	      entity = this->_entityFactory.createDestructibleBlock((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								    (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2, 0);
	      break;
	    case EntityFactory::BOMB_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::BOMB_UP);
	      break;
	    case EntityFactory::FIRE_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::FIRE_UP);
	      break;
	    case EntityFactory::SPEED_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::SPEED_UP);
	      break;
	    case EntityFactory::LIVE_UP_POWER_UP:
	      entity = this->_entityFactory.createPowerUpContainer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
								   PowerUpComponent::LIVE_UP);
	      break;
	    case EntityFactory::BASIC_ENEMY:
	      entity = this->_entityFactory.createBasicEnemy((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							     (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2);
	      break;
	    case EntityFactory::PLAYER_ONE:
	      entity = this->_entityFactory.createPlayer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 0,
							 // irr::KEY_KEY_Z,
							 (layoutIsFr ? irr::KEY_KEY_Z : irr::KEY_KEY_W),
							 irr::KEY_KEY_S,
							 // irr::KEY_KEY_Q,
							 (layoutIsFr ? irr::KEY_KEY_Q : irr::KEY_KEY_A),
							 irr::KEY_KEY_D,
							 irr::KEY_SPACE, 1, 1, 50, "./textures/bomberman_blue.png",
							 &(this->_display));
	      break;
	    case EntityFactory::PLAYER_TWO:
	      entity = this->_entityFactory.createPlayer((i / MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 (i % MAP_SIZE) * TILE_SIZE + TILE_SIZE / 2,
							 0,
							 irr::KEY_UP,
							 irr::KEY_DOWN, irr::KEY_LEFT, irr::KEY_RIGHT,
							 irr::KEY_RETURN, 1, 1, 50, "./textures/bomberman_green.png",
							 &(this->_display));
	      break;
	    default:
	      break;
	    }
          this->_display.createModel(entity);
	  this->_entityManager.addEntity(entity);
	}
    }
}

void					Engine::removeEntities()
{
  std::vector<Entity*>			entities = this->_entityManager.getEntities();

  this->_display.removeGround();
  for (Entity *entity: entities)
    {
      this->_display.removeModel(entity);
      this->_entityManager.destroyEntity(entity->getId());
    }
}

void					Engine::initGame(irr::IrrlichtDevice *device,
							 EventReceiver *receiver,
							 GameType gameType)
{
  #include "map.hh"
  this->_gameType = gameType;
  this->_display.init(device, receiver);
  if (gameType == SOLO)
    this->initMap(mapSolo);
  else if (gameType == VERSUS)
    this->initMap(mapVersus);
  else if (gameType == COOP)
    this->initMap(mapCoop);
}

void					Engine::setVolumeMusic(const unsigned int &volume)
{
  this->_audio.musicSetVolume(volume);
}

void					Engine::setVolumeSound(const unsigned int &volume)
{
  this->_audio.soundSetVolume(volume);
}

void					Engine::saveGame(const std::string &fileName)
{
  this->_entityManager.serialize(fileName);
}

void					Engine::loadSave(const std::string &fileName,
							 EventReceiver *receiver,
							 irr::IrrlichtDevice *device)
{
  this->_display.init(device, receiver);
  this->_entityManager.unserialize(fileName, &this->_display);
}

void					Engine::makeMusic()
{
  this->_audio.makeMusic("sound/mortalkombat.wav");
  this->_audio.musicSetLoop(true);
}

void					Engine::gameLoop()
{
  std::chrono::system_clock::time_point	now;

  this->_gameIsOn = true;
  this->_lastTick = std::chrono::system_clock::now();
  this->_display.setCursorVisibility(false);
  while (this->_gameIsOn)
    {
      now = std::chrono::system_clock::now();
      if (std::chrono::duration_cast<std::chrono::milliseconds>(now - this->_lastTick).count() > TICK_DURATION)
	{
	  this->_lastTick = now;
	  for (auto system: this->_systems)
	    (this->*system)();
	}
      (this->_display.windowIsActive() ? this->_display.refreshScreen() : this->_gameIsOn = false);
    }
  this->_display.setCursorVisibility(true);
}
