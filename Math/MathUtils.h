#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/norm.hpp>
#include <cstdlib>
#include <algorithm>

inline float random01()
{
	return rand() / (float)RAND_MAX;
}

inline float random(float min, float max)
{
	if (min > max) std::swap(min, max);

	return min + (max - min) * random01();
}

/// <summary>
/// Gets a random In Unit Sphere
/// </summary>
/// <returns>point</returns>
inline glm::vec3 randomInUnitSphere()
{
	glm::vec3 point;
	do
	{
		point = glm::vec3{ random(-1, 1), random(-1, 1), random(-1, 1) };
	} while (glm::length2(point) >= 1);
	
	return point;

}

inline float dot(const glm::vec3& v1, const glm::vec3& v2)
{
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

/// <summary>
/// Reflection
/// </summary> Get reflection vector
/// <param name="v"></param>
/// <param name="n"></param>
/// <returns>Reflection Vector</returns>
inline glm::vec3 reflect(const glm::vec3& v, const glm::vec3& n)
{
	return v - (n * dot(n, v)) * 2.0f;
}

template <typename T>
inline T lerp(T a, T b, float t)
{
	return (a * (1.0f - t)) + (b * t);
	//return a + (a - b) * t; //alt way of interpolating
}
