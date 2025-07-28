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
#include "Input/InputSystem.h"
#include "GameData.h"
#include "Enemy.h"
#include "Engine.h"
#include "Player.h"


bool SpaceGame::Initialize()
{
 
	m_scene = std::make_unique<piMath::Scene>();
    

    std::shared_ptr<piMath::Model> newModel = std::make_shared<piMath::Model>(GameData::squarePoint, piMath::vec3{ 0,0,1 });
	std::shared_ptr<piMath::Model> playerModel = std::make_shared<piMath::Model>(GameData::playerShipPoints, piMath::vec3{ 0,1,0 });
    std::shared_ptr<piMath::Model> EnemyModel = std::make_shared<piMath::Model>(GameData::enemyShipPoints, piMath::vec3{ 1,0,0 });

    std::vector<piMath::Actor> actors;

    piMath::Transform playerTransform{ piMath::vec2{piMath::GetEngine().GetRenderer().getWidth() * 0.5f, piMath::GetEngine().GetRenderer().getHeight() * 0.5f}, 0.0f, 10.0f};
    std::shared_ptr<Player> player = std::make_unique<Player>(playerTransform, playerModel);

	player->speed = 20.0f; // Set player speed
	player->rotationSpeed = 180.0f; // Set player rotation speed
	player->damping = 0.98f; // Set player damping
    player->tag = "player"; // Set player name for identification
	player->name = "player"; // Set player name for identification

	m_scene->AddActor(player); // add the player

	for (int i = 0; i < 10; i++) { // make enemies
        piMath::Transform transform{ piMath::vec2{ piMath::Random::getRandomFloat() * piMath::GetEngine().GetRenderer().getHeight(), piMath::Random::getRandomFloat() * piMath::GetEngine().GetRenderer().getHeight() }, 0, 10};
        std::unique_ptr<Enemy> enemy = std::make_unique<Enemy>(transform, EnemyModel);
        enemy->damping = 0.98f;
		enemy->speed = piMath::Random::getRandomFloat() * 10.0f + 1.0f; // Random speed between 100 and 7000
        enemy->tag = "enemy"; // Set enemy name for identification
		enemy->name = "enemy"; // Set enemy name for identification
        m_scene->AddActor(std::move(enemy));
    }

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
    //
}

void SpaceGame::Update(float dt)
{
    switch (m_gameState)
    {
        case GameState::Init:
			m_gameState = GameState::Title; // Transition to Title state
            break;
        case GameState::Title:
            if (piMath::GetEngine().GetInput().getKeyPressed(SDL_SCANCODE_SPACE)) {
				m_gameState = GameState::StartGame; // Transition to StartGame state
            }
            break;
        case GameState::StartGame:
            m_score = 0;
            m_lives = 3;
			m_gameState = GameState::StartRound; // Transition to StartRound state
            break;
        case GameState::Game:
			m_enemySpawnTimer -= dt;
            if (m_enemySpawnTimer <= 0.0f) {
				m_enemySpawnTimer = 3.0f; // Reset the timer
            }
            break;
        case GameState::PlayerDead:
            m_lives--;
            if (m_lives == 0) m_gameState = GameState::GameOver;
            else{
                m_gameState = GameState::StartRound; // Transition to StartRound state
			}
            break;
        case GameState::GameOver:
            
            break;

	}
	m_scene->Update(piMath::GetEngine().GetTime().GetDeltaTime());
}

void SpaceGame::Draw()
{
    m_scene->Draw(piMath::GetEngine().GetRenderer());
}


