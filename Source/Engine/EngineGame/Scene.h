#pragma once
#include <vector>
#include <memory>


namespace piMath {
	class Scene {
	public:
		Scene() = default;
		
		void Update(float dt);
		void Draw(class Renderer& renderer);

		void addActor(std::shared_ptr<class Actor> actor);

	private:
		std::vector<std::shared_ptr<class Actor>> m_actors;

	};
}