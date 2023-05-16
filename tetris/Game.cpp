#include <assert.h>
#include "Game.h"
#include "raylibCpp.h"
#include "Settings.h"
Game::Game(int width, int height,int fps, std::string title)
	:
	board(settings::boardPosition,
		  settings::boardWidthHeight,
		  settings::cellSize,
	      settings::padding)
{

	assert(!GetWindowHandle()); //If assertion triggers : window is already open
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	for (int iY = 0; iY < 20; iY++)
	{
		for (int iX = 0; iX < 10; iX++)
		{
			board.setCell({ iX, iY }, RED);
		}
	}
}

Game::~Game() noexcept
{
	assert(GetWindowHandle); //If assertion triggers : window is already closed
	CloseWindow();
}

bool Game::GameShouldClose() const
{
	return WindowShouldClose();
}

void Game::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}
void Game::Draw()
{
	ClearBackground(BLACK);
	board.draw();
	 
}
void Game::Update()
{
	
}
