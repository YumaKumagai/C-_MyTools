#pragma once

template<class T>
class Matrix4
{
	static const int ColLength = 4;
	static const int RowLength = 4;

public:
	T m[ColLength][RowLength];

	Matrix4()
		:m{ {0} } {}
	//Matrix4(const int)
};

