//
// Bomberman
//

#include "BasicEnemyComponent.hh"

BasicEnemyComponent::BasicEnemyComponent(const unsigned int &x, const unsigned int &y)
  :   Component(Component::BASIC_ENEMY_COMPONENT),
      _tileGoingToX(x),
      _tileGoingToY(y),
      _tileComingFromX(x),
      _tileComingFromY(y)
{}

const unsigned int	BasicEnemyComponent::getTileGoingToX() const
{
  return (this->_tileGoingToX);
}

const unsigned int	BasicEnemyComponent::getTileGoingToY() const
{
  return (this->_tileGoingToY);
}

const unsigned int	BasicEnemyComponent::getTileComingFromX() const
{
  return (this->_tileComingFromX);
}

const unsigned int	BasicEnemyComponent::getTileComingFromY() const
{
  return (this->_tileComingFromY);
}

void			BasicEnemyComponent::setTileGoingToX(const unsigned int &x)
{
  this->_tileGoingToX = x;
}

void			BasicEnemyComponent::setTileGoingToY(const unsigned int &y)
{
  this->_tileGoingToY = y;
}

void			BasicEnemyComponent::setTileComingFromX(const unsigned int &x)
{
  this->_tileComingFromX = x;
}

void			BasicEnemyComponent::setTileComingFromY(const unsigned int &y)
{
  this->_tileComingFromY = y;
}
