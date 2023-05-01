#include "Game.h"
#include <raylib.h>
#include <assert.h>

Game::Game(int width, int height, std::string title)
{
	assert(!GetWindowHandle()); //If assertion triggers : window is already open
	InitWindow(width, height, title.c_str());
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

}
void Game::Update()
{
	ClearBackground(RAYWHITE);
}
