#pragma once

#include "SpaceGame.h"
#include <vector>
#include "EngineGame/Game.h"
#include "EngineGame/Scene.h"
#include "Core/Random.h"
#include "Math/Vector2.h"
#include "Renderer/Model.h"
#include "Renderer/Renderer.h"
#include "EngineGame/Actor.h"
#include "Engine.h"
#include "Player.h"


bool SpaceGame::Initialize()
{
    // Color Vector (R, G, B)
    //{ 1.0, 0.0, 0.0 },

    //    // Connected Lines
    //{ 3, 0 },
    //{ -3, -3 },
    //{ -1, 0 },
    //{ -3, 3 },
    //{ 3, 0 },
	m_scene = std::make_unique<piMath::Scene>();
    std::vector<piMath::vec2> squarePoint{ // makes a square 
        {-5,-5},
        { 5,-5},
        { 5, 5},
        {-5, 5},
        {-5,-5}
    };

    std::vector<piMath::vec2> playerShip{ // makes a player ship
        { 3, 0 },
        { -3, -3 },
        { -1, 0 },
        { -3, 3 },
        { 3, 0 },
    };

    std::shared_ptr<piMath::Model> newModel = std::make_shared<piMath::Model>(squarePoint, piMath::vec3{ 0,0,1 });
	std::shared_ptr<piMath::Model> playerModel = std::make_shared<piMath::Model>(playerShip, piMath::vec3{ 0,1,0 });

    std::vector<piMath::Actor> actors;

    piMath::Transform transformSystem{ piMath::vec2{piMath::GetEngine().GetRenderer().getWidth() * 0.5f, piMath::GetEngine().GetRenderer().getHeight() * 0.5f}, 0.0f, 10.0f};
    std::shared_ptr<piMath::Actor> actor = std::make_shared<piMath::Actor>(transformSystem, playerModel);
    std::shared_ptr<Player> player = std::make_unique<Player>(transformSystem, playerModel);
    m_scene->addActor(actor);

    /*for (int i = 0; i < 100; i++) {

        piMath::Transform transformSystem{ piMath::vec2{piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024}, 0.0f, 2.0f };
        std::shared_ptr<piMath::Actor> actor = std::make_shared<piMath::Actor>(transformSystem, newModel);
        std::unique_ptr<Player> player = std::make_unique<Player>(transformSystem, newModel);
        m_scene->addActor(actor);
    }*/
    return true;
}

void SpaceGame::Shutdown()
{
	m_scene->Update(piMath::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Update()
{

}

void SpaceGame::Draw()
{
    m_scene->Draw(piMath::GetEngine().GetRenderer());
}


