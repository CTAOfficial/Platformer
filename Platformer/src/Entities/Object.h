#pragma once
#include <string>

//..TODO: Move outside Entities folder
class Object {
private:
	int ID = 0;

protected:
	Object();

public:
	friend class EntityManager;
	std::string name = "New Object";

	virtual ~Object() {
		//.. TODO: Destroy as needed in a garbage collector
	}

	int GetID() const {
		return ID;
	}

};