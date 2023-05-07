#pragma once

template <typename T>

class Vec2
{
public:
	Vec2() = default;
	Vec2(T x, T y)
		:
		x(x),
		y(y)
	{}

	T getX() const { return x; };
	T getY() const { return y; };
	void setX(T xx) { x = xx; };
	void setY(T yy) { y = yy; };

	Vec2 operator+(const Vec2& rhs) const
	{
		return{ x + rhs.x, y + rhs.y };
	}
	Vec2 operator+(const int rhs) const
	{
		return{ x + rhs, y + rhs };
	}
	Vec2 operator-(const Vec2& rhs) const
	{
		return{ x - rhs.x, y - rhs.y };
	}
	Vec2 operator-(const int rhs) const
	{
		return{ x - rhs, y - rhs };
	}
	Vec2 operator*(const Vec2& rhs) const
	{
		return{ x * rhs.x, y * rhs.y };
	}
	Vec2 operator*(const int rhs) const
	{
		return{ x * rhs, y * rhs };
	}
	Vec2& operator+=(const Vec2& rhs)
	{
		*this = *this + rhs;
	}
	Vec2& operator-=(const Vec2& rhs)
	{
		*this = *this - rhs;
	}
	Vec2& operator*=(const Vec2& rhs)
	{
		*this = *this * rhs;
	}
	bool operator==(const Vec2& rhs) const 
	{
		return (x == rhs.x && y == rhs.y);
	}
	bool operator!=(const Vec2& rhs)const 
	{
		return !(*this == rhs);
	}
private:
	T x;
	T y;



};
