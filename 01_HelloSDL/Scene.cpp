#include "Scene.h"

#include <algorithm>

Scene::Scene(uint32_t nrPlanets)
{
	std::vector<SpaceObject*> planets;
	planets.push_back(new Mercury(0, 0));
	planets.push_back(new Venus(0, 1));
	planets.push_back(new Earth(0, 2));
	planets.push_back(new Mars(0, 3));
	planets.push_back(new Jupiter(0, 4));
	planets.push_back(new Saturn(0, 5));
	planets.push_back(new Uranus(0, 6));
	planets.push_back(new Neptune(0, 7));

	if (nrPlanets == 8)
	{
		solarSystem = new SolarSystem(planets);
	}
	else
	{
		std::vector<SpaceObject*> randomPlanets;
		std::vector<bool> usedIndexes(8, true);

		for (int i = 0; i < nrPlanets; i++)
		{
			int randomIndex = rand() % 8;

			if (usedIndexes[randomIndex])
			{
				randomPlanets.push_back(planets[randomIndex]);
				usedIndexes[randomIndex] = false;
			}
			else
			{
				i--;
			}
		}

		solarSystem = new SolarSystem(randomPlanets);
	}
}

Scene::~Scene()
{
	delete solarSystem;
}

void Scene::set_solar_system(SolarSystem* solarSystem)
{
	this->solarSystem = solarSystem;
}

SolarSystem* Scene::get_solar_system()
{
	return solarSystem;
}