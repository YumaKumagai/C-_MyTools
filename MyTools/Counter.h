#pragma once
#include <limits>

class Counter
{
	unsigned counter;

public:
	Counter();
	void Incr();	//1�J�E���g�A�b�v,�����UINT_MAX
	void Decr();	//1�J�E���g�_�E��,������0
	unsigned Get()const { return counter; }
	void Reset();

};