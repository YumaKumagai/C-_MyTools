#include "Funcs.h"

// DxLib関数オーバーロード
int DrawCircle(const Int2& pos, int radius, unsigned color,
	int fillFlag, int lineThickness)
{
	return DxLib::DrawCircle(pos.x, pos.y, radius, color, fillFlag, lineThickness);
}

int DrawBox(const Int2& upLeft, const Int2& downRight, unsigned color, int fillFlag)
{
	return DxLib::DrawBox(upLeft.x, upLeft.y, downRight.x, downRight.y, color, fillFlag);
}