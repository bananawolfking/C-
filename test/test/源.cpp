#include<iostream>
using namespace std;


//某人想将手中的一张面值100元的人民币换成10元、5元、2元和1元面值的票子。
//要求换正好40张，且每种票子至少一张。问：有几种换法？

#define one 1
#define two 2
#define five 5
#define ten 10

int main()
{
	int sum = 100;
	
	int count = 0;
	for (int a = 1; ; a++)
	{
		sum = sum - ten * a;
		if (sum <= 0)
		{
			break;
		}
		for (int b = 1; b <= 20; b++)
		{
			sum = sum -  five * b;
			if (sum <= 0)
			{
				sum = sum + five * b;
				continue;
			}
			for (int c = 1; c <= 50; c++)
			{
				sum = sum - two * c;
				if (sum <= 0)
				{
					sum = sum + two * c;
					continue;
				}
				int d = sum;
				if (a + b + c + d == 40)
				{
					count++;
				}	
				sum = sum + two * c;
			}
			sum = sum + five * b;
		}
		sum = sum + ten * a;
	}
	cout << count << endl;

	return 0;
}