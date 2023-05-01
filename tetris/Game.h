#pragma once
#include <string>

class Game
{
private:
	void Draw();
	void Update();

public:
	Game(int width, int height, std::string title);
	~Game() noexcept;
	bool GameShouldClose() const;

	void Tick();

};
