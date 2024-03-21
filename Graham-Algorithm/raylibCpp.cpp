#include "raylibCpp.h"
#include <assert.h>
void raycpp::DrawCircle(Vec2<int> pos, float radius, Color color)
{
	assert(pos.GetX() - radius >= 0 && pos.GetY() - radius >= 0 &&
		pos.GetX() + radius < GetScreenWidth() && pos.GetY() + radius < GetScreenHeight()); //If assertion triggers : Trying to draw outisde of the screen
	DrawCircle(pos.GetX(), pos.GetY(), radius, color);
}
void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		   pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //If assertion triggers : Trying to draw outisde of the screen
	DrawRectangle(pos.GetX(),pos.GetY(),widthHeight.GetX(),widthHeight.GetY(),color);
}

void raycpp::DrawRectangleLinesEx(Vec2<int> pos, Vec2<int> widthHeight, int lineThick, Color color)
{
	assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
		pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight()); //If assertion triggers : Trying to draw outisde of the screen
	assert(lineThick > 0); //If assertion triggers : line thickness is less than 1
	DrawRectangleLinesEx({(float)pos.GetX(),(float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY()}, (float)lineThick, color);
}
