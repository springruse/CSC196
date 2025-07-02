#pragma once
#include <algorithm>

namespace piMath {
	namespace Math {
	

	constexpr float pi = 3.14159265358979323846f; // Pi constant
	constexpr float two_pi = 6.28318530717958647692f; // 2 * Pi constant
	constexpr float half_pi = 1.57079632679489661923f; // Pi / 2 constant

	/// <summary>
	/// converts an angle to radians to degrees
	/// </summary>
	/// <param name="radius"></param>
	/// <returns></returns>
	constexpr float radToDeg(float radius) {
		return radius * (180.0f / pi);
	}
	constexpr float degToRad(float degrees) {
		return degrees * (pi / 180.0f);
	}

	using std::min;
	using std::max;
	using std::clamp;
	} // namespace Math
}