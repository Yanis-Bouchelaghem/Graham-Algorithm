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
	for (int i = 1; i < edge.GetPointCount(); ++i)
	{
		raycpp::DrawLine(points[i-1], points[i], color);
	}
}
