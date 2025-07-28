#pragma once
#include "EngineGame/Actor.h"
#include "EngineGame/Scene.h"

class Enemy : public piMath::Actor {
public:
	Enemy() = default;
	Enemy(const piMath::Transform& transform, std::shared_ptr<class piMath::Model> model) :
		piMath::Actor{ transform, model }
	{}

	void Update(float deltaTime) override;
	float damping = 0.98f;
	float speed = 100;
	piMath::vec2 direction = { 0,0 };
private:

};