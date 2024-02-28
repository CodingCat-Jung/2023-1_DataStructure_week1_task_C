#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#pragma warning (disable :4996)

int count = 0;

typedef struct student {
    int number;
    char name[10];
    float total;
}stu;

typedef struct NODE {
    stu data;
    struct NODE* link;
}node;

node* insert(node* head, stu data) {
    node* p = (node*)malloc(sizeof(node)); //���� �޸� �Ҵ��� �̿��ؼ� ���ο� ��� p�� ����
    p->data.number = data.number;
    strcpy(p->data.name, data.name);
    p->data.total = data.total;
    p->link = head; //��� �������� ���� ������
    head = p; //��� ������ ����
    return head;
}

void total_change(node* head) {

    stu temp;

    for (node* p = head; p->link != NULL; p = p->link)
    {
        for (node* q = p->link; q != NULL; q = q->link) //p->link�� null�� �ƴϾ����
        {
            if (p->data.total > q->data.total)
            {
                temp.total = p->data.total;
                p->data.total = q->data.total;
                q->data.total = temp.total;

                temp.number = p->data.number;
                p->data.number = q->data.number;
                q->data.number = temp.number;

                strcpy(temp.name, p->data.name);
                strcpy(p->data.name, q->data.name);
                strcpy(q->data.name, temp.name);
            }
        }
    }

    for (node* p = head; p != NULL; p = p->link)
    {
        printf("�й�: %d, �̸�: %s, ����: %f\n", p->data.number, p->data.name, p->data.total);
    }

}

void number_change(node* head) {

    stu temp;

    for (node* p = head; p->link != NULL; p = p->link)
    {
        for (node* q = p->link; q != NULL; q = q->link)
        {
            if (p->data.number > q->data.number)
            {
                temp.total = p->data.total;
                p->data.total = q->data.total;
                q->data.total = temp.total;

                temp.number = p->data.number;
                p->data.number = q->data.number;
                q->data.number = temp.number;

                strcpy(temp.name, p->data.name);
                strcpy(p->data.name, q->data.name);
                strcpy(q->data.name, temp.name);
            }
        }
    }

    for (node* p = head; p != NULL; p = p->link) {
        printf("�й�: %d, �̸�: %s, ����: %f\n", p->data.number, p->data.name, p->data.total);
    }
}

void name_change(node* head) {

    stu temp;

    for (node* p = head; p->link != NULL; p = p->link)
    {
        for (node* q = p->link; q != NULL; q = q->link)
        {
            if (strcmp(p->data.name, q->data.name) > 0)
            {
                temp.total = p->data.total;
                p->data.total = q->data.total;
                q->data.total = temp.total;

                temp.number = p->data.number;
                p->data.number = q->data.number;
                q->data.number = temp.number;

                strcpy(temp.name, p->data.name);
                strcpy(p->data.name, q->data.name);
                strcpy(q->data.name, temp.name);
            }
        }
    }

    for (node* p = head; p != NULL; p = p->link) {
        printf("�й�: %d, �̸�: %s, ����: %f\n", p->data.number, p->data.name, p->data.total);
    }

}

int main() {
    FILE* fp = NULL;
    char c_tem[10];
    int n = 0;

    stu test;
    stu* s;

    node* head = NULL;
    stu temp; // �ӽ� ������ ���� ���� ���� ���x

    if ((fp = fopen("data.txt", "r")) == NULL)
        printf("���� ���� ����\n");

    while (!feof(fp)) {
        fscanf(fp, "%d %s %f", &temp.number, c_tem, &temp.total);
        count++;
    }

    rewind(fp); //���������͸� �� ������ �ű�
    s = (stu*)malloc(sizeof(stu) * count); //���� ������ ������ŭ �����Ҵ�

    while (!feof(fp)) {
        fscanf(fp, "%d %s %f", &test.number, c_tem, &test.total);
        strcpy(test.name, c_tem);
        head = insert(head, test);
        printf("%d %s %f\n", test.number, test.name, test.total);
    }
    printf("\n");


    printf("\n");
    printf("���� ���� ������ ����(��������)\n");
    total_change(head);

    printf("\n");
    printf("�й� ���� ������ ����(��������)\n");
    number_change(head);

    printf("\n");
    printf("�̸� ���� ������ ����(��������)\n");
    name_change(head);

    free(s); // �޸� ���� ����(�����Ҵ�)
    fclose(fp);
    return 0;
}