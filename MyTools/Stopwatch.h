#include <chrono>

class Stopwatch
{
	std::chrono::system_clock::time_point start;	//�v���J�n����
	std::chrono::system_clock::time_point end;		//�v���I������
	double elapsed;									//�����ɗv��������(�~���b)

public:
	Stopwatch();		//elapsed��0.�ŏ�����
	void SetStart();	//start�Ɍv���J�n���Ԃ���
	void SetEnd();		//end�Ɍv���I�����Ԃ���,elapsed�Ɍv�����ʂ����Z
	double GetElapsedTime()const { return elapsed; }
	void ResetElapsedTime();	//elapsed��0.����

};