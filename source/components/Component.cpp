//
// Component.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 13:02:59 2016 Barthelemy Gouby
// Last update Thu May 26 12:37:10 2016 Erwan Dupard
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
