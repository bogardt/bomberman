//
// ExplosionComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 12:23:26 2016 Barthelemy Gouby
// Last update Mon May 23 12:33:11 2016 Barthelemy Gouby
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
