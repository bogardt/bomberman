//
// Bomberman
//

#ifndef _ENTITY_HH_
# define _ENTITY_HH_

# include <string>
# include <vector>
# include "components/Component.hh"

class						Entity
{
public:
  Entity(const unsigned int &id);
  ~Entity();
  const unsigned int				&getId() const;
  void						addComponent(Component *component);
  void						removeComponent(Component::ComponentType type);
  Component					*getComponent(Component::ComponentType type);
  const std::vector<Component*>			&getComponents() const;

private:
  const unsigned int				_id;
  std::vector<Component*>			_components;
};

#endif /* !_ENTITY_HH_ */
