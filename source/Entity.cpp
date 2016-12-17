//
// Bomberman
//

#include "Entity.hh"

Entity::Entity(const unsigned int &id)
  : _id(id)
{}

Entity::~Entity()
{}

const unsigned int		&Entity::getId() const
{
  return (this->_id);
}

void				Entity::addComponent(Component *component)
{
  this->_components.push_back(component);
}

void				Entity::removeComponent(Component::ComponentType type)
{
  for (std::vector<Component*>::iterator it = this->_components.begin();
       it != this->_components.end();
       it++)
    {
      if ((*it)->getType() == type)
	{
	  this->_components.erase(it);
	  break;
	}
    }
}

Component			*Entity::getComponent(Component::ComponentType type)
{
  for (Component *component: this->_components)
    {
      if (component->getType() == type)
	return (component);
    }
  return (NULL);
}

const std::vector<Component*>	&Entity::getComponents() const
{
  return (this->_components);
}
