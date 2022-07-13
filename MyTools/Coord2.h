#pragma once
#define _USE_MATH_DEFINES
#include <math.h>

template<class T>class Coord2
{
public:
	// メンバ変数
	T x;
	T y;

	// メソッド
	Coord2() :x(0), y(0) {}
	Coord2(T x, T y) :x(x), y(y) {}
	Coord2(const Coord2& c2) :x(c2.x), y(c2.y) {}

	static Coord2 Square(T xy)
	{
		return { xy,xy };
	}

	static Coord2<double> Unit(double radian)
	{
		return { cos(radian),sin(radian) };
	}

	template<class U>Coord2<U> Cast()const
	{
		return { static_cast<U>(x),static_cast<U>(y) };
	}

#pragma region 単項演算子・代入演算子オーバーロード

	Coord2 operator+()const
	{
		return *this;
	}

	Coord2 operator-()const
	{
		return { -x,-y };
	}

	Coord2& operator+=(const Coord2& c2)
	{
		*this = *this + c2;
		return *this;
	}

	Coord2& operator-=(const Coord2& c2)
	{
		*this += (-c2);
		return *this;
	}

	Coord2& operator*=(T t)
	{
		*this = *this * t;
		return *this;
	}

	Coord2& operator*=(const Coord2& c2)
	{
		*this = *this * c2;
		return *this;
	}

	Coord2& operator/=(T t)
	{
		*this = *this / t;
		return *this;
	}

	Coord2& operator/=(const Coord2& c2)
	{
		*this = *this / c2;
		return *this;
	}

#pragma endregion

	double Length()const
	{
		return sqrt(pow(x, 2) + pow(y, 2));
	}

	double Angle()const
	{
		double angle;
		double sin = y / Length();
		double arcsin = asin(sin);

		angle = (x >= 0) ? arcsin :
			(arcsin >= 0) ?
			M_PI - arcsin :
			-M_PI - arcsin;

		return angle;
	}

	Coord2<double> Normalize()const
	{
		return this->Cast<double>() / this->Length();
	}

	T Dot(const Coord2& c2)const
	{
		return x * c2.x + y * c2.y;
	}

	T Cross(const Coord2& c2)const
	{
		return x * c2.y - y * c2.x;
	}

};

#pragma region 二項演算子オーバーロード

template<class T>
inline Coord2<T> operator+(const Coord2<T>& a, const Coord2<T>& b)
{
	return { a.x + b.x,a.y + b.y };
}

template<class T>
inline Coord2<T> operator-(const Coord2<T>& a, const Coord2<T>& b)
{
	return a + (-b);
}

template<class T>
inline Coord2<T> operator*(const Coord2<T>& a, T t)
{
	return { a.x * t,a.y * t };
}

template<class T>
inline Coord2<T> operator*(T t, const Coord2<T>& a)
{
	return a * t;
}

template<class T>
inline Coord2<T> operator*(const Coord2<T>& a, const Coord2<T>& b)
{
	return { a.x * b.x,a.y * b.y };
}

template<class T>
inline Coord2<T> operator/(const Coord2<T>& a, T t)
{
	return { a.x / t,a.y / t };
}

template<class T>
inline Coord2<T> operator/(const Coord2<T>& a, const Coord2<T>& b)
{
	return { a.x / b.x,a.y / b.y };
}

#pragma endregion

using Int2 = Coord2<int>;
using Float2 = Coord2<float>;
using Vector2 = Coord2<float>;
using Double2 = Coord2<double>;