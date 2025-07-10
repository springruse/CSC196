#pragma once
#include <cassert>
#include "Math.h"

namespace piMath {
	template<typename T>
	struct Vector2
	{
		T x, y;

		Vector2() = default;
		Vector2(T x, T y) : x(x), y(y) {};

		T operator [] (unsigned int index) const { assert(index < 2);  return (&x)[index]; }
		T& operator [] (unsigned int index) { assert(index < 2);  return (&x)[index]; }

		Vector2 operator +(const Vector2& v) const // positive
		{
			return Vector2{ x + v.x, y + v.y };
		}
		Vector2 operator -(const Vector2& v) const // negative
		{
			return Vector2{ x - v.x, y - v.y };
		}
		Vector2 operator *(const Vector2& v) const // mult
		{
			return Vector2{ x * v.x, y * v.y };
		}
		Vector2 operator /(const Vector2& v) const // divide
		{
			return Vector2{ x / v.x, y / v.y };
		}

		// Comparison operators
		Vector2 operator +(float s) const { return Vector2{ x + s, y + s }; }
		Vector2 operator -(float s) const { return Vector2{ x - s, y - s }; }
		Vector2 operator *(float s) const { return Vector2{ x * s, y * s }; }
		Vector2 operator /(float s) const { return Vector2{ x / s, y / s }; }

		Vector2& operator += (float s) { x += s; y += s; return *this; }
		Vector2& operator -= (float s) { x -= s; y -= s; return *this; }
		Vector2& operator *= (float s) { x *= s; y *= s; return *this; }
		Vector2& operator /= (float s) { x /= s; y /= s; return *this; }

		Vector2& operator += (const Vector2& v) { x += v.x; y += v.y; return *this; }
		Vector2& operator -= (const Vector2& v) { x -= v.x; y -= v.y; return *this; }
		Vector2& operator *= (const Vector2& v) { x *= v.x; y *= v.y; return *this; }
		Vector2& operator /= (const Vector2& v) { x /= v.x; y /= v.y; return *this; }

		/// <summary>
		/// 
		/// </summary>
		/// <returns></returns>
		float LengthSqr() const{
			return (x * x) + (y * y);
		}
		float Length() const{
			return piMath::Math::sqrtf(LengthSqr());
		}

	};

	using ivec2 = Vector2<int>;
	using vec2 = Vector2<float>;
}