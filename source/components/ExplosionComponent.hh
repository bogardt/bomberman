//
// Bomberman
//

#ifndef EXPLOSION_COMPONENT_HH_
# define EXPLOSION_COMPONENT_HH_

# include "Component.hh"

class			ExplosionComponent : public Component
{
public:
  ExplosionComponent(const unsigned int &explosionDuration);
  const unsigned int	&getExplosionDuration();
  void			setExplosionDuration(const unsigned int &newExplosionDuration);
private:
  unsigned int		_explosionDuration;
};

# endif /* !EXPLOSION_COMPONENT_HH_ */
