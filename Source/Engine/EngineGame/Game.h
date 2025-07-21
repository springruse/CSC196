#pragma once
#include <memory>

namespace piMath {
	class Game {
	public:
		Game() = default;

		virtual bool Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;
	protected:
		std::unique_ptr<class Scene> m_scene;
	};
}