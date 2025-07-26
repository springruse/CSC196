#pragma once
#include <vector>
#include <memory>
#include "Actor.h"


namespace piMath {
	class Actor;
	class Scene {
	public:
		Scene() = default;
		
		void Update(float dt);
		void Draw(class Renderer& renderer);

		void AddActor(std::shared_ptr<class Actor> actor);

		Actor* GetActorByName(const std::string& name);

	private:
		std::vector<std::shared_ptr<class Actor>> m_actors;

	};
}