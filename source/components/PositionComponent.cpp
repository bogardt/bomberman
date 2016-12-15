//
// PositionComponent.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 16:13:50 2016 Barthelemy Gouby
// Last update Fri May 27 13:46:53 2016 Barthelemy Gouby
//

#include "PositionComponent.hh"

PositionComponent::PositionComponent()
  : Component(Component::POSITION_COMPONENT)
{}

PositionComponent::PositionComponent(const unsigned int &x, const unsigned int &y, const unsigned int rotation)
  : Component(Component::POSITION_COMPONENT),
    _x(x),
    _y(y),
    _rotation(rotation)
{}

PositionComponent::~PositionComponent()
{}

void				PositionComponent::setX(const unsigned int &x)
{
  this->_x = x;
}

void				PositionComponent::setY(const unsigned int &y)
{
  this->_y = y;
}

void				PositionComponent::setRotation(const unsigned int &rotation)
{
  this->_rotation = rotation;
}

const unsigned int			&PositionComponent::getX() const
{
  return (this->_x);
}

const unsigned int			&PositionComponent::getY() const
{
  return (this->_y);
}

const unsigned int			&PositionComponent::getRotation() const
{
  return (this->_rotation);
}
