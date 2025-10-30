#include "Segment3D.h"

double Segment3D::length() const {
	double result = (start_.x() - end_.x()) * (start_.x() - end_.x());
	result += (start_.y() - end_.y()) * (start_.y() - end_.y());
	result += (start_.z() - end_.z()) * (start_.z() - end_.z());
	return std::sqrt(result);
}

bool Segment3D::contain(const Vector3D& v) const {
	Vector3D v1(end_, -1, start_);
	Vector3D v2(v, -1, start_);
	Vector3D v3 = v1.cross(v2);
	if (std::sqrt(v3.dot(v3)) / (*this).length() > 1e-13) return false; //критерий для работы с иррациональными числами
	double projection = v2.dot(v1);
	return  0 <= projection && projection <= v1.dot(v1);
}

std::optional<Vector3D> Segment3D::intersect(const Segment3D& s) const {
	//проверка на вырожденность отрезков (сначала обоих отрезков, потом по отдельности)
	if ((*this).length() == 0 && s.length() == 0) {
		return (start_ == s.start()) ? std::optional<Vector3D>(start_) : std::nullopt;
	}
	else if ((*this).length() == 0) {
		return s.contain(start_) ? std::optional<Vector3D>(start_) : std::nullopt;
	}
	else if (s.length() == 0) {
		return (*this).contain(s.start()) ? std::optional<Vector3D>(s.start()) : std::nullopt;
	}
	//dir1 - направляющий вектор первого отрезка
    //dir2 - направляющий вектор второго отрезка
    //dir3 - вектор между точками отрезков (например start)
    //dircross - векторное произведение dir1 и dir2
	Vector3D dir1(end_, -1, start_);
	Vector3D dir2(s.end(), -1, s.start());
	Vector3D dircross = dir1.cross(dir2);
	Vector3D dir3(s.start(), -1, start_);
	//проверка компланарности dir1, dir2, dir3
	if (dircross.dot(dir3) != 0) return std::nullopt;

	//n - перпендикулярный вектор к dir1 и к нормали плоскости векторов, направляющих отрезки 
	Vector3D n = dir1.cross(dircross);
	double denom = n.dot(dir2);
	//проверяем параллельность направляющих векторов (и в случае параллельности принадлежность граничных точек)
	if (denom == 0) {
		if (s.contain(start_)) return start_;
		else if (s.contain(end_)) return end_;
		else if ((*this).contain(s.start())) return s.start();
		else return std::nullopt;
	}
	//находим пересечение прямых, на которых лежат отрезки
	double param2 = - n.dot(dir3) / denom;
	Vector3D intersec(s.start(), param2, dir2);
	//если intersec (точка пересечения прямых) не принадлежит обоим отрезкам - пересечения нет
	return (s.contain(intersec) && (*this).contain(intersec)) ? 
		std::optional<Vector3D>(intersec) : std::nullopt;
}
