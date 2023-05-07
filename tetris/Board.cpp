#include "Board.h"
#include <raylib.h>
#include <assert.h>
#include "raylibCpp.h"

Board::Cell::Cell()
	:
	bExists(false),
	c(WHITE)
{
}

void Board::Cell::setColor(Color c_in)
{
	c = c_in;
	bExists = true;
}

void Board::Cell::Remove()
{
	bExists = false;
}

Color Board::Cell::getColor() const
{
	return c;
}

Board::Board(Vec2<int> screenPos, Vec2<int> widthHeight, int cellSizein,int padding)
	:
	screenPos(screenPos),
	width(widthHeight.getX()), height(widthHeight.getY()),
	cellSize(cellSizein), padding(padding)
{
	assert(width > 0 && height > 0);//If assertion triggers: width and height are smaller than 1.
	assert(cellSize > 0);//If assertion triggers: cellSize are smaller than 1.
	cells.resize(width * height);
}

void Board::setCell(Vec2<int> pos, Color c)
{
	assert(pos.getX() >= 0 && pos.getY() >= 0 && pos.getX() < width && pos.getY() < height);
	cells[pos.getY() * width + pos.getX()].setColor(c);

}

void Board::drawCell(Vec2<int> pos) const
{
	assert(pos.getX() >= 0 && pos.getX() < width && pos.getY() >= 0 && pos.getY() < height);
	Color c = cells[pos.getY() * width + pos.getX()].getColor();
	Vec2<int> topLeft = screenPos + padding + (pos * cellSize);
	raycpp::DrawRectangle(topLeft, Vec2{cellSize,cellSize} - padding, c);
}

void Board::draw() const
{
	for (int iY = 0; iY < height; iY++)
	{
		for (int iX = 0; iX < width; iX++)
		{
			drawCell({ iX,iY });
		}
	}
}
