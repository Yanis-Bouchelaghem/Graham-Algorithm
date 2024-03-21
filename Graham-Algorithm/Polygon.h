#pragma once
#include <vector>
#include "raylibCpp.h"
#include "PointCloud.h"

class Polygon
{
public:
	Polygon() = default;
	Polygon(const PointCloud& edge);
public:
	void AddPoint(const Point2D<int>& point);
	void RemovePoint(int index);
	int GetPointCount() const;
	void Draw(Color color) const;
	static Polygon GrahamAlgorithm(const PointCloud& pointCloud);
private:
	PointCloud hull;
};