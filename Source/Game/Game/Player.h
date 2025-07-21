#pragma once
#include "EngineGame/Actor.h"


class Player : public piMath::Actor {
	
public:
	Player() = default;
	Player(const piMath::Transform& transform, std::shared_ptr<piMath::Model> model) :
	
		Actor{transform, model}

	{} 

	void Update(float dt) override;

private:
};