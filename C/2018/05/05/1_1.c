#include <stdio.h>

//�ַ�����ת����
int palindrome_number(int number);

int main()
{
	int number;

	printf("������һ����\n");
	scanf("%d", &number);

	if(palindrome_number(number) == number)
	{
		printf("��������ǻ�����\n");
	}
	else
	{
		printf("������Ĳ��ǻ�����\n");
	}

	return 0;
}

int palindrome_number(int number)
{
	int number_2;

	number_2 = 0;

	while(number != 0)
	{
		number_2 = number_2*10 + number%10;
		number /= 10;
	}

	return number_2;
}