#pragma once

#include "SceneObject.h"
#include "Moveable.h"

class Planet : public SceneObject, public Movable {
private:
    float radius;

    float orbitSpeed;
    float orbitAngle;
    float orbitRadius;

public:
    Planet(float orbitSpeed, float orbitAngle, float orbitRadius);
    ~Planet();

    float getRadius() const;

    void move(float deltaTime) override;
};