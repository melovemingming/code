#include <stdio.h>

int main(void)
{
	int number, flag;
	int i;

	flag = 1;

	printf("������һ����\n");
	scanf("%d", &number);

	for(i=2; i<(number/2); i++)
	{
		if(number % i == 0)
		{
			flag = 0;
			break;	// ֻ��Ҫ�ٳ�һ������
		}
	}

	if(flag == 1)
	{
		printf("�������������\n");
	}
	else
	{
		printf("������Ĳ�������\n");
	}

	return 0;
}