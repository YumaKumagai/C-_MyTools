#include <chrono>

class Stopwatch
{
	std::chrono::system_clock::time_point start;	//計測開始時間
	std::chrono::system_clock::time_point end;		//計測終了時間
	double elapsed;									//処理に要した時間(ミリ秒)

public:
	Stopwatch();		//elapsedを0.で初期化
	void SetStart();	//startに計測開始時間を代入
	void SetEnd();		//endに計測終了時間を代入,elapsedに計測結果を加算
	double GetElapsedTime()const { return elapsed; }
	void ResetElapsedTime();	//elapsedに0.を代入

};