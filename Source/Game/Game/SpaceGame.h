#pragma once
#include "EngineGame/Game.h"

class SpaceGame : piMath::Game {

	public:
		enum class GameState {
			Init,
			Title,
			StartGame,
			Game,
			PlayerDead,
			GameOver,
			StartRound, // New state for starting a round
		};

	public:
		SpaceGame() = default;

		bool Initialize() override;
		void Shutdown() override;

		void Update(float dt) override;
		void Draw() override;

		int m_score = 0; // Player's score
		int m_lives = 0; // Player's lives

	private:
		GameState m_gameState = GameState::Init;
		float m_enemySpawnTimer = 0.0f; // Timer for enemy spawning
};