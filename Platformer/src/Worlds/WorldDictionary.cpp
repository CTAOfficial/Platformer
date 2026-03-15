#include "WorldDictionary.h"

template<typename T>
bool WorldDictionary<T>::Define(T definition, Texture* texture)
{
	//if (Definitions.find(definition))

	Definitions.emplace(definition, texture);
	return true;
}

template<typename T>
bool WorldDictionary<T>::Undefine(T definition)
{
	//Definitions.
	return true;
}

template<typename T>
Texture* WorldDictionary<T>::Fetch(T definition)
{
	Texture* def = Definitions.at(definition);
	if (!def) {
		//.. TODO: Log 
		std::cout << "No Definition found for '" + std::to_string(definition) + "'.\n";
		return nullptr;
	}
	
	return def;
}
