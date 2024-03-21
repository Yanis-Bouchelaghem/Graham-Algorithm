#include <assert.h>
#include "Game.h"
#include "raylibCpp.h"
#include "Settings.h"
Game::Game(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
	pointCloud.AddPoint({300, 200});
	pointCloud.AddPoint({300, 150});
	pointCloud.AddPoint({100, 240});
	pointCloud.AddPoint({500, 490});
	pointCloud.AddPoint({320, 00});
}

Game::~Game() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
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

void Game::Update()
{
}

void Game::Draw()
{

	pointCloud.Draw(5, RAYWHITE);
}



