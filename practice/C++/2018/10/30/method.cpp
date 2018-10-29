// method.cpp ������
#include "pch.h"
#include "method.h"

/*���캯��*/
list::list() {
	this->createList();
}

/*��������*/
list::~list() {
	this->destroyList();
}

/*��������*/
int list::createList() {
	Node* head = new Node();	// ����ͷ�ڵ�
	this->head = head;
	try {
		if (head == NULL) {
			exit(-2);
		}
	}catch (const string msg) {
		this->error = msg;
		return -1;
	}

	// ά�����Ա���
	this->length = 0;

	return 0;
}

/*���������*/
int list::getLength()
{
	Node* p;
	int i = 0;	// ͷ�ڵ�Ϊ0 ���β��ϵ�������һ���洢�����ݵĽڵ�Ϊ1
	
	// ����0�ڵ������
	if (this->length == 0)
		return 0;
	
	p = this->head->next;

	while (p != NULL) {
		i++;
		p = p->next;
	}

	try {
		if (i != this->length) {
			exit(-3);
		}
	}catch (const string msg) {
		this->error = msg;
		this->length = 0;
		return 0;
	}

	return this->length;
}

/*�������*/
// ����ȡ�����Ա�Ľ��������result�ַ�����
list* list::getList() {
	Node* p;
	if (this->length == 0)
		return this;

	p = this->head->next;	// ָ���һ��ӵ�����ݵĽڵ�

	for (int index = 1; index <= this->getLength(); index++) {
		// ���ڵ�һ���ڵ�Ϊ�սڵ㣬����index�ĳ�ֵΪ1
		/*����ڵ����*/
		this->result += "\n�ڵ����\t" + to_string(index) + "\n";
		this->result += "���ѧ��\t" + p->getNum() + "\n";
		/*�������*/
		this->result += "�������\t" + p->getName() + "\n";
		/*�������*/
		this->result += "�������\t" + to_string(p->getAge()) + "\n";
		/*���רҵ*/
		this->result += "���רҵ\t" + p->getMajor() + "\n";
		/*�����ѧ���*/
		this->result += "��ѧ���\t" + to_string(p->getRegissterYear()) + "\n";
		/*ָ����һ���ڵ�*/
		p = p->next;
		this->result += "------------------------------------------------";
	}
	return this;
}

/*���result*/
string list::toString()
{
	return this->result;
}

// ���result�ַ���
list* list::deleteString()
{
	string msg = "";
	this->setString(msg);	// ���result����
	return this;
}
/*����result�ַ���*/
list* list::setString(string& msg)
{
	this->result = msg;
	return this;
}


/*���error*/
string list::toError()
{
	return this->error;
}

/*ͷ�巨����Ԫ��*/
list* list::insertElem_Head(Node& node){
	Node* p = NULL;
	p = this->head->next;
	node.next = p;
	this->head->next = &node;
	this->head->next;
	(this->length)++;	// ����ά��

	return this;
}

/*β�巨������Ԫ��*/
list* list::insertElem_Foot(Node& node){
	Node* p = this->head;	// ָ��ͷ���
	for (int i = 1; i <= this->length; i++) {
		p = p->next;
	}
	// ���в���
	p->next = &node;	// ����ָ��
	p = p->next;	// ָ���ƶ�
	p->next = NULL;	// ���ÿ�ֵ
	(this->length)++;

	return this;
}

/*���ݼ�ֵ����ָ���ڵ�*/
Node* list::getNumNode(const string& num){
	Node* p = this->head->next;	// ָ���һ���ڵ�
	int index = 1;	// ����Ϊ1

	// ��������
	try {
		while (p != NULL) {
			if (p->getNum() == num) {
				return p;	// �ҵ��ڵ��Ժ󷵻�һ��ָ��
			}
			// ���Խ�����
			if (index > this->length)
				exit(-4);
			// �ƶ�ָ��
			p = p->next;
			index++;
		};
	}
	catch (string msg) {
		this->error = msg;
		return this->head;
	}
	return this->head;	// δ�ҵ����ؿ�ָ��
}

/*��ȡָ��locλ�õĽڵ�*/
Node* list::getNode(const int& loc){
	// ��loc�����ж�
	try {
		if (loc < 0 || loc > this->length) {
			exit(-1);
		}
	}
	catch (const char msg) {
		this->error = msg;	// ���󴢴�
		return this->head;	// ����һ��ָ��
	}

	// ��ȡָ��λ�õĽڵ�
	Node* p = this->head;	// ͷ�ڵ�
	for (int index = 0; index < loc; index++) {
		p = p->next;	// �ƶ�ָ��
	}

	return p;
}

/*����ָ��λ�õ�Ԫ��*/
Node * list::insertLoc(Node & node, int & loc){
	node.next = this->getNode(loc + 1);
	this->getNode(loc - 1)->next = &node;
	return &node;
}

/*ɾ���ڵ�*/
list* list::deleteNode(const int& loc){
	// ��loc���д���
	try {
		if (loc < 0 || loc > this->length)
			exit(-1);
	}
	catch (string msg) {
		this->error = msg;
		return this;	
	}

	// ɾ���ڵ�
	Node* p_loc_previous = this->getNode(loc-1);	// ��ȡҪɾ���Ľڵ����һ���ڵ�
	Node* p_loc = this->getNode(loc);	// ��ȡҪɾ���Ľڵ�
	p_loc_previous->next = this->getNode(loc)->next;	// ɾ����
	delete p_loc;	// ɾ��new���Ķ��ڴ�
	p_loc = NULL;	// ����ָ��Ϊ��

	// ά������
	(this->length)--;
	return this;
}

/*����ת*/
list* list::reverse()
{
	// ʹ������ָ�룬���������������������з�ת
	// ˼·���������ָ����з���Ϊ�˷�ֹ������ѣ�ʹ��һ��ָ����б���,Ȼ���ٺ�ͷ�ڵ��������
	Node* last;
	Node* tmp;
	Node* first;
	// ���г�ʼ��
	first = this->head->next;
	last = this->head->next->next;	// ��ʱ�Ϸ���ָ��Ϊ  first->next = last

	// ��ʼ����ת
	try {
		while (last->next != NULL) {	// �����һ�������next��ֵΪNULL��ʱ����������ת���
			// �鿴�����Ƿ�����ѭ������ֹ��ѭ������
			if (this->judgingRingList())
				exit(-1);
			
			// Ϊ�˷�ֹ����ʧ�������������������tmp�ݴ�
			tmp = last->next;
			// ����first��last֮���˳��
			last->next = first;	// ע����ʱfirst->next�Ծ�ָ��last��ʱΪһ���ջ�
			// ָ�������ƶ�
			first = last;
			last = tmp;
		}
	}
	catch (string msg) {
		this->error = msg;
		return this;
	}

	// �������һ���ڵ�
	last->next = first;
	// ��ʱthis->head ָ�����������һ���ڵ�,�Լ������ĵڶ����ڵ��γɻ�
	// �� first->next = last  last -> next = first  this->head->next = first
	// �������Լ�ͷ�ڵ�
	this->head->next->next = NULL;	// ����β���ڵ�
	this->head->next = last;	//����ͷ�ڵ�

	return this;
}

/*����һ��Ϊ��*/
list* list::TwoPoints()	{
	Node* q1 = this->head;
	Node* q2 = this->head;
	
	// �ж��Ƿ�Ϊ��������
	try {
		if (this->judgingRingList())
			exit(-1);
	}
	catch (string msg) {
		this->error = msg;
		return NULL;
	}

	// ����һ��Ϊ��
	while (q2->next != NULL) {
		q1 = q1->next;	// q1��һ��
		if (q2->next == NULL)
			break;	// ѭ������ֹ
		q2 = q2->next->next;	// q2������
	}

	// q1��������ͷ���γ�һ����������,������
	q2 = (new Node())->next = q1;
	list* tmp;
	tmp = new list();
	tmp->head = q2;

	return	tmp;
}

/*�ͷŵ�����*/ 
int list::destroyList(){
	for (int index = 1; index <= this->length; index++) {
		this->deleteNode(index);
			
	}

	// ɾ��ͷ�ڵ�
	delete this->head;
	this->head = NULL;
	return 0;
}


/*�жϻ�������*/
bool list::judgingRingList(){
	Node* q1 = this->head;
	Node* q2 = this->head;
	
	while (q2->next != NULL) {
		q1 = q1->next;	// q1��һ��
		if (q2->next == NULL)
			break;	// ѭ������ֹ,֤��������
		q2 = q2->next->next;	// q2������
		
		if (q1 == q2)
			return true;	// ֤��Ϊ��������
	}
	return false;
}












