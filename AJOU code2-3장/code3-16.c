#include <stdio.h>
#define MAX_DEGREE 6
struct polynomial {
	int degree;
	int coef[MAX_DEGREE];
} poly = {5, {100,0,0,0,60,0}}; //이렇게 들어가야 5제곱과 1제곱에 들어감

// 3번이 답.