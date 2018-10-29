#pragma once
#include "store.h"
// method.h ������
// 0 �Žڵ�Ϊͷ�ڵ� 1�Žڵ㿪ʼ�洢����
class list {
public: 
	list();	// ���캯��
	~list();	// ��������
	int getLength();	// ���������
	list* getList(); // �������
	string toString();	// ���result�ַ���
	list* deleteString();	// ���result�ַ�����������ָ������ָ��
	list* setString(string& msg);	// ����result�ַ���
	string toError();	// ���error
	list* insertElem_Head(Node& node);	// ͷ�巨������Ԫ��
	list* insertElem_Foot(Node& node);	// β�巨������Ԫ��
	Node* getNumNode(const string& num);	// ���ݼ�ֵ����ָ���ڵ�,����ָ��ýڵ��ָ��
	Node* getNode(const int& loc);	// ��ȡָ��loc�Ľڵ㣬����ָ��ýڵ��ָ��
	Node* insertLoc(Node& node, int& loc);	// ����ָ��λ�õ�Ԫ��
	list* deleteNode(const int& loc);	// ɾ���ڵ�
	list* reverse();	// ��ת����
	list* TwoPoints();	// ����һ��Ϊ�������صڶ��������ͷ
private:
	Node* head;	// ����ͷ���
	int length=NULL;	// ����ĳ���
	string result = "";	// ��ʱ������
	string error;	// �������
	bool judgingRingList();	// �жϻ�������
	int createList();	// ��������
	int destroyList();	// �ͷ����Ա�
};