#include "Counter.h"

Counter::Counter()
	:counter(0)
{
}

void Counter::Incr()
{
	if (counter < UINT_MAX)++counter;
}

void Counter::Decr()
{
	if (counter > 0)--counter;
}

void Counter::Reset()
{
	counter = 0;
}
