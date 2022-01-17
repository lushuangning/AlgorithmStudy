#include <iostream>

typedef struct _RECEIVE_DATA_
{
	char rx[5];
}RECEIVE_DATA;

int main()
{
	RECEIVE_DATA Receive_Data;
	char x[5] = { 'a','b','c','d' };
	memcpy(Receive_Data.rx, x, sizeof(x));
	std::cout << Receive_Data.rx << std::endl;
	//std::wcout << "The size of Receive_Data.rx is " << sizeof(Receive_Data.rx);
	return 0;
}