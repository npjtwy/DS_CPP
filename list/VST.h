#pragma once
#include <stdio.h>

template <typename T>
struct VST
{
	void operator()(T& data)
	{
		printf("%d ", data);

	}
};