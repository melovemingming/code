#include <stdio.h>
#include "header.h"

int main(int argc, char** argv) {
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
