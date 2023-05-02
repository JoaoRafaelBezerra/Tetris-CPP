#pragma once
#include <string>
#include "Board.h"

class Game
{
private:
	void Draw();
	void Update();
	Board board;
public:
	Game(int width, int height,int fps, std::string title);
	Game(const Game& other) = delete;
	Game& operator=(const Game& other) = delete;
	~Game() noexcept;
	bool GameShouldClose() const;
	void Tick();

};
