#include <iostream>
#include <vector>
#include <algorithm>
#include <LeetcodePrint.h>

using namespace std;

// ����2.0�İ汾���Ľ�֮������
void process(vector<int>& arr, int L, int R) {

	if (L >= R) {
		return;
	}

	int less = L - 1;			// < �����ұ߽�
	int more = R + 1;		// > ������߽�
	int index = L;
	int p = arr[R];

	while (index < more) {
		if (arr[index] < p) {
			swap(arr[++less], arr[index++]);
		}
		else if (arr[index] > p) {
			swap(arr[index], arr[--more]);
		}
		else {
			index++;
		}
	}

	process(arr, L, less);
	process(arr, more, R);
}


// arr[L . . R] ��Χ�ϣ����� arr[R] ��������ֵ������partition
void quickSort(vector<int>& arr) {
	process(arr, 0, arr.size() - 1);
}

int main() {
	vector<int> arr = {8, 1, 4, 10, 5, 3, 3, 3};
	quickSort(arr);
	show1DVector(arr);

	return 0;
}