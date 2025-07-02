#define NAME "Alec"
#include "Math/Math.h"
#include "Core/Random.h"
#include <iostream>


int main() {

	// const float degree = piMath::radToDeg(piMath::pi);
	piMath::Math::min(3, 2);
	piMath::Math::clamp(5, 1, 10);

	std::cout << NAME << std::endl;
	std::cout << "Hello, World!" << std::endl;
	std::cout << "I am writing this to future me!" << std::endl;
	std::cout << piMath::Math::pi << std::endl;

	for (int i = 0; i < 10; ++i) {
		std::cout << piMath::Random::getRandomFloat() << std::endl;
	}

}