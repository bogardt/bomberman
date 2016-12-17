//
// Bomberman
//

#ifndef _BASIC_ENEMY_COMPONENT_HH_
# define _BASIC_ENEMY_COMPONENT_HH_

# include "Component.hh"

class			BasicEnemyComponent : public Component
{
public:
  BasicEnemyComponent(const unsigned int &x, const unsigned int &y);

  const unsigned int	getTileGoingToX() const;
  const unsigned int	getTileGoingToY() const;
  const unsigned int	getTileComingFromX() const;
  const unsigned int	getTileComingFromY() const;
  void			setTileGoingToX(const unsigned int &x);
  void			setTileGoingToY(const unsigned int &y);
  void			setTileComingFromX(const unsigned int &x);
  void			setTileComingFromY(const unsigned int &y);

private:
  unsigned int		_tileGoingToX;
  unsigned int		_tileGoingToY;
  unsigned int		_tileComingFromX;
  unsigned int		_tileComingFromY;
};

#endif /* !_BASIC_ENEMY_COMPONENT_HH_ */
