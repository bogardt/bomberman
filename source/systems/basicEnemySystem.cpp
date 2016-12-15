//
// basicEnemySystem.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Fri May 27 18:51:39 2016 Barthelemy Gouby
// Last update Fri Jun  3 15:19:13 2016 Barthelemy Gouby
//

#include "../Engine.hh"

void					Engine::basicEnemySystem()
{
  std::vector<Entity*>			*basicEnemies =
    this->_entityManager.getEntitiesWithComponents({Component::BASIC_ENEMY_COMPONENT});
  std::vector<Entity*>			*solids =
    this->_entityManager.getEntitiesWithComponents({Component::SOLIDITY_COMPONENT});
  std::vector<Entity*>			*players =
    this->_entityManager.getEntitiesWithComponents({Component::PLAYER_INPUT_COMPONENT});
  BasicEnemyComponent			*basicEnemyComponent;
  PositionComponent			*positionComponent;
  SpeedComponent			*speedComponent;
  HealthComponent			*healthComponent;
  PositionComponent			validTiles[4];
  PositionComponent			tileInFrontPos;
  unsigned int				numberOfValidTiles;
  bool					upIsValid;
  bool					downIsValid;
  bool					leftIsValid;
  bool					rightIsValid;
  bool					tileInFrontIsOccupied;
  std::random_device			rd;
  std::mt19937				rng(rd());
  int					randomTile;

  for (Entity *basicEnemy: *basicEnemies)
    {
      basicEnemyComponent = (BasicEnemyComponent*) basicEnemy->getComponent(Component::BASIC_ENEMY_COMPONENT);
      positionComponent = (PositionComponent*) basicEnemy->getComponent(Component::POSITION_COMPONENT);
      speedComponent = (SpeedComponent*) basicEnemy->getComponent(Component::SPEED_COMPONENT);

      for (Entity *player: *players)
	{
	  if (this->_display.collision(basicEnemy->getId(), player->getId()))
	    {
	      healthComponent = (HealthComponent*) player->getComponent(Component::HEALTH_COMPONENT);
	      if (healthComponent->getInvincibleTimer() <= 0)
		{
		  healthComponent->setLives(healthComponent->getLives() - 1);
		  healthComponent->setInviciblesTimer(110);
		}
	    }
	}

      if (basicEnemyComponent->getTileGoingToX() == positionComponent->getX()
	  && basicEnemyComponent->getTileGoingToY() == positionComponent->getY())
	{
	  numberOfValidTiles = 0;
	  tileInFrontIsOccupied = false;
	  if (speedComponent->getSpeedY() < 0)
	    {
	      tileInFrontPos.setX(positionComponent->getX());
	      tileInFrontPos.setY(positionComponent->getY() - TILE_SIZE);
	      upIsValid = false;
	    }
	  else
	    upIsValid = true;
	  if (speedComponent->getSpeedY() > 0)
	    {
	      tileInFrontPos.setX(positionComponent->getX());
	      tileInFrontPos.setY(positionComponent->getY() + TILE_SIZE);
	      downIsValid = false;
	    }
	  else
	    downIsValid = true;
	  if (speedComponent->getSpeedX() > 0)
	    {
	      tileInFrontPos.setX(positionComponent->getX() + TILE_SIZE);
	      tileInFrontPos.setY(positionComponent->getY());
	      leftIsValid = false;
	    }
	  else
	    leftIsValid = true;
	  if (speedComponent->getSpeedX() < 0)
	    {
	      tileInFrontPos.setX(positionComponent->getX() - TILE_SIZE);
	      tileInFrontPos.setY(positionComponent->getY());
	      rightIsValid = false;
	    }
	  else
	    rightIsValid = true;

	  for (Entity *solid: *solids)
	    {
	      if (this->_display.tileIsOccupied(tileInFrontPos.getX(),
						tileInFrontPos.getY(),
						solid))
		  tileInFrontIsOccupied = true;
	      if (this->_display.tileIsOccupied(positionComponent->getX(),
						positionComponent->getY() + TILE_SIZE,
						solid))
		upIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX(),
						positionComponent->getY() - TILE_SIZE,
						solid))
		downIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX() - TILE_SIZE,
						positionComponent->getY(),
						solid))
		leftIsValid = false;
	      if (this->_display.tileIsOccupied(positionComponent->getX() + TILE_SIZE,
						positionComponent->getY(),
						solid))
		rightIsValid = false;
	    }

	  if ((speedComponent->getSpeedX() != 0 || speedComponent->getSpeedY() != 0) && !tileInFrontIsOccupied)
	    {
	      basicEnemyComponent->setTileGoingToX(tileInFrontPos.getX());
	      basicEnemyComponent->setTileGoingToY(tileInFrontPos.getY());
	    }
	  else
	    {
	      if (upIsValid)
		{
		  validTiles[numberOfValidTiles].setX(positionComponent->getX());
		  validTiles[numberOfValidTiles].setY(positionComponent->getY() + TILE_SIZE);
		  numberOfValidTiles++;
		}
	      if (downIsValid)
		{
		  validTiles[numberOfValidTiles].setX(positionComponent->getX());
		  validTiles[numberOfValidTiles].setY(positionComponent->getY() - TILE_SIZE);
		  numberOfValidTiles++;
		}
	      if (leftIsValid)
		{
		  validTiles[numberOfValidTiles].setX(positionComponent->getX() - TILE_SIZE);
		  validTiles[numberOfValidTiles].setY(positionComponent->getY());
		  numberOfValidTiles++;
		}
	      if (rightIsValid)
		{
		  validTiles[numberOfValidTiles].setX(positionComponent->getX() + TILE_SIZE);
		  validTiles[numberOfValidTiles].setY(positionComponent->getY());
		  numberOfValidTiles++;
		}
	      if (numberOfValidTiles > 0)
		{
		  std::uniform_int_distribution<int>	distribution(1, numberOfValidTiles);
		  randomTile = distribution(rng) - 1;
		  basicEnemyComponent->setTileGoingToX(validTiles[randomTile].getX());
		  basicEnemyComponent->setTileGoingToY(validTiles[randomTile].getY());
		}
	      else
		{
		  basicEnemyComponent->setTileGoingToX(basicEnemyComponent->getTileComingFromX());
		  basicEnemyComponent->setTileGoingToY(basicEnemyComponent->getTileComingFromY());
		}
	    }
	  basicEnemyComponent->setTileComingFromX(positionComponent->getX());
	  basicEnemyComponent->setTileComingFromY(positionComponent->getY());
	  speedComponent->setSpeedY(0);
	  speedComponent->setSpeedX(0);
	  if (basicEnemyComponent->getTileGoingToY() > positionComponent->getY())
	    speedComponent->setSpeedY(50);
	  else if (basicEnemyComponent->getTileGoingToY() < positionComponent->getY())
	    speedComponent->setSpeedY(- 50);
	  else if (basicEnemyComponent->getTileGoingToX() > positionComponent->getX())
	    speedComponent->setSpeedX(50);
	  else if (basicEnemyComponent->getTileGoingToX() < positionComponent->getX())
	    speedComponent->setSpeedX(- 50);
	}
    }
}
