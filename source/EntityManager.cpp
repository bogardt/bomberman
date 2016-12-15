//
// EntityManager.cpp for indie studio in /home/barthe_g/rendu/tek2/c++/cpp_indie_studio/source
//
// Made by Barthelemy Gouby
// Login   <barthe_g@epitech.net>
//
// Started on  Mon May  2 14:13:17 2016 Barthelemy Gouby
// Last update Sun Jun  5 19:27:40 2016 Barthelemy Gouby
//

#include "EntityManager.hh"

EntityManager::EntityManager() : _display(NULL)
{}

EntityManager::~EntityManager()
{}

void							EntityManager::addEntity(Entity *entity)
{
  this->_entities.push_back(entity);
}

void							EntityManager::setDisplay(Display *display)
{
  this->_display = display;
}

void							EntityManager::destroyEntity(const unsigned int &id)
{
  for (std::vector<Entity*>::iterator it = this->_entities.begin(); it != this->_entities.end(); it++)
    {
      if ((*it)->getId() == id)
	{
	  it = this->_entities.erase(it);
	  break;
	}
    }
}

Entity							*EntityManager::getEntity(const unsigned int id)
{
  for (std::vector<Entity*>::iterator it = this->_entities.begin(); it != this->_entities.end(); it++)
    {
      if ((*it)->getId() == id)
	return (*it);
    }
  return (NULL);
}

const std::vector<Entity*>				&EntityManager::getEntities()
{
  return (this->_entities);
}

std::vector<Entity*>					*EntityManager::getEntitiesWithComponents(std::vector<Component::ComponentType> typeList)
{
  std::vector<Entity*>					*validEntities = new std::vector<Entity*>;
  bool							isValid;

  for (Entity *entity: this->_entities)
    {
      isValid = true;
      for (Component::ComponentType type: typeList)
	{
	  if (!entity->getComponent(type))
	    isValid = false;
	}
      if (isValid)
	validEntities->push_back(entity);
    }
  return (validEntities);
}

void							EntityManager::_serializePositionComponent(std::string &out, PositionComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getX()) + ",";
  out += this->_intToString(component->getY()) + ",";
  out += this->_intToString(component->getRotation());
}

void							EntityManager::_serializeSpeedComponent(std::string &out, SpeedComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getSpeedX()) + ",";
  out += this->_intToString(component->getSpeedY());
}

void							EntityManager::_serializeModelComponent(std::string &out, ModelComponent *component) const
{
  std::vector<std::string>				models = component->getModels();
  std::vector<std::string>::const_iterator		it = models.begin();

  out += ':';
  out += this->_intToString(models.size()) + ',';
  while (it != models.end())
    {
      out += *it + ',';
      ++it;
    }
  out += component->getTexture() + ',';
  out += this->_intToString(component->getScale()) + ',';
  out += this->_intToString(component->getSelectedModel());
}

void							EntityManager::_serializeHealthComponent(std::string &out, HealthComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getLives()) + ',';
  out += this->_intToString(component->getInvincibleTimer());
}

void							EntityManager::_serializeExplosiveComponent(std::string &out, ExplosiveComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getTimerLength()) + ',';
  out += this->_intToString(component->getExplosionSize()) + ',';
  out += this->_intToString(component->getOwnerId()) + ',';
  out += this->_intToString(component->getOwnerType());
}

void							EntityManager::_serializeExplosionComponent(std::string &out, ExplosionComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getExplosionDuration());
}

void							EntityManager::_serializePowerUpComponent(std::string &out, PowerUpComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getType());
}

void							EntityManager::_serializePlayerInputComponent(std::string &out, PlayerInputComponent *component) const
{
  out += ':';
  out += this->_intToString(component->getKeyUp()) + ',';
  out += this->_intToString(component->getKeyDown()) + ',';
  out += this->_intToString(component->getKeyLeft()) + ',';
  out += this->_intToString(component->getKeyRight()) + ',';
  out += this->_intToString(component->getKeyBomb()) + ',';
  out += this->_intToString(component->getMaxBombs()) + ',';
  out += this->_intToString(component->getActiveBombs()) + ',';
  out += this->_intToString(component->getExplosionSize()) + ',';
  out += this->_intToString(component->getSpeed());
}

void							EntityManager::_serializeEntityComponent(std::string &out, Component *component) const
{
  switch(component->getType())
    {
    case Component::POSITION_COMPONENT:
      this->_serializePositionComponent(out, (PositionComponent *)component);
      break;
    case Component::SPEED_COMPONENT:
      this->_serializeSpeedComponent(out, (SpeedComponent *)component);
      break;
    case Component::MODEL_COMPONENT:
      this->_serializeModelComponent(out, (ModelComponent *)component);
      break;
    case Component::HEALTH_COMPONENT:
      this->_serializeHealthComponent(out, (HealthComponent *)component);
      break;
    case Component::EXPLOSIVE_COMPONENT:
      this->_serializeExplosiveComponent(out, (ExplosiveComponent *)component);
      break;
    case Component::EXPLOSION_COMPONENT:
      this->_serializeExplosionComponent(out, (ExplosionComponent *)component);
      break;
    case Component::POWER_UP_COMPONENT:
      this->_serializePowerUpComponent(out, (PowerUpComponent *)component);
      break;
    case Component::PLAYER_INPUT_COMPONENT:
      this->_serializePlayerInputComponent(out, (PlayerInputComponent *)component);
      break;
    }
}

void							EntityManager::_serializeEntityComponents(std::string &out, Entity *entity) const
{
  std::vector<Component *>				components;
  std::vector<Component *>::const_iterator		it;
  Component						*component;

  components = entity->getComponents();
  it = components.begin();
  while (it != components.end())
    {
      component = *it;
      out += '{';
      out += this->_intToString(component->getType());
      this->_serializeEntityComponent(out, component);
      out += '}';
      if ((it + 1) != components.end())
	out += ',';
      ++it;
    }
}

void							EntityManager::serialize(const std::string &fileName) const
{
  std::ofstream						fs;
  std::vector<Entity *>::const_iterator			it;
  std::string						out;
  Entity						*entity;

  std::cout << "maybe" << std::endl;
  fs.open(fileName, std::fstream::in | std::fstream::out | std::fstream::trunc);
  std::cout << "serializing" << std::endl;
  if (fs.is_open())
    {
      it = this->_entities.begin();
      while (it != this->_entities.end())
	{
	  entity = *it;
	  out += this->_intToString(entity->getId());
	  out += '|';
	  this->_serializeEntityComponents(out, entity);
	  out += '\n';
	  ++it;
	}
      fs << out;
      fs.close();
      std::cout << "[+] Game Saved to file " << fileName << std::endl;
    }
  else
    std::cout << "[-] Can't serialize to file " << fileName << std::endl;
}

Entity							*EntityManager::_addUnserializedEntity(std::vector<Entity *> &entities, const unsigned int &entityId) const
{
  Entity						*newEntity = new Entity(entityId);

  entities.push_back(newEntity);
  return (newEntity);
}

void							EntityManager::_unserializePositionComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  PositionComponent					*newComponent = new PositionComponent();

  newComponent->setX(this->_stringToInt(workingString));
  workingString = workingString.substr(workingString.find(',') + 1);
  newComponent->setY(this->_stringToInt(workingString));
  workingString = workingString.substr(workingString.find(',') + 1);
  newComponent->setRotation(this->_stringToInt(workingString));
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializeSpeedComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  SpeedComponent					*newComponent = new SpeedComponent();

  newComponent->setSpeedX(this->_stringToInt(workingString));
  workingString = workingString.substr(workingString.find(',') + 1);
  newComponent->setSpeedY(this->_stringToInt(workingString));
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializeModelComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  ModelComponent					*newComponent = new ModelComponent();
  unsigned int						modelsSize = this->_stringToInt(componentString);
  unsigned int						i = 0;
  std::vector<std::string>				models;
  std::string						texture;
  unsigned int						scale;
  ModelComponent::ModelType				selectedModel;

  workingString = workingString.substr(workingString.find(',') + 1);
  while (i < modelsSize)
    {
      if (0 == workingString.find(','))
	models.push_back("");
      else
	models.push_back(workingString.substr(0, workingString.find(',')));
      workingString = workingString.substr(workingString.find(',') + 1);
      ++i;
    }
  texture = workingString.substr(0, workingString.find(','));
  workingString = workingString.substr(workingString.find(',') + 1);
  scale = this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  selectedModel = (ModelComponent::ModelType)this->_stringToInt(workingString);
  newComponent->setModels(models);
  newComponent->setTexture(texture);
  newComponent->setScale(scale);
  newComponent->setSelectedModel(selectedModel);
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializeHealthComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  unsigned int						lives;
  unsigned int					        invicibleTimer;
  HealthComponent					*newComponent;

  lives = this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  invicibleTimer = this->_stringToInt(workingString);
  newComponent = new HealthComponent(lives);
  newComponent->setInviciblesTimer(invicibleTimer);
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializeExplosiveComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  ExplosiveComponent					*newComponent;
  unsigned int						timerLength;
  unsigned int					        explosionSize;
  unsigned int					        ownerId;
  ExplosiveComponent::Owner				ownerType;

  timerLength = this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  explosionSize = this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  ownerId = this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  ownerType = (ExplosiveComponent::Owner)this->_stringToInt(workingString);
  workingString = workingString.substr(workingString.find(',') + 1);
  newComponent = new ExplosiveComponent(timerLength, explosionSize, ownerId, ownerType);
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializeExplosionComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  ExplosionComponent					*newComponent;
  unsigned int						explosionDuration;

  explosionDuration = this->_stringToInt(workingString);
  newComponent = new ExplosionComponent(explosionDuration);
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializePowerUpComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  PowerUpComponent					*newComponent;
  PowerUpComponent::Type				type;

  type = (PowerUpComponent::Type)this->_stringToInt(workingString);
  newComponent = new PowerUpComponent(type);
  entity.addComponent(newComponent);
}

void							EntityManager::_unserializePlayerInputComponent(Entity &entity, const std::string &componentString) const
{
  std::string						workingString = componentString.substr(componentString.find(":") + 1);
  PlayerInputComponent					*newComponent;
  irr::EKEY_CODE					keyUp;
  irr::EKEY_CODE					keyDown;
  irr::EKEY_CODE					keyLeft;
  irr::EKEY_CODE					keyRight;
  irr::EKEY_CODE					keyBomb;
  unsigned int						maxBombs;
  unsigned int					        explosionSize;
  unsigned int					        speed;

  keyUp = (irr::EKEY_CODE)this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  keyDown = (irr::EKEY_CODE)this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  keyLeft = (irr::EKEY_CODE)this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  keyRight = (irr::EKEY_CODE)this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  keyBomb = (irr::EKEY_CODE)this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  maxBombs = this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  explosionSize = this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  speed = this->_stringToInt(workingString);workingString = workingString.substr(workingString.find(',') + 1);
  if (this->_display)
    this->_display->createEventListener(entity.getId(), {keyUp, keyDown, keyRight, keyLeft, keyBomb});
  newComponent = new PlayerInputComponent(keyUp, keyDown, keyLeft, keyRight, keyBomb, maxBombs, explosionSize, speed);
  entity.addComponent(newComponent);
}

void							EntityManager::_addUnserializedComponent(Entity &entity, const std::string &componentString) const
{
  Component::ComponentType				componentId;

  componentId = (Component::ComponentType)this->_stringToInt(componentString);
  switch(componentId)
    {
    case Component::POSITION_COMPONENT:
      this->_unserializePositionComponent(entity, componentString);
      break;
    case Component::SPEED_COMPONENT:
      this->_unserializeSpeedComponent(entity, componentString);
      break;
    case Component::MODEL_COMPONENT:
      this->_unserializeModelComponent(entity, componentString);
      break;
    case Component::HEALTH_COMPONENT:
      this->_unserializeHealthComponent(entity, componentString);
      break;
    case Component::EXPLOSIVE_COMPONENT:
      this->_unserializeExplosiveComponent(entity, componentString);
      break;
    case Component::EXPLOSION_COMPONENT:
      this->_unserializeExplosionComponent(entity, componentString);
      break;
    case Component::POWER_UP_COMPONENT:
      this->_unserializePowerUpComponent(entity, componentString);
      break;
    case Component::PLAYER_INPUT_COMPONENT:
      this->_unserializePlayerInputComponent(entity, componentString);
      break;
    }
}

bool							EntityManager::unserialize(const std::string &fileName,
										   Display *display)
{
  std::ifstream						fs;
  std::string						entityString;
  std::string						componentString;
  unsigned int						entityId;
  unsigned						first;
  unsigned					        last;
  std::vector<Entity*>					newEntities;
  Entity						*lastEntity;

  this->_display = display;
  fs.open(fileName, std::fstream::in);
  if (fs.is_open())
    {
      while (std::getline(fs, entityString))
	{
	  entityId = this->_stringToInt(entityString.substr(0, entityString.find("|")));
	  lastEntity = _addUnserializedEntity(newEntities, entityId);
	  while (entityString != "")
	    {
	      first = entityString.find("{") + 1;
	      last = entityString.find("}");
	      componentString = entityString.substr(first, last - first);
	      this->_addUnserializedComponent(*lastEntity, componentString);
	      entityString = entityString.substr(entityString.find("}") + 1);
	    }
	  this->_display->createModel(lastEntity);
	}
      this->_entities = newEntities;
      fs.close();
      return (true);
    }
  else
    std::cout << "[-] Can't unserialize file " << fileName << std::endl;
  return (false);
}

std::string						EntityManager::_intToString(const int value) const
{
  std::stringstream					str;

  str << value;
  return (str.str());
}

int							EntityManager::_stringToInt(const std::string &str) const
{
  int							result;

  try
    {
      result = std::stoi(str, nullptr, 10);
    }
  catch(std::out_of_range &e)
    {
      result = 0;
    }
  return (result);
}
