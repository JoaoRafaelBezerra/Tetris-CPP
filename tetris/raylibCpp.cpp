#include "raylibCpp.h"
#include <assert.h>
void raycpp::DrawRectangle(Vec2<int> pos, Vec2<int> widthHeight, Color color)
{
	assert(pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < GetScreenWidth() && pos.getY() < GetScreenWidth());
	DrawRectangle(pos.getX(), pos.getY(), widthHeight.getX(), widthHeight.getY(), color);
}
