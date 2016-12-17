//
// Bomberman
//

#ifndef _ENTITY_MANAGER_HH_
# define _ENTITY_MANAGER_HH_

# include <initializer_list>
# include <vector>
# include <fstream>
# include <iostream>
# include <sstream>
# include <string>
# include <stdexcept>
# include "Entity.hh"
# include "Display.hh"
# include "components/Component.hh"
# include "components/PositionComponent.hh"
# include "components/SpeedComponent.hh"
# include "components/ModelComponent.hh"
# include "components/HealthComponent.hh"
# include "components/ExplosiveComponent.hh"
# include "components/ExplosionComponent.hh"
# include "components/PowerUpComponent.hh"
# include "components/PlayerInputComponent.hh"

class				EntityManager
{
public:
  EntityManager();
  ~EntityManager();
  void				addEntity(Entity *entity);
  void				destroyEntity(const unsigned int &id);
  Entity			*getEntity(const unsigned int id);
  const std::vector<Entity*>	&getEntities();
  std::vector<Entity*>		*getEntitiesWithComponents(std::vector<Component::ComponentType> typeList);
  void				serialize(const std::string &fileName) const;
  bool				unserialize(const std::string &fileName,
					    Display *display);
  void				setDisplay(Display *display);
private:
  std::string			_intToString(int value) const;
  int				_stringToInt(const std::string &str) const;
  void				_serializeEntityComponents(std::string &out, Entity *entity) const;
  void				_serializeEntityComponent(std::string &out, Component *entity) const;
  void				_serializePositionComponent(std::string &out, PositionComponent *component) const;
  void				_serializeSpeedComponent(std::string &out, SpeedComponent *component) const;
  void				_serializeModelComponent(std::string &out, ModelComponent *component) const;
  void				_serializeHealthComponent(std::string &out, HealthComponent *component) const;
  void				_serializeExplosiveComponent(std::string &out, ExplosiveComponent *component) const;
  void				_serializeExplosionComponent(std::string &out, ExplosionComponent *component) const;
  void				_serializePowerUpComponent(std::string &out, PowerUpComponent *component) const;
  void				_serializePlayerInputComponent(std::string &out, PlayerInputComponent *component) const;
  Entity			*_addUnserializedEntity(std::vector<Entity *> &entities, const unsigned int &entityId) const;
  void				_addUnserializedComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializePositionComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeSpeedComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeModelComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeHealthComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeExplosiveComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializeExplosionComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializePowerUpComponent(Entity &entity, const std::string &componentString) const;
  void				_unserializePlayerInputComponent(Entity &entity, const std::string &componentString) const;
  std::vector<Entity*>		_entities;
  Display			*_display;
};

#endif /* !_ENTITY_MANAGER_HH_ */
