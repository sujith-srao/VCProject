#pragma once
#include<math.h>

template<typename T>
inline T max(T& a, T& b) {
	if (a > b)
		return a;
	return b;
}