//
// Created by 26363 on 2023/6/12.
//
#include "student.h"

/**
* TODO:��ʼ��,��db/student�ļ��е�ѧ����Ϣ��ȡ���ڴ���
 * @return
*/
void init(student *s) {
    // �����ڴ�
    s = (student *) malloc(sizeof(student));

    // ��ȡ db Ŀ¼�µ� student.bin �ļ�
    FILE *fp = fopen("db/student.bin", "r");

    // ����ļ���ʧ��
    if (!fp) {
        printf("�ļ���ʧ��\n");
        return;
    }

    while (fread(s, sizeof(student), 1, fp)) {
        // ָ����һ��ѧ����ָ��
        s->next = (student *) malloc(sizeof(student));
        s = s->next;
    }

    // �ر��ļ�
    fclose(fp);
}


/**
* TODO:׷��д��ѧ����Ϣ
 * @param s   ѧ����Ϣ
 * @return
*/
void wirteStudent(student *s) {
    // д�� db Ŀ¼�µ� student �ļ�
    FILE *fp = fopen("db/student.bin", "a");

    // ����ļ���ʧ��
    if (!fp) {
        printf("�ļ���ʧ��\n");
        return;
    }

    // д���ļ�
    fwrite(s, sizeof(student), 1, fp);

    // �ر��ļ�
    fclose(fp);
}

/**
* TODO:���ѧ��
 * @return
*/
void addStudent(student *s) {
    student *temp;
    temp = (student *) malloc(sizeof(student));
    printf("������ѧ��ѧ�ţ�");
    scanf("%s", temp->sno);
    printf("������ѧ��������");
    scanf("%s", temp->name);
    printf("������ѧ�����䣺");
    scanf("%d", &temp->age);
    printf("������ѧ���Ա�");
    scanf("%s",temp->gender);
    printf("������ѧ���������ڣ�");
    scanf("%s", temp->birthday);
    printf("������ѧ����ͥסַ��");
    scanf("%s", temp->address);
    printf("������ѧ���绰��");
    scanf("%s", temp->phone);
    printf("������ѧ�����䣺");
    scanf("%s", temp->email);

    // ѧ������ + 1
    if(!s->total) {
        s->total = 1;
    } else {
        s->total++;
    }

    // ָ����һ��ѧ����ָ��
    s->next = (student *) malloc(sizeof(student));

    // д���ļ�
    wirteStudent(s);
}