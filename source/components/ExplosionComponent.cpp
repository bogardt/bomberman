//
// Bomberman
//

#include "ExplosionComponent.hh"

ExplosionComponent::ExplosionComponent(const unsigned int &explosionDuration)
  : Component(Component::EXPLOSION_COMPONENT),
    _explosionDuration(explosionDuration)
{}

const unsigned int	&ExplosionComponent::getExplosionDuration()
{
  return (this->_explosionDuration);
}

void			ExplosionComponent::setExplosionDuration(const unsigned int &newExplosionDuration)
{
  this->_explosionDuration = newExplosionDuration;
}
