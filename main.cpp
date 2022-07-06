#include "DxLib.h"
#include "Coord2.h"

void func(const int(&array)[4][4])
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			printfDx("%d,", array[i][j]);
		}
		printfDx("\n");
	}
}

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	Coord2<double> a(3, 4), b(1, 1);
	int array[4][4];

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0) {

		//ここに処理を追加
		clsDx();
		printfDx("%lf,%lf\n", a.x, a.y);
		a = a + b;
		func(array);
	}


	DxLib_End(); // DXライブラリ終了処理
	return 0;
}