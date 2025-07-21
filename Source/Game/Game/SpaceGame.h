#pragma once
#include "EngineGame/Game.h"

class SpaceGame : piMath::Game {
	public:
		SpaceGame() = default;

		bool Initialize() override;
		void Shutdown() override;

		void Update() override;
		void Draw() override;

	private:
};