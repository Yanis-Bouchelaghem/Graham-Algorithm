#pragma once
#include <cmath>

template <typename T>
class Point2D
{
public:
	Point2D() = default;
	constexpr Point2D(T x, T y)
		:
		x(x),
		y(y)
	{}
	constexpr float PolarAngle(const Point2D<T>& otherPoint) const
	{
		return std::atan2(y - otherPoint.y, x - otherPoint.x);
	}
	static constexpr float crossProduct(const Point2D<T>& p0, const Point2D<T>& p1, const Point2D<T>& p2) {
		return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
	}
public:
	constexpr T GetX() const {return x;};
	constexpr T GetY() const {return y;};
	constexpr void SetX(T x_in) { x = x_in;};
	constexpr void SetY(T y_in) { y = y_in;};
public:
	constexpr bool operator<(const Point2D& rhs) const
	{
		if (y != rhs.y)
			return y < rhs.y;
		else
			return x < rhs.x;
	}
	constexpr bool operator>(const Point2D& rhs) const
	{
		if (y != rhs.y)
			return y > rhs.y;
		else
			return x > rhs.x;
	}
	constexpr bool operator==(const Point2D& rhs) const
	{
		return (x == rhs.x && y == rhs.y);
	}
	constexpr bool operator!=(const Point2D& rhs) const
	{
		return !(*this == rhs);
	}
	constexpr Point2D operator+(const Point2D& rhs) const
	{
		return {x + rhs.x, y + rhs.y};
	}
	constexpr Point2D operator+(const int rhs) const
	{
		return {x + rhs, y + rhs};
	}
	constexpr Point2D& operator+=(const Point2D& rhs)
	{
		 return *this = *this + rhs;
	}
	constexpr Point2D operator-(const Point2D& rhs) const
	{
		return {x - rhs.x, y - rhs.y};
	}
	constexpr Point2D operator-(const int rhs) const
	{
		return { x - rhs, y - rhs};
	}
	constexpr Point2D& operator-=(const Point2D& rhs)
	{
		return *this = *this - rhs;
	}
	constexpr Point2D operator*(const Point2D& rhs) const
	{
		return {x * rhs.x, y * rhs.y};
	}
	constexpr Point2D operator*(const int rhs) const
	{
		return { x * rhs, y * rhs };
	}
	constexpr Point2D& operator*=(const Point2D& rhs)
	{
		return *this = *this * rhs;
	}

private:
	T x;
	T y;
};
