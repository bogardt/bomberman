//
// SpeedComponent.hh for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
// 
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
// 
// Started on  Mon May  2 14:17:14 2016 Barthelemy Gouby
// Last update Thu May 19 13:30:07 2016 Barthelemy Gouby
//

#ifndef _SPEED_COMPONENT_HH_
# define _SPEED_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				SpeedComponent : public Component
{
public:
  SpeedComponent();
  SpeedComponent(const int &speedX, const int &speedY, const double &rotation);
  ~SpeedComponent();
  void				setSpeedX(const int &speedX);
  void				setSpeedY(const int &speedY);
  const int			&getSpeedX() const;
  const int			&getSpeedY() const;

private:
  int				_speedX;
  int				_speedY;
};

#endif /* !_SPEED_COMPONENT_HH_ */
