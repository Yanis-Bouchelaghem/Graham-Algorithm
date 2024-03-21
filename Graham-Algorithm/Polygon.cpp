#include "Polygon.h"
#include <stack>
#include <assert.h>

Polygon::Polygon(const PointCloud& hull)
	:
	hull(hull)
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

Polygon Polygon::GrahamAlgorithm(PointCloud pointCloud)
{
    assert(pointCloud.GetPointCount() >= 3);
	//Sort the cloud points using polar sort
	pointCloud.PolarSort();
    auto& points = pointCloud.GetPoints();
	//Apply Graham algorithm
    // Initialize the stack with the first three points
    std::stack<Point2D<int>> stack;
    stack.push(points[0]);
    stack.push(points[1]);
    stack.push(points[2]);

    // Process remaining points
    for (size_t i = 3; i < points.size(); ++i) {
        while (stack.size() >= 2) {
            Point2D<int> top = stack.top();
            stack.pop();
            Point2D<int> secondTop = stack.top();
            if (Point2D<int>::crossProduct(secondTop, top, points[i]) > 0) {
                stack.push(top);
                break;
            }
        }
        stack.push(points[i]);
    }

    // Transfer points from stack to result vector
    Polygon result;
    while (!stack.empty()) {
        result.AddPoint(stack.top());
        stack.pop();
    }

	return result;
}
