#include "Stopwatch.h"

using namespace std::chrono;

Stopwatch::Stopwatch()
	:elapsed(0.)
{
}

void Stopwatch::SetStart()
{
	start = system_clock::now();
}

void Stopwatch::SetEnd()
{
	end = system_clock::now();
	elapsed += duration_cast<milliseconds>(end - start).count();
}

void Stopwatch::ResetElapsedTime()
{
	elapsed = 0.;
}
