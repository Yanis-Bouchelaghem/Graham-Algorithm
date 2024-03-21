#include "PointCloud.h"
#include <assert.h>

void PointCloud::AddPoint(const Point2D<int>& point)
{
    points.emplace_back(point);
}

void PointCloud::RemovePoint(int index)
{
    assert(index < points.size());
    points.erase(points.begin() + index);
}

int PointCloud::GetPointCount() const
{
    return points.size();
}

const std::vector<Point2D<int>>& PointCloud::GetPoints() const
{
    return points;
}

const void PointCloud::Draw(int radius, Color color) const
{
    for (const Point2D<int>& point : points)
    {
        raycpp::DrawCircle(point, radius, color);
    }

}
