#include <Core/Random.h>
#include <Renderer/Renderer.h>
#include <Math/Math.h>
#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Core/Time.h>
#include <Input/InputSystem.h>
#include <Audio/AudioSystem.h>
#include <Renderer/Model.h>
#include <EngineGame/Actor.h>
#include "EngineGame/Scene.h"
#include "Game/Player.h" 
#include "Game/SpaceGame.h"
#include "Engine.h"

#include <memory>
#include <random>
#include <vector>

#include <iostream>

int main(int argc, char* argv[]) {
    


    //initialize stuff here
    
	piMath::GetEngine().Initialize();
	std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();

    std::vector<piMath::vec2> points; // has no actual points
	piMath::Scene scene;

    
	
    piMath::Model* models = new piMath::Model{ points, piMath::vec3{ 0,0,1 } };

    std::vector<piMath::Actor> actors;
    for (int i = 0; i < 100; i++) {
       
        piMath::Transform transformSystem{ piMath::vec2{piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024}, 0.0f, 2.0f};
        std::shared_ptr<piMath::Actor> actor = std::make_shared<piMath::Actor>(transformSystem, newModel );
		std::unique_ptr<Player> player = std::make_unique<Player>(transformSystem, newModel);
		scene.addActor(actor);
    }


	piMath::GetEngine().GetRenderer().Initialize();
    piMath::GetEngine().GetRenderer().CreateWindow("Game project", 1280, 1024);
	piMath::GetEngine().GetInput().Initialize();
    piMath::GetEngine().GetAudio().Initialize();
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

	piMath::GetEngine().GetAudio().addSound("bass.wav", "bass");
    piMath::GetEngine().GetAudio().addSound("snare.wav", "snare");
    piMath::GetEngine().GetAudio().addSound("clap.wav", "clap");
    piMath::GetEngine().GetAudio().addSound("close-hat.wav", "close-hat");
    piMath::GetEngine().GetAudio().addSound("open-hat.wav", "open-hat");
    

    //MAIN LOOP
    while (!quit) {
		piMath::GetEngine().GetTime().Tick();
        piMath::GetEngine().GetInput().Update();
		piMath::GetEngine().GetAudio().Update();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }

            if (piMath::GetEngine().GetInput().getKeyPressed(SDL_SCANCODE_ESCAPE)) {
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

		/*if (inputSystem.getKeyDown(SDL_SCANCODE_A)) { transformSystem.rotation -= piMath::Math::degToRad(90 * time.GetDeltaTime()); }
        if (inputSystem.getKeyDown(SDL_SCANCODE_D)) { transformSystem.rotation += piMath::Math::degToRad(90 * time.GetDeltaTime()); }*/
        
        // draw stuff

        piMath::vec3 color{ 0, 0, 0 };
        piMath::GetEngine().GetRenderer().SetColor(color.r, color.g, color.b);
        piMath::GetEngine().GetRenderer().Clear();
		scene.Draw(piMath::GetEngine().GetRenderer()); // uses *

       for (auto& actor : actors) {
		    piMath::GetEngine().GetRenderer().SetColor(255.0f, 0.0f, 0.0f);
            actor.Draw(piMath::GetEngine().GetRenderer()); // uses *
	   }

		if (piMath::GetEngine().GetInput().GetMouseReleased(0)) {
            points.push_back(piMath::GetEngine().GetInput().getMousePosition());
		}

        // line drawing below
        if (piMath::GetEngine().GetInput().getMouseButtonDown(0)) {
            piMath::vec2 position = piMath::GetEngine().GetInput().getMousePosition();
            if (points.empty()) points.push_back(position);
            else if ((position - points.back()).Length() > 10) points.push_back(position);
        }

        for (int i = 0; i < (int)points.size() - 1; i++) {
            // set color so we can see what we drew
            piMath::GetEngine().GetRenderer().SetColor(255.0f,255.0f,255.0f);
            piMath::GetEngine().GetRenderer().DrawLine(points[i].x, points[i].y, points[i + 1].x, points[i + 1].y);
        }

        piMath::GetEngine().GetRenderer().Present();
        
    }
    
	delete models;

    piMath::GetEngine().GetAudio().Shutdown();
    piMath::GetEngine().GetRenderer().Shutdown();
    
    return 0;
}