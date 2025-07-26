#include "Enemy.h"
#include "Engine.h"
#include "EngineGame/Scene.h"
#include "Renderer/Renderer.h"
#include <EngineGame/Game.h>

void Enemy::Update(float deltaTime)
{
	float speed = 10.0f;

	Actor* player = m_scene->GetActorByName("player");

	if (player) {
		direction = player -> m_transform.position - m_transform.position;
		direction = direction.Normalize();
		m_transform.rotation = piMath::Math::radToDeg(direction.Angle());
	}

	piMath::vec2 force = direction.Rotate(m_transform.rotation) * speed * deltaTime;
	velocity += force;

	Actor::Update(deltaTime);

	//m_transform.position.x = piMath::Math::wrap(m_transform.position.x, 0.0f, 0.0f);
	//m_transform.position.y = piMath::Math::wrap(m_transform.position.y, 0.0f, 1024.0f);
}
