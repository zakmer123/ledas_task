#ifndef VECTOR3D_H
#define VECTOR3D_H

#include <iostream>

class Vector3D{
	double x_;
	double y_;
	double z_;
public:
	Vector3D(double x, double y, double z) : x_(x), y_(y), z_(z) {}
	Vector3D(const Vector3D& v1, double param, const Vector3D& v2) : 
		x_(v1.x() + param * v2.x()), 
		y_(v1.y() + param * v2.y()),
		z_(v1.z() + param * v2.z()) {}

	double x() const { return x_; }
	double y() const { return y_; }
	double z() const { return z_; }

	//равенство Vector3D
	bool operator==(const Vector3D& v) const;
	//скалярное произведение
	double dot(const Vector3D& v) const;
	//векторное произведение
	Vector3D& cross(const Vector3D& v) const;
	//вывод в консоль
	void print() const;
};
#endif

