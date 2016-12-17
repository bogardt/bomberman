//
// Bomberman
//

#include "SpeedComponent.hh"

SpeedComponent::SpeedComponent()
  : Component(Component::SPEED_COMPONENT)
{}

SpeedComponent::SpeedComponent(const int &speedX, const int &speedY, const double &rotation)
  : Component(Component::SPEED_COMPONENT), _speedX(speedX), _speedY(speedY)
{}

SpeedComponent::~SpeedComponent()
{}

void				SpeedComponent::setSpeedX(const int &speedX)
{
  this->_speedX = speedX;
}

void				SpeedComponent::setSpeedY(const int &speedY)
{
  this->_speedY = speedY;
}

const int			&SpeedComponent::getSpeedX() const
{
  return (this->_speedX);
}

const int			&SpeedComponent::getSpeedY() const
{
  return (this->_speedY);
}
