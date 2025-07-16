#pragma once
#include "../Math/Transform.h"
#include "../Renderer/Model.h"


namespace piMath {
	class Actor {
	public:
		Actor() = default;
		Actor(const Transform& transform, class Model* model) :
			m_transform{ transform },
			m_model{ model }
		{};

		virtual void Update(float deltaTime);
		virtual void Draw(class Renderer& renderer);

		Transform GetTransform(){
			return m_transform;
		}
		void SetTransform(const Transform& transform) {
			m_transform = transform;
		}

	protected:
		Transform m_transform;
		Model* m_model;
	};
}