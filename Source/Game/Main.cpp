#include <SDL3/SDL.h>
#include <Core/Random.h>
#include <Renderer/Renderer.h>
#include <Engine/Core/Math.h>
#include <random>
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
    piMath::Renderer newRenderer;

	newRenderer.Initialize();
    newRenderer.CreateWindow("SDL3 Project", 1280, 1024);
    // Setup screen dimensions
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 1024;

    // Setup random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> randX(0.0f, SCREEN_WIDTH);
    std::uniform_real_distribution<float> randY(0.0f, SCREEN_HEIGHT);

    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("SDL3 Project", 1280, 1024, 0);
    if (window == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == nullptr) {
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Event e;
    bool quit = false;
    vec2 v(30, 40);

    // Define a rectangle
    SDL_FRect greenSquare{ 270, 190, 200, 200 };


    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_EVENT_QUIT) {
                quit = true;
            }
        }

        newRenderer.SetColor(0,0,0);
        newRenderer.Clear();

		for (int i = 0; i < 100; ++i) { // Draw 100 lines per frame
            newRenderer.SetColor(piMath::Random::getRandomInt(0, 255), piMath::Random::getRandomInt(0, 255), piMath::Random::getRandomInt(0, 255), 255);
            newRenderer.DrawLine(piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024, piMath::Random::getRandomFloat() * 1280, piMath::Random::getRandomFloat() * 1024);
            newRenderer.Present();
		}

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set render draw color to black
        SDL_RenderClear(renderer); // Clear the renderer

        SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255); // Set render draw color to green
        SDL_RenderFillRect(renderer, &greenSquare); // Render the rectangle

		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0); 
		bool keepGoing = true; // This is just a placeholder for the while loop condition

   //     for (int i = 0; i < 100; ++i) { // Draw 100 lines per frame
   //         float x1 = randX(gen);
   //         float y1 = randY(gen);
   //         float x2 = randX(gen);
   //         float y2 = randY(gen);
			//SDL_SetRenderDrawColor(renderer,x1 , y1, x2, y2); // Set color to random
   //         SDL_RenderLine(renderer, x1, y1, x2, y2);
   //         SDL_RenderPoint(renderer, x2, y2);
   //     }

        
       
		SDL_RenderPresent(renderer); // Present the renderer to the screen
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}