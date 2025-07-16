#include <Core/Random.h>
#include <Renderer/Renderer.h>
#include <Math/Math.h>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Core/Time.h>
#include <Input/InputSystem.h>
#include <Audio/AudioSystem.h>
#include <Renderer/Model.h>
#include <Game/Actor.h>

//#include <fmod.hpp>
//#include <SDL3/SDL.h>
#include <random>
#include <vector>

#include <iostream>
//int main() {
//
//	// const float degree = piMath::radToDeg(piMath::pi);
//	piMath::Math::min(3, 2);
//	piMath::Math::clamp(5, 1, 10);
//
//	std::cout << NAME << std::endl;
//	std::cout << "Hello, World!" << std::endl;
//	std::cout << "I am writing this to future me!" << std::endl;
//	std::cout << piMath::Math::pi << std::endl;
//
//	for (int i = 0; i < 10; ++i) {
//		std::cout << piMath::Random::getRandomFloat() << std::endl;
//	}
//}


int main(int argc, char* argv[]) {
    

    //initialize stuff here
    piMath::Time time;
    piMath::Renderer newRenderer;
	piMath::InputSystem inputSystem;
    std::vector<piMath::vec2> points;
    piMath::Model modelSystem;
    piMath::AudioSystem audioSystem;
	
	// piMath::Transform transformSystem;

    std::vector<piMath::vec2> squarePoint{
        {-5,-5},
        { 5,-5},
        { 5, 5},
        {-5, 5},
        {-5,-5}
    };

    piMath::Model model{ squarePoint, {0,0,1} };
	
    piMath::Model* models = new piMath::Model{ points, piMath::vec3{ 0,0,1 } };

    std::vector<piMath::Actor> actors;
    for (int i = 0; i < 100; i++) {
    
       
        piMath::Transform transformSystem{ piMath::vec2{piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024}, 0.0f, 2.0f};
        piMath::Actor actor{transformSystem, new piMath::Model{ squarePoint, piMath::vec3{ 1,0,0 } } };
		actors.push_back(actor);
    }

	newRenderer.Initialize();
    newRenderer.CreateWindow("Game project", 1280, 1024);
	inputSystem.Initialize();
    audioSystem.Initialize();
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Event e;
    bool quit = false;

    // generate random stars that move
    piMath::vec2 speed{ 0.1f, 0.0f };
    std::vector<piMath::vec2> stars;
    for (int i = 0; i < 100; i++) {
       
        stars.push_back(piMath::vec2{ piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024 }); // use curly for constructors
    }

    // add sounds before the loop begins

	audioSystem.addSound("bass.wav", "bass");
	audioSystem.addSound("snare.wav", "snare");
	audioSystem.addSound("clap.wav", "clap");
	audioSystem.addSound("close-hat.wav", "close-hat");
	audioSystem.addSound("open-hat.wav", "open-hat");
    

    //MAIN LOOP
    while (!quit) {
        time.Tick();
        inputSystem.Update();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }

            if (inputSystem.getKeyPressed(SDL_SCANCODE_ESCAPE)) {
                quit = true;
            }
        }

        /*if (inputSystem.getKeyReleased(SDL_SCANCODE_A)) {
			std::cout << "A key pressed!" << std::endl;
        }

        if (inputSystem.getMouseButtonDown(0)) {
			std::cout << "Left mouse button pressed!" << std::endl;
        }

        if (inputSystem.getKeyReleased(SDL_SCANCODE_F)) {
			audioSystem.playSound("bass");
        }
		if (inputSystem.getKeyReleased(SDL_SCANCODE_G)) {
			audioSystem.playSound("snare");
		}
		if (inputSystem.getKeyReleased(SDL_SCANCODE_H)) {
			audioSystem.playSound("clap");
		}
		if (inputSystem.getKeyReleased(SDL_SCANCODE_J)) {
			audioSystem.playSound("close-hat");
		}
		if (inputSystem.getKeyReleased(SDL_SCANCODE_K)) {
			audioSystem.playSound("open-hat");
		}*/

		/*if (inputSystem.getKeyDown(SDL_SCANCODE_A)) { transformSystem.rotation -= piMath::Math::degToRad(90 * time.GetDeltaTime()); }
        if (inputSystem.getKeyDown(SDL_SCANCODE_D)) { transformSystem.rotation += piMath::Math::degToRad(90 * time.GetDeltaTime()); }*/

        float speed = 175;
		piMath::vec2 direction{ 0,0 };

        if (inputSystem.getKeyDown(SDL_SCANCODE_W))  direction.y -= 100; /*time.GetDeltaTime(); };*/
        if (inputSystem.getKeyDown(SDL_SCANCODE_A))  direction.x -= 100; /*time.GetDeltaTime(); };*/
        if (inputSystem.getKeyDown(SDL_SCANCODE_S))  direction.y += 100; /*time.GetDeltaTime(); };*/
        if (inputSystem.getKeyDown(SDL_SCANCODE_D))  direction.x += 100; /*time.GetDeltaTime(); };*/

        if (direction.LengthSqr() > 0) {
            direction = direction.Normalize();

            for (auto actor : actors) {
                actor.GetTransform().position += (direction * speed * time.GetDeltaTime());
            }

            /*transformSystem.position += (direction * speed * time.GetDeltaTime());*/
			
        }
        
		audioSystem.Update();

        // draw stuff

        piMath::vec3 color{ 0, 0, 0 };
        newRenderer.SetColor(color.r,color.g,color.b);
        newRenderer.Clear();

       for (auto& actor : actors) {
		    newRenderer.SetColor(255.0f, 0.0f, 0.0f);
            actor.Draw(newRenderer);
           
	   }

		if (inputSystem.GetMouseReleased(0)) {
            points.push_back(inputSystem.getMousePosition());
		}

        // line drawing below
        if (inputSystem.getMouseButtonDown(0)) {
            piMath::vec2 position = inputSystem.getMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color so we can see what we drew
			newRenderer.SetColor(255.0f,255.0f,255.0f);
            newRenderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        newRenderer.Present();
        
    }
    
	newRenderer.Shutdown();
    audioSystem.Shutdown();
    

    return 0;
}