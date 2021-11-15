

#include <vector>
#include <iostream>
#include "LeetcodePrint.h"

using namespace std;

bool judgeSquareSum(int c) {
	long j = sqrt(c), i = 0;
	while(i <= j)
	{
		long t = i * i + j * j;
		if (t < c)
		{
			i++;
		}
		else if (t > c)
		{
			j--;
		}
		else
		{
			return true;
		}
	}

	return false;
}

int main()
{

	return 0;
}