//
// PowerUpComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Tue May 24 17:17:23 2016 Barthelemy Gouby
// Last update Wed May 25 16:10:17 2016 Barthelemy Gouby
//

#ifndef _POWER_UP_COMPONENT_HH_
# define _POWER_UP_COMPONENT_HH_

# include "Component.hh"

class				PowerUpComponent : public Component
{
public:
  enum Type
    {
      FIRE_UP,
      BOMB_UP,
      SPEED_UP,
      LIVE_UP
    };
  
  PowerUpComponent(PowerUpComponent::Type type);
  const PowerUpComponent::Type	&getType() const;

private:
  PowerUpComponent::Type	_type;
};

#endif /* !_POWER_UP_COMPONENT_HH_ */
