#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i<8; i++)
	{
		printf("x:%f y:%f z:%f\n\n", ((i >> 2) & 1) - 0.5, ((i >> 1) & 1) - 0.5, ((i & 1)) - 0.5);
	}
}