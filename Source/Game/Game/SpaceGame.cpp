#pragma once

#include "SpaceGame.h"
#include <vector>
#include "EngineGame/Game.h"
#include "EngineGame/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"

class SpaceGame : public piMath::Game {

public: 
	SpaceGame() = default;
	bool Initialize() override;
	void Shutdown() override;
	void Update() override;
	void Draw() override;
};

bool SpaceGame::Initialize()
{
	m_scene = std::make_unique<piMath::Scene>();
    std::vector<piMath::vec2> squarePoint{ // makes a square 
        {-5,-5},
        { 5,-5},
        { 5, 5},
        {-5, 5},
        {-5,-5}
    };
    std::shared_ptr<piMath::Model> newModel = std::make_shared<piMath::Model>(squarePoint, piMath::vec3{ 0,0,1 });
}

void SpaceGame::Shutdown()
{
}

void SpaceGame::Update()
{
}

void SpaceGame::Draw()
{
}


