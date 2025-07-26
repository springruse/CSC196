#pragma once
#include "EngineGame/Actor.h"


class Player : public piMath::Actor {
	
public:
	Player() = default;
	Player(const piMath::Transform& transform, std::shared_ptr<piMath::Model> model) :
	
		Actor{transform, model}

	{} 

	void Update(float dt) override;

	float speed = 175;
	float rotationSpeed = 180.0f;
	float damping = 0.98f; // Damping factor to reduce velocity over time

private:
};