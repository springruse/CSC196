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
#include "Renderer/Font.h"
#include "Engine.h"
#include "Renderer/Text.h"

#include <memory>
#include <random>
#include <vector>

#include <iostream>

int main(int argc, char* argv[]) {
    
    //make pointers here
    std::unique_ptr<SpaceGame> game = std::make_unique<SpaceGame>();

    //initialize stuff here
    
	piMath::GetEngine().Initialize();
	game->Initialize();

	piMath::Scene scene;

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

	piMath::Font* font = new piMath::Font();
	font->Load("CFSpaceship-Regular.ttf", 24); // Load a font with size 24
	
    piMath::Text* text = new piMath::Text(font);
    text->Create(piMath::GetEngine().GetRenderer(), "Hello World", piMath::vec3{1.0f, 1.0f, 1.0f});
    text->Draw(piMath::GetEngine().GetRenderer(), 40.0f, 40.0f);


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
        piMath::GetEngine().GetRenderer().SetColor(0.0f, 0.0f, 0.0f); // Set background color to black
        piMath::GetEngine().GetRenderer().Clear();
        text->Draw(piMath::GetEngine().GetRenderer(), 40.0f, 40.0f);
		game->Draw(); // uses *
        game->Update();
        
        piMath::GetEngine().GetRenderer().Present();
       
        
    }
	game->Shutdown();
    piMath::GetEngine().Shutdown();
    return 0;
}