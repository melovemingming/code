#include <stdio.h>
#include <math.h>

int main()
{
	int number, originalNumber;
	int result, residue;
	int i;

	printf("������һ����λ����\n");
	scanf("%d", &number);

	originalNumber = number;
	result = 0;
	residue = 0;
	i = 0;

	// �ж��ж���λ
	while(number != 0)
	{
		number /= 10;
		i++;
	}

	// �ָ�number������������ĳ���
	number = originalNumber;

	// ��������İ�ķ˹����������ɺ�Ľ��
	while(number != 0)
	{
		residue = number % 10;
		result += pow(residue, i);
		number /= 10;
	}

	// ���������ж�
	if(result == originalNumber)
	{
		printf("������� %d �ǰ�ķ˹׳��\n", originalNumber);
	}
	else
	{
		printf("������� %d ���ǰ�ķ˹׳��\n", originalNumber);
	}

	return 0;
}