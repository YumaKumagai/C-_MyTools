#pragma once
#include <vector>
#include "Coord2.h"
#include "DxLib.h"

template<class T> bool IsInArray(T val, const std::vector<T>& array)
{
	for (const auto& e : array)
	{
		if (val == e)
		{
			return true;
		}
	}
	return false;
}

template<class T>bool IsInRect(const Coord2<T>& point,
	const Coord2<T>& upLeft, const Coord2<T>& downRight)
{
	if (upLeft.x <= point.x && point.x <= downRight.x)
	{
		if (upLeft.y <= point.y && point.y <= downRight.y)
		{
			return true;
		}
	}
	return false;
}

// DxLib関数オーバーロード
int DrawCircle(const Int2& pos, int radius, unsigned color,
	int fillFlag = 1, int lineThickness = 1);

int DrawBox(const Int2& upLeft, const Int2& downRight, unsigned color, int fillFlag);