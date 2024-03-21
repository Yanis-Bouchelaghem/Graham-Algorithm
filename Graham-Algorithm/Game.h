#pragma once
#include <string>
#include "PointCloud.h"
#include "Polygon.h"

class Window
{
public:
	Window(int width, int height, int fps, std::string title);
	Window(const Window& other) = delete;
	Window& operator=(const Window& other) = delete;
	~Window() noexcept;
	bool GameShouldClose() const;
	void Tick();
private:
	void Update();
	void Draw();
private:
	PointCloud pointCloud;
	Polygon convexEdge;
};