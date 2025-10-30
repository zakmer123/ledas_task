#include "Vector3D.h"

bool Vector3D::operator==(const Vector3D& v) const {
	return x_ == v.x_ && y_ == v.y_ && z_ == v.z_;
}

double Vector3D::dot(const Vector3D& v) const {
	return x_ * v.x() + y_ * v.y() + z_ * v.z(); 
}

Vector3D& Vector3D::cross(const Vector3D& v) const {
	Vector3D result(y_ * v.z() - z_ * v.y(), z_ * v.x() - x_ * v.z(), x_ * v.y() - y_ * v.x());
	return result;
}

void Vector3D::print() const {
	std::cout << '(' << x_ << ',' << y_ << ',' << z_ << ')' << std::endl;
	return;
}

