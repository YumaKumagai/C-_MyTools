#pragma once
#define _USE_MATH_DEFINES
#include <cmath>

template<class T>class Coord4
{
public:
	// メンバ変数
	T x;
	T y;
	T z;
	T w;

// メソッド
	Coord4()
		:x(0), y(0), z(0), w(0) {}
	Coord4(T x, T y, T z, T w)
		:x(x), y(y), z(z), w(w) {}

	template<class U>Coord4<U> Cast()const
	{
		return {
			static_cast<U>(x),static_cast<U>(y),
			static_cast<U>(z),static_cast<U>(w)
		};
	}

#pragma region 単項演算子・代入演算子オーバーロード

	Coord4 operator+()const
	{
		return *this;
	}

	Coord4 operator-()const
	{
		return {
			-x,-y,-z,-w
		};
	}

	Coord4& operator+=(const Coord4& c4)
	{
		*this = *this + c4;
		return *this;
	}

	Coord4& operator-=(const Coord4& c4)
	{
		*this += (-c4);
		return *this;
	}

	Coord4& operator*=(T t)
	{
		*this = *this * t;
		return *this;
	}

	Coord4& operator*=(const Coord4& c4)
	{
		*this = *this * c4;
		return *this;
	}

	Coord4& operator/=(T t)
	{
		*this = *this / t;
		return *this;
	}

	Coord4& operator/=(const Coord4& c4)
	{
		*this = *this / c4;
		return *this;
	}

#pragma endregion

};

#pragma region 二項演算子オーバーロード

template<class T>
inline Coord4<T> operator+(const Coord4<T>& a, const Coord4<T>& b)
{
	return {
		a.x + b.x,a.y + b.y,a.z + b.z,a.w + b.w
	};
}

template<class T>
inline Coord4<T> operator-(const Coord4<T>& a, const Coord4<T>& b)
{
	return a + (-b);
}

template<class T>
inline Coord4<T> operator*(const Coord4<T>& a, T t)
{
	return {
		a.x * t,a.y * t,a.z * t,a.w * t
	};
}

template<class T>
inline Coord4<T> operator*(T t, const Coord4<T>& a)
{
	return a * t;
}

template<class T>
inline Coord4<T> operator*(const Coord4<T>& a, const Coord4<T>& b)
{
	return {
		a.x * b.x,a.y * b.y,a.z * b.z,a.w * b.w
	};
}

template<class T>
inline Coord4<T> operator/(const Coord4<T>& a, T t)
{
	return {
		a.x / t,a.y / t,a.z / t,a.w / t
	};
}

template<class T>
inline Coord4<T> operator/(const Coord4<T>& a, const Coord4<T>& b)
{
	return {
		a.x / b.x,a.y / b.y,a.z / b.z,a.w / b.w
	};
}

#pragma endregion

using Int4 = Coord4<int>;
using Float4 = Coord4<float>;
using Vector4 = Coord4<float>;
using Double4 = Coord4<double>;