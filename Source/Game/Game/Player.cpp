#include "Player.h"
#include "Engine.h"
#include "Input/InputSystem.h"

void Player::Update(float dt)
{
    float speed = 175;
    piMath::vec2 direction{ 0,0 };

    float rotate = 0;
	float rotationSpeed = 180.0f; // degrees per second
	// rotation speed
    if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A))  rotate =  -1; /*time.GetDeltaTime(); };*/
    if(piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D))  rotate = +1; /*time.GetDeltaTime(); };*/

	m_transform.rotation += (rotate * rotationSpeed) * dt;

    // direction speed
    //if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_W))  direction.y -= 100; /*time.GetDeltaTime(); };*/
    //if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_A))  direction.x -= 100; /*time.GetDeltaTime(); };*/
    //if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_S))  direction.y += 100; /*time.GetDeltaTime(); };*/
    //if (piMath::GetEngine().GetInput().getKeyDown(SDL_SCANCODE_D))  direction.x += 100; /*time.GetDeltaTime(); };*/

    if (direction.LengthSqr() > 0) {
        direction = direction.Normalize();
        m_transform.position += (direction + speed) * dt;

       /* for (auto actor : actors) {
            actor.GetTransform().position += (direction * speed * piMath::GetEngine().GetTime().GetDeltaTime());
        }*/


    }
}
