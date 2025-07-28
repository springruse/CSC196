//#include "Rocket.h"
//#include <vector>
////unfinished but is similar to enemy.cpp
//
//void Rocket::Update(float deltaTime)
//{
//	float speed = 10.0f;
//
//
//	if (player) {
//		direction = player->m_transform.position - m_transform.position;
//		direction = direction.Normalize();
//		m_transform.rotation = piMath::Math::radToDeg(direction.Angle());
//	}
//
//	piMath::vec2 force = direction.Rotate(m_transform.rotation) * speed * deltaTime;
//	velocity += force;
//
//	Actor::Update(deltaTime);
//
//	//m_transform.position.x = piMath::Math::wrap(m_transform.position.x, 0.0f, 0.0f);
//	//m_transform.position.y = piMath::Math::wrap(m_transform.position.y, 0.0f, 1024.0f);
//}
