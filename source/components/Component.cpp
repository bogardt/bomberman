//
// Bomberman
//

#include "Component.hh"

Component::Component(Component::ComponentType type)
  : _type(type)
{}

Component::~Component()
{}

const Component::ComponentType		&Component::getType() const
{
  return (this->_type);
}
