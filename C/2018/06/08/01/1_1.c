#include <stdio.h>
#include <math.h>

// �ṹ����
// ����һ����
typedef struct 
{
	double x;
	double y;
}spot;
// ����һ��Բ
typedef struct 
{
	spot center;	// Բ��
	double r;	// �뾶
}circle;

// ��������
int read(spot *p_coordinate, circle *p_cir);	// ��ȡԲ�͵�
int point_garden(spot coordinate, circle cir);	// �ж�һ�����Ƿ���һ��԰��
double computational_distance(spot coordinate, circle cir);	// ����Բ�͵�֮��ľ���
double distance(circle cir1, circle cir2);	// ��������Բ���뺯��
double two_point_distance(spot coordinate1, spot cordinate2);	// �����������

int main() {
	spot coordinate;	// ����
	circle cir1,cir2;	// Բ
	int result;	// ������

	// �ж�һ�����Ƿ���һ��Բ��
	printf("��ʼ�жϵ��Ƿ���԰��\n");
	read(&coordinate, &cir1);	// ��ȡԲ������͵������
	result = point_garden(coordinate, cir1);	// �����ж�
	// ����жϽ��
	if(result == 1)
		printf("����Բ��\n");
	else if(result == 0)
		printf("����Բ��\n");
	else if(result == -1)
		printf("����Բ��\n");
	else
		printf("���Բ���غ�\n");

	// ����һ������һ��Բ֮��ľ���
	printf("��ʼ������Բ�ľ���\n");
	read(&coordinate, &cir1);	// ��ȡԲ������͵������
	printf("���Բ�ľ���Ϊ %lf\n", computational_distance(coordinate, cir1));	// ������Բ�ľ��벢������

	// ��������Բ֮��ľ���
	printf("��ʼ��������Բ�ľ���\n");
	read(&coordinate, &cir1);	// ��ȡ��һ��Բ
	read(&coordinate, &cir2);	// ��ȡ�ڶ���Բ
	printf("����Բ֮��ľ���Ϊ %lf\n", distance(cir1, cir2));	// ��������Բ�ľ��벢������

	return 0;
}

// ��ȡ�����Բ
// ���� ������� Բ��Բ�İ뾶 double
// ���� �ɹ�ִ�нṹ0 int
int read(spot *p_coordinate, circle *p_cir)
{
	printf("���������\n");
	printf("�������ĺ�����\n");
	scanf("%lf", &p_coordinate->x);
	printf("��������������\n");
	scanf("%lf", &p_coordinate->y);

	printf("���濪ʼ������Բ\n");
	printf("��������Բ��\n");
	printf("����Բ�ĵĺ�����\n");
	scanf("%lf", &p_cir->center.x);
	printf("����Բ�ĵ�������\n");
	scanf("%lf", &p_cir->center.y);
	printf("��������뾶\n");
	scanf("%lf", &p_cir->r);

	return 0;
}

// �ж�һ�����Ƿ���һ��Բ��
// ����һ���� һ��Բ double
// ���� �жϵĽ��
int point_garden(spot coordinate, circle cir)
{
	double result;

	result = two_point_distance(coordinate, cir.center);

	if(result > cir.r)
		return 1;	// ����Բ��
	else if(result == cir.r)
		return 0;	// ����Բ��
	else if(result == 0.0)
		return -2;	// ����Բ��
	else
		return -1;	// ����Բ��

}

// ������Բ�ľ���
// ���� �� Բ
// ��� �жϽ��
double computational_distance(spot coordinate, circle cir)
{
	double result;

	result = point_garden(coordinate, cir);	// �жϵ��Բ�Ĺ�ϵ
	if(result == 1)	// ����Բ��
	{
		return two_point_distance(coordinate, cir.center);
	}
	else if(result == 0)	// ����Բ��
	{
		return cir.r;
	}
	else if(result == -2)	// ���Բ���غ�
	{
		return cir.r;
	}
	else	// ����Բ��
	{
		return cir.r - two_point_distance(coordinate, cir.center);
	}
}

// ��������Բ֮��ľ���
// ��������Բ
// �������Բ�ľ���
double distance(circle cir1, circle cir2)
{
	double dis;
	dis = two_point_distance(cir1.center, cir2.center);

	if(dis > (cir1.r + cir2.r))	// ��Բ����
	{
		return dis - cir1.r - cir2.r;
	}
	else if(dis == (cir1.r + cir2.r))	// ��Բ���У�����
	{
		return 0;
	}
	else 	// ��Բ�ں�
	{
		return fabs(cir1.r - cir2.r);
	}
}

// ��������ľ���
double two_point_distance(spot coordinate1, spot cordinate2)
{
	double x, y;
	x = coordinate1.x - cordinate2.x;
	y = coordinate1.y - cordinate2.y;
	return sqrt(pow(x,2) + pow(y,2));
}