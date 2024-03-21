#include <assert.h>
#include "Game.h"
#include "raylibCpp.h"
#include "Settings.h"
Window::Window(int width, int height, int fps, std::string title)
{
	assert(!GetWindowHandle());	//If assertion triggers : Window is already opened
	SetTargetFPS(fps);
	InitWindow(width, height, title.c_str());
}

Window::~Window() noexcept
{
	assert(GetWindowHandle()); //If assertion triggers : Window is already closed
	CloseWindow();
}

bool Window::GameShouldClose() const
{
	return WindowShouldClose();
}

void Window::Tick()
{
	BeginDrawing();
	Update();
	Draw();
	EndDrawing();
}

void Window::Update()
{
	if (raycpp::IsMouseButtonPressed(MouseButton::MOUSE_BUTTON_LEFT))
	{
		pointCloud.AddPoint(raycpp::GetMousePosition());
		pointCloud.PolarSort();
		if (pointCloud.GetPointCount() >= 3)
		{
			convexEdge = Polygon::GrahamAlgorithm(pointCloud);
		}
	}
}

void Window::Draw()
{
	ClearBackground(BLACK);
	pointCloud.Draw(5, RAYWHITE);
	convexEdge.Draw(RED);
}



