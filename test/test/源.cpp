#include<iostream>
using namespace std;


//ĳ���뽫���е�һ����ֵ100Ԫ������һ���10Ԫ��5Ԫ��2Ԫ��1Ԫ��ֵ��Ʊ�ӡ�
//Ҫ������40�ţ���ÿ��Ʊ������һ�š��ʣ��м��ֻ�����

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