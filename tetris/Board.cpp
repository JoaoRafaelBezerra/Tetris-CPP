#include "Board.h"
#include <raylib.h>
#include <assert.h>
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

Board::Board(int screenX, int screenY, int widthin, int heightin, int cellSizein,int padding)
	:
	screenX(screenX), screenY(screenY),
	width(widthin), height(heightin),
	cellSize(cellSizein), padding(padding)
{
	assert(width > 0 && height > 0);//If assertion triggers: width and height are smaller than 1.
	assert(cellSize > 0);//If assertion triggers: cellSize are smaller than 1.
	cells.resize(width * height);
}

void Board::setCell(int x, int y, Color c)
{
	assert(x >= 0 && y >= 0 && x < width && y < height);
	cells[y * width + x].setColor(c);

}

void Board::drawCell(int x, int y) const
{
	assert(x >= 0 && x < width && y >= 0 && y < height);
	Color c = cells[y * width + x].getColor();
	DrawRectangle(screenX + x * cellSize + padding, screenY + y * cellSize  + padding , cellSize - padding, cellSize - padding , c);
}

void Board::draw() const
{
	for (int iY = 0; iY < height; iY++)
	{
		for (int iX = 0; iX < width; iX++)
		{
			drawCell(iX,iY);
		}
	}
}
