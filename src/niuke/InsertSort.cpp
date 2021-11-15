#include <iostream>
#include <vector>
#include <LeetcodePrint.h>

using namespace std;

void insertSort(vector<int>& vec);

int main()
{

	return 0;
}


void insertSort(vector<int> &vec)
{
    int n = vec.size();

    for (int i = 1; i < n; ++i)
    {
        for (int j = i - 1; j >= 0 && vec[j] > vec[j + 1]; --j)
        {
            vec[j] = vec[j] ^ vec[j + 1];
            vec[j + 1] = vec[j] ^ vec[j + 1];
            vec[j] = vec[j] ^ vec[j + 1];
        }
    }

    for (int i = 0; i < n; ++i)
    {
        cout << vec[i] << " ";
    }
}