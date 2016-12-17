//
// Bomberman
//

#include "Component.hh"

#ifndef _HEALTH_COMPONENT_HH_
# define _HEALTH_COMPONENT_HH_

class				HealthComponent : public Component
{
public:
  HealthComponent(const unsigned int &lives);
  const unsigned int		&getLives() const;
  void				setLives(const unsigned int &lives);
  const unsigned int		&getInvincibleTimer() const;
  void				setInviciblesTimer(const unsigned int &invicibleTimer);

private:
  unsigned int			_lives;
  unsigned int			_invicibleTimer;
};

#endif /* !_HEALTH_COMPONENT_HH_ */
