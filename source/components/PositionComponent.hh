//
// Bomberman
//

#ifndef _POSITION_COMPONENT_HH_
# define _POSITION_COMPONENT_HH_

# include <string>
# include "Component.hh"

class				PositionComponent : public Component
{
public:
  PositionComponent();
  PositionComponent(const unsigned int &x, const unsigned int &y, const unsigned int rotation);
  ~PositionComponent();
  void				setX(const unsigned int &x);
  void				setY(const unsigned int &y);
  void				setRotation(const unsigned int &rotation);
  const unsigned int			&getX() const;
  const unsigned int			&getY() const;
  const unsigned int			&getRotation() const;
private:
  unsigned int				_x;
  unsigned int				_y;
  unsigned int				_rotation;
};

#endif /* !POSITION_COMPONENT */
