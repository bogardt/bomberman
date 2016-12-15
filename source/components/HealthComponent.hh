//
// DestructibleComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source/components
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 17:07:02 2016 Barthelemy Gouby
// Last update Wed May 25 16:25:11 2016 Barthelemy Gouby
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
