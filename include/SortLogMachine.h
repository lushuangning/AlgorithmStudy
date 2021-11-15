#include <iostream>
#include <algorithm>
#include <vector>
#include<random>
#include<cassert>
#include<ctime>

using namespace std;


vector<int> generateRandomVector(int maxSize, int minValue, int maxValue);

vector<int> copyVector(vector<int>& vec);

bool isEqual(vector<int>& vec1, vector<int>& vec2);