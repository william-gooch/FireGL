#pragma once

#include <glm/glm.hpp>
#include <glm/gtx/matrix_transform_2d.hpp>

namespace fire::object {
	class Transform
	{
	public:
		Transform(float x, float y, float r, float sx, float sy);
		Transform(float x, float y);
		Transform();
		~Transform();

		Transform operator *(Transform other);

	private:
		glm::mat3 matrix;
	};
}

