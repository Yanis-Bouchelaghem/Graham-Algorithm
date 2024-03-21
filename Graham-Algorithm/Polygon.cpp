#include "Polygon.h"

Polygon::Polygon(const PointCloud& edge)
	:
	hull(edge)
{
}

void Polygon::AddPoint(const Point2D<int>& point)
{
	hull.AddPoint(point);
}

void Polygon::RemovePoint(int index)
{
	hull.RemovePoint(index);
}

int Polygon::GetPointCount() const
{
	return hull.GetPointCount();
}

void Polygon::Draw(Color color) const
{
	auto points = hull.GetPoints();
	for (int i = 1; i < points.size(); ++i)
	{
		raycpp::DrawLine(points[i-1], points[i], color);
	}
	if (points.size() >= 2)
	{
		//Draw a line between the first and the last
		raycpp::DrawLine(points[0], points[points.size() - 1], color);
	}

}

Polygon Polygon::GrahamAlgorithm(const PointCloud& pointCloud)
{
	//Sort the cloud points using le tri polaire
	
	//Apply Graham algorithm
	//Return a polygon
	return Polygon();
}
