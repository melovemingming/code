#pragma once
// store.h ����Ľṹ��
#include "typeRedefinition.h"
#define Node_Length 20

/*��������Ĵ���ṹ*/
class Elemtype {
private:
	string num;	// ѧ��
	string name;	// ����
	int age;	// ����
	string major;	// רҵ
	int regissterYear;	// ��ѧ���
public:
	int setNum(string num);
	string getNum();
	int setName(string name);
	string getName();
	int setAge(int age);
	int getAge();
	int setMajor(string major);
	string getMajor();
	int setRegissterYear(int regissterYear);
	int getRegissterYear();
};

/*�ڵ�*/
class Node: public Elemtype{
public:
	Node* next = NULL;
	Node();
};