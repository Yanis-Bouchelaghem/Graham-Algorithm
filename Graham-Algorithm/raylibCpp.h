#pragma once
#include <raylib.h>
#include "Point2D.h"
namespace raycpp
{
	void DrawCircle(Point2D<int> pos, float radius, Color color);// Draw a color-filled circle.
	void DrawLine(Point2D<int> startPos, Point2D<int> endPos, Color color);// Draw a line
	void DrawRectangle(Point2D<int> pos, Point2D<int> widthHeight, Color color); //Draw a color-filled rectangle.
	void DrawRectangleLinesEx(Point2D<int> pos, Point2D<int> widthHeight, int lineThick, Color color); //Draw a hollow ractangle with edges.
	bool IsMouseButtonPressed(int button); //Returns true if the button has been pressed once
	Point2D<int> GetMousePosition();
}