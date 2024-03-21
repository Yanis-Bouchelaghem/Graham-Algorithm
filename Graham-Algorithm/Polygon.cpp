#include "Polygon.h"

Polygon::Polygon(const PointCloud& edge)
	:
	edge(edge)
{
}

void Polygon::AddPoint(const Point2D<int>& point)
{
	edge.AddPoint(point);
}

void Polygon::RemovePoint(int index)
{
	edge.RemovePoint(index);
}

int Polygon::GetPointCount() const
{
	return edge.GetPointCount();
}

void Polygon::Draw(Color color) const
{
	auto points = edge.GetPoints();
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
