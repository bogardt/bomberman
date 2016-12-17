//
// Bomberman
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
