#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXCOUNT 50
// ����Ҫ��������Ա�
typedef struct {
    char num[20];   // ����ѧ��
    char name[20];  // ��������
    int age;    // ��������
    char major[20]; // ����רҵ
    int registerYear;   // ������ѧ���
}ElemType;

// �������Ա��������
typedef struct {
    ElemType data[MAXCOUNT];    // ��������
    int len;    // ���峤��
}SeqList;

int createList(SeqList **myList);
int listLength(const SeqList *myList);
int printfList(const SeqList *myList);
int inputList(ElemType **tmpList, int *col);
int moveList(SeqList *myList, int col, int option);
int selectList(SeqList *myList, char *key);
int infoList(SeqList *myList, int key);
int DestroyList(SeqList *myList);

int main() {
    // ����һЩ����
    int option, tmp;
    SeqList *myList; // ����һ��SeqList���͵Ŀ�ָ�룬�����������Ա�
    myList = NULL;
    char key[20];
    int num;

    // ���ѡ��
    printf("ѧ������ϵͳ����ɹ�\n");
    printf("************ѡ��*******************\n");
    printf("1 �������Ա�\n");
    printf("2 �����Ա�ĳ���\n");
    printf("3 �����ϸ��\n");
    printf("4 �����Ա��λ�ò���һ��Ԫ��\n");
    printf("5 ���ݼ�ֵ�Բ���ָ����Ԫ��\n");
    printf("6 ��ȡָ��λ�õ�Ԫ�ص���Ϣ\n");
    printf("7 ɾ��ָ��λ�õ�Ԫ��\n");
    printf("8 �ͷ����Ա�\n");
    printf("9 �˳�ϵͳ\n");
    printf("**************end!*********************\n");

    // ����ѡ�������
    // ���л����߼��Ĵ���
    while(1) {
        printf("������ѡ��\n");
        scanf("%d", &option);
        switch(option) {
            // �������Ա�
            case 1:
                tmp = createList(&myList);   // �����������������Ա�
                // ������
                if (tmp == 1) {
                    printf("�������Ա�ɹ���\n");
                } else {
                    printf("�������Ա�ʧ��!\n");
                };
                break;
            // ��ѯ���Ա�ĳ���
            case 2:
                tmp = listLength(myList);
                if (tmp == -1) {
                    printf("��ѯ���Ա���ʧ�ܣ�δָ�����Ա�\n");
                } else {
                    printf("��ѯ���Ա�ĳ���Ϊ%d\n", tmp);
                };
                break;
            // ������Ա�
            case 3:
                tmp = printfList(myList);
                if (tmp == -1)
                    printf("������Ա�ʧ�ܣ�δָ�����Ա�\n");
                else
                    printf("������Ա�����\n");
                break;
             // �������Ա�
             case 4:
                tmp = insterList(myList);
                if (tmp == -1)
                    printf("�������Ա�ʧ��\n");
                else
                    printf("�������Ա�ɹ�\n");
                break;
            case 5:
                // ���ݼ�ֵ��������ֵ
                printf("�������ֵ,��ѧ��\n");
                fflush(stdin);
                gets(key);
                fflush(stdin);
                tmp = selectList(myList, key);
                if (tmp == -1)
                    printf("���Ҵ���\n");
                else if (tmp >= listLength(myList))
                    printf("δ�ҵ���");
                else
                    printf("����ֵΪ %d\n", tmp);
                break;
            case 6:
                // ��������ֵ���Ҽ�ֵ
                printf("����������ֵ\n");
                scanf("%d", &num);
                tmp = infoList(myList, num);
                if (tmp == -1) {
                    printf("����ʧ��\n");
                } else {
                    printf("�������Ϣ����\n");
                }
                break;
            case 7:
                // ���ݼ�ֵɾ����Ӧ������
                tmp = deleteList(myList);
                if (tmp == -1)
                    printf("ɾ��ʧ��\n");
                else
                    printf("ɾ���ɹ�");
                break;
            case 8:
                tmp = DestroyList(myList);
                if (tmp == -1) {
                    printf("�ͷ�ʧ��\n");
                } else {
                    printf("�ͷųɹ�\n");
                }
                break;
            case 9:
                return 0;
            default:
                printf("��������д�������������");
                break;
        }
    }
    return 0;
}

/*
 * �������Ա�
*/
// in �����ָ�� out ���Ա���׵�ַ
int createList(SeqList **myList) {
     *myList = (SeqList *)malloc(sizeof(SeqList));    // ����һ�鴢��ռ�
    if (*myList == NULL) {
        return -1;   // ��������ռ�ʧ��
    } else {
        return 1;   // ��������ռ�ɹ�
    }
}

/*
 * �����Ա���,
*/
// in ���Ա� out ����
int listLength(const SeqList *myList) {
    // δ�������Ա�
    if (myList == NULL)
        return -1;
    // �������Ա�
    return myList -> len;
};

/*
 * ������Ա�
*/
// in ���Ա� out ���Ա������
int printfList(const SeqList *myList) {
    int i, len;
    // �ж��Ƿ�Ϊ��ָ��
    if (myList == NULL)
        return -1;
    // ��ȡ���Ա���
    len = myList -> len;
    if (len == 0) {
        printf ("����������Ա�Ϊ��\n");
        return 1;
    }
    // ������Ա�
    for (i = 0; i < len; i++) {
        printf("�����%d������\n", i + 1);
        printf("ѧ�� = %s\n", myList->data[i].num);
        printf("���� = %d\n", myList ->data[i].age);
        printf("רҵ = %s\n", myList ->data[i].major);
        printf("���� = %s\n", myList ->data[i].name);
        printf("��ѧ��� = %d\n", myList ->data[i].registerYear);
    }
    printf("���Ա�����ɹ�\n");
    return 1;
}


/*
 * �����Ա��ָ��λ�ò���
*/
// in ���Ա� out ���
int insterList(SeqList *myList) {
    int tmp, col;
    ElemType *tmpList = NULL;
    // �жϴ����ַ�Ƿ�Ϊ��
    if (myList == NULL) {
        return -1;
    }
    /*
     * ���в���
     */
    // ��ȡ�û�����
    tmp = inputList(&tmpList, &col);
    // �ж��Ƿ��ȡ�ɹ�
    if (tmp == -1)
        return -1;
    // ���в������
    // ���ú������������ƶ�
    tmp = moveList(myList, col, 1);    // 1��������ƶ�  0 ��ǰ�ƶ�
    // �жϻ�ȡ���
    if (tmp == -1) {
        return -1;
    }
    // ��ֵ����
    myList->data[col-1] = *tmpList;
    // ά������
    (myList ->len)++;
    // �ͷŴ���ռ�
    free(tmpList);
    // ���ÿ�ָ��
    tmpList = NULL;
    return 1;
}
// ��ȡ�û�����Ҫ�������Ա����Ϣ
// in �������Ϣ �����λ�� out ���
int inputList(ElemType **tmpList, int *col) {
    // ���봢����ڴ�ռ�
    *tmpList = (ElemType *)malloc(sizeof(ElemType));
    if (*tmpList == NULL){
        printf("�ռ䲻�㣬�޷�����\n");
        return -1;
    }
    // ��ȡ�û���Ҫ���������
    fflush(stdin);
    printf("������ѧ��\n");
    gets(((*tmpList) ->num));
    fflush(stdin);
    printf("����������\n");
    gets((*tmpList) ->name);
    fflush(stdin);
    printf("����������\n");
    scanf("%d",&((*tmpList) ->age));
    fflush(stdin);
    printf("����������רҵ\n");
    gets((*tmpList)->major);
    fflush(stdin);
    printf("��������ѧ���\n");
    scanf("%d", &((*tmpList)->registerYear));
    fflush(stdin);
    printf("������Ҫ�����λ��\n");
    scanf("%d", col);
    fflush(stdin);
    return 1;   // ��ȡ�û��������Ϣ���
}

// �ƶ����Ա���
// ����option��1�����ƶ���0��ǰ�ƶ� col ΪҪ�����λ�ã���1��ʼ
int moveList(SeqList *myList, int col, int option) {
    int i;
    // �жϴ�������Ա��Ƿ�Ϊ��
    if (myList == NULL) {
        printf ("���Ա�Ϊ��\n");
        return -1;
    }
    // �ж����Ա��Ƿ�����
    if (listLength(myList) >= MAXCOUNT) {
        printf("���Ա��������޷����룬��ɾ�������\n");
        return -1;
    }
    // �ж�col�Ƿ�Խ�磬�������Ա�����
    if ((col > listLength(myList) && col - listLength(myList) != 1 ) || col < 1) {
        printf("����Ĳ���λ�ô�����ȷ�Ϻ����²���\n");
        return -1;
    }
   // �ж�ǰ�ƻ��Ǻ���
   switch(option) {
        case 1:
            // ���Ա������ƶ�
           // �ƶ����Ա�
           col--;
           for(i = listLength(myList); i >= col; i--) {
               myList ->data[i] = myList ->data[i-1];
           };
           break;
        case 0:
            // ���Ա���ǰ�ƶ�
            col--;
            for(i = col; i < listLength(myList); i++) {
                myList ->data[i] = myList ->data[i+1];
            }
            break;
       default:
           printf("�����ѡ�ʹ���\n");
           return -1;
    }
    return 1;
}

// ���ݼ�ֵ�������Ա�
int selectList(SeqList *myList, char * key) {
    if (myList == NULL) {
        return -1;
    }
    int i;
    // ���б�������
    for (i = 0; i< listLength(myList); i++) {
        if (strcmp(myList ->data[i].num, key) == 0) {
            break;
        }
    }
    return i;
}

// ��ȡָ��λ�õ�Ԫ����Ϣ
int infoList(SeqList *myList, int key) {
    if (myList == NULL) {
        return -1;
    }
    // ��������key
    if (key > listLength(myList) || key < 0) {
        return -1;  // �������������
    }

    // ���ֵ��Ӧ��ѧ��
    printf("ѧ�� = %s\n", myList ->data[key].num);
    return 1;
}

// ɾ��Ԫ��
int deleteList(SeqList *myList) {
    char num[20];
    int tmp;
    // ���myList�Ƿ�Ϊ��
    if (myList == NULL) {
        return -1;
    }
    // ��ȡҪɾ����ѧ��
    printf("������Ҫɾ����ѧ��\n");
    fflush(stdin);
    gets(num);
    // ���Ҷ�Ӧ������ֵ
    tmp = selectList(myList, num);
    if (tmp == -1) {
        return -1;
    }
    // ��ǰ�ƶ�
    tmp = moveList(myList, tmp, 1);
    if (tmp == -1) {
        return -1;
    }
    return 1;
}

// �ͷ����Ա�
int DestroyList(SeqList *myList) {
    if (myList == NULL) {
        return -1;
    }
    free(myList);
    return 1;
}