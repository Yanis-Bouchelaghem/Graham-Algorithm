#include "PointCloud.h"
#include <assert.h>
#include <algorithm>

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

const void PointCloud::Draw(float radius, Color color) const
{
    for (const Point2D<int>& point : points)
    {
        raycpp::DrawCircle(point, radius, color);
    }

}

void PointCloud::PolarSort()
{
    std::vector<Point2D<int>> sortedPoints;
    //Find the minimum point.
    std::sort(points.begin(), points.end());
    //Save the minimum point as part of the convex hull and remove it from the points of the cloud.
    Point2D minimumPoint = points[0];
    points.erase(points.begin());
    //Sort the remaining points by using the polar sort
    std::sort(points.begin(), points.end(), [&minimumPoint](const Point2D<int>& point1, const Point2D<int>& point2) {
            return minimumPoint.PolarAngle(point1) < minimumPoint.PolarAngle(point2);
        });
    sortedPoints.push_back(minimumPoint);
    sortedPoints.insert(sortedPoints.end(), points.begin(), points.end());
    points = sortedPoints;
}
