//
// SpeedComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 14:22:56 2016 Barthelemy Gouby
// Last update Wed May 25 12:01:45 2016 Barthelemy Gouby
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
