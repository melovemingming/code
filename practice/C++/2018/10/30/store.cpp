// store.cpp
#include "pch.h"
#include "store.h"

/*���캯��*/
Node::Node(){
	this->next = NULL;
	Elemtype::setAge(0);
	Elemtype::setMajor("NULL");
	Elemtype::setName("NULL");
	Elemtype::setNum("NULL");
	Elemtype::setRegissterYear(0);
}

/*ѧ��*/
int Elemtype::setNum(string num)
{
	this->num = num;
	return 0;
}

string Elemtype::getNum(){
	return this->num;
}

/*����*/
int Elemtype::setName(string name)
{
	this->name = name;
	return 0;
}

string Elemtype::getName()
{
	return this->name;
}

/*����*/
int Elemtype::setAge(int age)
{
	this->age = age;
	return 0;
}

int Elemtype::getAge()
{
	return this->age;
}

/*רҵ*/
int Elemtype::setMajor(string major)
{
	this->major = major;
	return 0;
}

string Elemtype::getMajor()
{
	return this->major;
}

/*��ѧ���*/
int Elemtype::setRegissterYear(int regissterYear)
{
	this->regissterYear = regissterYear;
	return 0;
}

int Elemtype::getRegissterYear()
{
	return this->regissterYear;
}


