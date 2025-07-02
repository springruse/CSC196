#pragma once
#include <cstdlib>

namespace piMath {
	namespace Random {
		/// <summary>
		/// Generates a random int value.
		/// </summary>
		/// <returns> pseudo-random int value </returns>
		inline int getRandomInt() {
			return rand();
		}
		/// <summary>
		/// Generates a random int in the range [0, max).
		/// </summary>
		/// <param name="max"> upper bound (exclusive) for the random integer </param>
		/// <returns> a random integer greater than or equal to 0 and less than max </returns>
		inline int getRandomInt(int max) {
			return rand() % max;
		}
		/// <summary>
		/// Generates a random int within a specified inclusive range
		/// </summary>
		/// <param name="min"> </param>
		/// <param name="max"> </param>
		/// <returns></returns>
		inline int getRandomInt(int min, int max) {
			return min + getRandomInt(max - min + 1);
		}

		/// <summary>
		/// Generates a random floating-point number between 0.0 and 1.0
		/// </summary>
		/// <returns> random float in value range between 0.0 and 1.0</returns>
		inline float getRandomFloat() {
			return (rand()) / (float)(RAND_MAX);
		}
	}
}