#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"

void Player::Update(float dt)
{
    
    piMath::vec2 direction{ 1,0 };

    float rotate = 0;
	
	// rotation speed
    if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A))  rotate =  -1; 
    if(piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D))  rotate = +1; 

	m_transform.rotation += (rotate * rotationSpeed) * dt;

	//thrust speed
    float thrust = 0;
	if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W))  thrust = +1;
	if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_S))  thrust = -1;

	piMath::vec2 force = direction.Rotate(m_transform.rotation) * thrust * speed * dt;
	velocity += force;
	
	Actor::Update(dt);

}
