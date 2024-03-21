#pragma once
#include <vector>
#include "raylibCpp.h"
#include "Point2D.h"

class PointCloud
{
public:
	PointCloud() = default;
	void AddPoint(const Point2D<int>& point);
	void RemovePoint(int index);
	int GetPointCount() const;
	const std::vector<Point2D<int>>& GetPoints() const;
	const void Draw(float radius, Color color) const;
private:
	std::vector<Point2D<int>> points;
};