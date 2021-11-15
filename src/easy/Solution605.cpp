#include <vector>
#include <iostream>
#include<numeric>

using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n);

bool canPlaceFlowers(vector<int>& flowerbed, int n) 
{
	unsigned int size = flowerbed.size();
	flowerbed.insert(flowerbed.begin(), 0);
	flowerbed.insert(flowerbed.end(), 0);

	for (int i = 1;i <= size;i++)
	{
		if (flowerbed[i] == 0 && (flowerbed[i-1] == 0 && flowerbed[i+1] == 0))
		{
			flowerbed[i] = 1;
			n--;
		}
	}

	return n <= 0;
}

int main()
{
	vector<int> flower = { 0,0,1,0,1 };
	cout << "Output: " << canPlaceFlowers(flower, 1) << endl;

	return 0;
}