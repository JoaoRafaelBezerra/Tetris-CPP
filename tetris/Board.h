#pragma once
#include <raylib.h>
#include <vector>
#include "Vec2.h"

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
	Board(Vec2<int> screenPos,Vec2<int> widthHeight,int cellSizein,int padding);
	void setCell(Vec2<int> screenPos, Color c);
	void drawCell(Vec2<int> screenPos) const;
	void draw() const;
private:
	std::vector<Cell> cells;
	const int width;
	const int height;
	const int cellSize;
	const int padding;
	Vec2<int> screenPos;

};

