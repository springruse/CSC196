#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "Scene.h"
namespace piMath {

	void piMath::Actor::Update(float deltaTime)
	{

	}

	void piMath::Actor::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_transform);
	}
	inline void piMath::Scene::addActor(std::shared_ptr<class Actor> actor) {
		m_actors.push_back(actor);
	}
}

