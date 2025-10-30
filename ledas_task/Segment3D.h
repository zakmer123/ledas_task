#ifndef SEGMENT3D_H
#define SEGMENT3D_H

#include <cmath>
#include <optional>
#include <iostream>

#include "Vector3D.h"

class Segment3D{
	Vector3D start_;
	Vector3D end_;
public:
	Segment3D(const Vector3D& start, const Vector3D& end) : start_(start), end_(end) {}

	Vector3D start() const { return start_; }
	Vector3D& start() { return start_; }
	Vector3D end() const { return end_; }
	Vector3D& end() { return end_; }

	//����� �������
	double length() const;
	//�������������� ����� �������
	bool contain(const Vector3D& v) const;
	//����� ����������� ���� �������� (���������� ��� Vector3D, ��� � std::nullopt)
	std::optional<Vector3D> intersect(const Segment3D& s) const;
};
#endif
