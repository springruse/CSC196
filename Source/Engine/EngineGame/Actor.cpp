#include "Actor.h"
#include "../Renderer/Renderer.h"
#include "../Renderer/Model.h"
#include "Scene.h"
namespace piMath {

	void piMath::Actor::Update(float deltaTime)
	{
		m_transform.position += velocity * deltaTime;
		velocity *= (1.0f * damping);
	}

	void piMath::Actor::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_transform);
	}
	inline void piMath::Scene::AddActor(std::shared_ptr<class Actor> actor) {
		m_actors.push_back(actor);
	}

}

