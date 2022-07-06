#pragma once
#include <limits>

class Counter
{
	unsigned counter;

public:
	Counter();
	void Incr();	//1カウントアップ,上限はUINT_MAX
	void Decr();	//1カウントダウン,下限は0
	unsigned Get()const { return counter; }
	void Reset();

};