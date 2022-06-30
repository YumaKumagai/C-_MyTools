#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

template<class T>class Coord3
{
public:
	T x;
	T y;
	T z;

public:
	Coord3() :x(0), y(0), z(0) {}

	Coord3(T x, T y, T z) :x(x), y(y), z(z) {}

	Coord3(const Coord3& co3) :x(co3.x), y(co3.y), z(co3.z) {}

	template<class U>Coord3<U> Cast()const
	{
		return { static_cast<U>(x),static_cast<U>(y),static_cast<U>(z) };
	}

	Coord3 operator+()const
	{
		return *this;
	}

	Coord3 operator-()const
	{
		return { -x,-y,-z };
	}

	Coord3& operator+=(const Coord3& co3)
	{
		*this = *this + co3;
		return *this;
	}

	Coord3& operator-=(const Coord3& co3)
	{
		*this += (-co3);
		return *this;
	}

	Coord3& operator*=(T t)
	{
		*this = *this * t;
		return *this;
	}

	Coord3& operator*=(const Coord3& co3)
	{
		*this = *this * co3;
		return *this;
	}

	Coord3& operator/=(T t)
	{
		*this = *this / t;
		return *this;
	}

	Coord3& operator/=(const Coord3& co3)
	{
		*this = *this / co3;
		return *this;
	}

	double Length()const
	{
		return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
	}

	Coord3<double> Normalize()const
	{
		return this->Cast<double>() / this->Length();
	}

	T Dot(const Coord3& co3)const
	{
		return x * co3.x + y * co3.y + z * co3.z;
	}

	Coord3 Cross(const Coord3& co3)const
	{
		return {
			y * co3.z - z * co3.y,
			z * co3.x - x * co3.z,
			x * co3.y - y * co3.x
		};
	}

};

template<class T>
Coord3<T> operator+(const Coord3<T>& a, const Coord3<T>& b)
{
	return { a.x + b.x,a.y + b.y,a.z + b.z };
}

template<class T>
Coord3<T> operator-(const Coord3<T>& a, const Coord3<T>& b)
{
	return a + (-b);
}

template<class T>
Coord3<T> operator*(const Coord3<T>& a, T t)
{
	return { a.x * t,a.y * t,a.z * t };
}

template<class T>
Coord3<T> operator*(T t, const Coord3<T>& a)
{
	return a * t;
}

template<class T>
Coord3<T> operator*(const Coord3<T>& a, const Coord3<T>& b)
{
	reuturn{ a.x * b.x,a.y * b.y,a.z * b.z };
}

template<class T>
Coord3<T> operator/(const Coord3<T>& a, T t)
{
	return { a.x / t,a.y / t,a.z / t };
}

template<class T>
Coord3<T> operator/(const Coord3<T>& a, const Coord3<T>& b)
{
	return { a.x / b.x,a.y / b.y,a.z / b.z };
}

using Int3 = Coord3<int>;
using Float3 = Coord3<float>;
using Vector3 = Coord3<float>;
using Double3 = Coord3<double>;