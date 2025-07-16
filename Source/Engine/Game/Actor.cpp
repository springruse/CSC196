#include "Actor.h"
#include "../Renderer/Renderer.h"
namespace piMath {

	void piMath::Actor::Update(float deltaTime)
	{

	}

	void piMath::Actor::Draw(Renderer& renderer)
	{
		m_model->Draw(renderer, m_transform);
	}
}

