#pragma once
#include <raylib.h>
#include <vector>

class Board {
private:
	class Cell {
	public:
		Cell();
		void setColor(Color c_in);
		void Remove();
		Color getColor() const;
	private:
		bool bExists;
		Color c;
	};
public:
	Board(int screenX, int screenY,int widthin,int heightin,int cellSizein,int padding);
	void setCell(int x, int y, Color c);
	void drawCell(int x, int y) const;
	void draw() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding;
	int screenX;
	int screenY;

};

