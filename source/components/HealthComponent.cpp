//
// Bomberman
//

#include "HealthComponent.hh"

HealthComponent::HealthComponent(const unsigned int &lives)
  : Component(Component::HEALTH_COMPONENT),
    _lives(lives),
    _invicibleTimer(0)
{}

const unsigned int		&HealthComponent::getLives() const
{
  return (this->_lives);
}

const unsigned int		&HealthComponent::getInvincibleTimer() const
{
  return (this->_invicibleTimer);
}

void				HealthComponent::setLives(const unsigned int &lives)
{
  this->_lives = lives;
}

void				HealthComponent::setInviciblesTimer(const unsigned int &invicibleTimer)
{
  this->_invicibleTimer = invicibleTimer;
}
