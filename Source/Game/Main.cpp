#include <SDL3/SDL.h>
#include <Core/Random.h>
#include <Renderer/Renderer.h>
#include <Math/Math.h>
#include <Math/Vector2.h>
#include <Core/Time.h>
#include <Input/InputSystem.h>
#include <fmod.hpp>
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
    piMath::Time time;
    piMath::Renderer newRenderer;
	piMath::InputSystem inputSystem;
    std::vector<piMath::vec2> points;

	newRenderer.Initialize();
    newRenderer.CreateWindow("SDL3 Project", 1280, 1024);
	inputSystem.Initialize();

    // create audio system
    FMOD::System* audio;
    FMOD::System_Create(&audio);

    void* extradriverdata = nullptr;
    audio->init(32, FMOD_INIT_NORMAL, extradriverdata);

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Event e;
    bool quit = false;

    // generate random stars that move
    piMath::vec2 speed{ 0.1f, 0.0f };
    std::vector<piMath::vec2> stars;
    for (int i = 0; i < 100; i++) {
       
        stars.push_back(piMath::vec2{ piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024 }); // use curly for constructors
    }
    
    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };



    // play a sound before loop starts
    FMOD::Sound* sound = nullptr;
    audio->createSound("test.wav", FMOD_DEFAULT, 0, &sound);

    audio->playSound(sound, 0, false, nullptr);

    std::vector<FMOD::Sound*> sounds;
    audio->createSound("bass.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    audio->createSound("snare.wav", FMOD_DEFAULT, 0, &sound);
    sounds.push_back(sound);

    //MAIN LOOP
    while (!quit) {
        time.Tick();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }
		inputSystem.Update();

        if (inputSystem.getKeyReleased(SDL_SCANCODE_A)) {
			std::cout << "A key pressed!" << std::endl;
        }

        if (inputSystem.getKeyReleased(SDL_SCANCODE_E)) {
            audio->playSound(sound, 0, false, nullptr);
        }

        if (inputSystem.getKeyReleased(SDL_SCANCODE_A)) {
            std::cout << "A key pressed!" << std::endl;
        }

        if (inputSystem.getKeyReleased(SDL_SCANCODE_A)) {
            std::cout << "A key pressed!" << std::endl;
        }

        if (inputSystem.getMouseButtonDown(0)) {
			std::cout << "Left mouse button pressed!" << std::endl;
        }


		piMath::vec2 mouse = inputSystem.getMousePosition();
		std::cout << mouse.x << ", " << mouse.y << std::endl;

        newRenderer.SetColor(0,0,0);
        newRenderer.Clear();

		if (inputSystem.GetMouseReleased(0)) {
            points.push_back(inputSystem.getMousePosition());
		}

        if (inputSystem.getMouseButtonDown(0)) {
            piMath::vec2 position = inputSystem.getMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color so we can see what we drew
			newRenderer.SetColor(255,255,255);
            newRenderer.DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }


   //     for (auto& star : stars) {
   //         star += speed / time.GetDeltaTime();

   //         if (star[0] > 1280) {
   //             star[0] = 0;
   //         }
			//if (star[0] < 0) {
			//	star[0] = 1024;
			//}

   //         newRenderer.SetColor(piMath::Random::getRandomInt(256), piMath::Random::getRandomInt(256), piMath::Random::getRandomInt(256));
   //         newRenderer.DrawPoint(star.x, star.y); // Draw the star
   //    
   //     }

		//for (int i = 0; i < 100; ++i) { // Draw 100 lines per frame
  //          newRenderer.SetColor(piMath::Random::getRandomInt(0, 255), piMath::Random::getRandomInt(0, 255), piMath::Random::getRandomInt(0, 255), 255);
  //          newRenderer.DrawLine(piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024, piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024);
  //          newRenderer.Present();
		//}

        
        newRenderer.Present();
    }
    
	newRenderer.Shutdown();
    

    return 0;
}