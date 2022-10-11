#include <stdio.h>
#include <stdlib.h>
int main()
{
	int a[] = { 19,2,25,92,36,45 };
	
	/*1¹ø*/
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		printf("%d ", a[i]);

	/*2¹ø*/
	int min = INT_MAX, max = INT_MIN;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}
	printf("\n\nÃÖ¼Ú°ª : %d, ÃÖ´ñ°ª : %d", min, max);

	/*3¹ø*/
	int s = 0;
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		s += a[i];
	printf("\n\nÆò±Õ : %d", s / (sizeof(a) / sizeof(a[0])));

	/*4¹ø*/
	int ps = 0;
	int avg = s / (sizeof(a) / sizeof(a[0]));
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
		ps += (avg - a[i]) * (avg - a[i]);
	printf("\n\nºÐ»ê : %d", ps / (sizeof(a) / sizeof(a[0])));
	return 0;
}