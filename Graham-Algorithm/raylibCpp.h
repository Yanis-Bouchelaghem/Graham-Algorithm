#pragma once
#include <raylib.h>
#include "Vec2.h"
namespace raycpp
{
	void DrawCircle(Vec2<int> pos, float radius, Color color);// Draw a color-filled circle.
	void DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color); //Draw a color-filled rectangle.
	void DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThick, Color color); //Draw a hollow ractangle with edges.
}