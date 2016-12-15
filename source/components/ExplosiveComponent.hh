//
// ExplosiveComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May 23 11:18:50 2016 Barthelemy Gouby
// Last update Thu May 26 13:12:17 2016 Erwan Dupard
//

#ifndef _EXPLOSIVE_COMPONENT_HH_
# define _EXPLOSIVE_COMPONENT_HH_

# include "Component.hh"

class					ExplosiveComponent : public Component
{
public:
  enum Owner : unsigned int
    {
      PLAYER = 0
    };

  ExplosiveComponent(const unsigned int &timerLength,
		     const unsigned int &explosionSize,
		     const unsigned int &ownerId,
		     ExplosiveComponent::Owner ownerType);

  const unsigned int			&getTimerLength() const;
  const unsigned int			&getExplosionSize() const;
  const unsigned int			&getOwnerId() const;
  const ExplosiveComponent::Owner	&getOwnerType() const;
  void					setTimerLength(const unsigned int &newLength);
private:
  unsigned int				_timerLength;
  unsigned int				_explosionSize;
  unsigned int				_ownerId;
  Owner					_ownerType;
};

#endif /* !_EXPLOSIVE_COMPONENT_HH_ */
