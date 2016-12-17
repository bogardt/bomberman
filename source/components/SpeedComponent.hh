//
// Bomberman
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
