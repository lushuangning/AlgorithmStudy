//
// Created by 路双宁  on 2021/3/23.
//
#include <vector>
#include <string>
#include <iostream>
using namespace std;

char firstUniqChar(string s);

char firstUniqChar(string s)
{
    if(s.empty())
        return ' ';

    vector<int> hashTable(256, 0);

    for (char i : s)  { hashTable[(int)i]++; }

    for (char i : s) 
    {
        if (hashTable[(int)i] == 1)
            return i;
    }

    return ' ';
}

int main()
{
	string test = "abcdefghiu";

	cout << firstUniqChar(test);

	return 0;
}