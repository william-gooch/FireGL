#include "Transform.hpp"

namespace fire::object {
	Transform::Transform(float x, float y, float r, float sx, float sy)
	{
		this->matrix = glm::mat3(1.0f);
		this->matrix = glm::translate(this->matrix, { x, y });
		this->matrix = glm::rotate(this->matrix, r);
		this->matrix = glm::scale(this->matrix, { sx, sy });
	}

	Transform::Transform(float x, float y) : Transform(x, y, 0.0f, 1.0f, 1.0f) {}

	Transform::Transform() : Transform(0.0f, 0.0f, 0.0f, 1.0f, 1.0f) {}


	Transform::~Transform()
	{
	}
	Transform Transform::operator*(Transform other)
	{
		Transform newTransform;
		newTransform.matrix = this->matrix * other.matrix;
		return newTransform;
	}
}