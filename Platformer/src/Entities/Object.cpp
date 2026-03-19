#include "Object.h"
#include "EntityManager.h"

Object::Object()
{
	EntityManager::InitializeObject(this);
}
