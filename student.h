//
// Created by 26363 on 2023/6/12.
//

#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <stdlib.h>
#include <iostream>

#define MAX_NAME_LEN 20                 // ������󳤶�
#define MAX_BIRTHDAY_LEN 20             // ����������󳤶�
#define MAX_ADDRESS_LEN 100             // ��ͥסַ��󳤶�
#define MAX_PHONE_LEN 20                // �绰��󳤶�
#define MAX_EMAIL_LEN 20                // ������󳤶�

#define datatype int                    // ������������

typedef struct student{
    datatype sno;                       // ѧ��
    char name[MAX_NAME_LEN];            // ����
    datatype age;                       // ����
    char gender[2];                     // �Ա�
    char birthday[MAX_BIRTHDAY_LEN];    // ��������
    char address[MAX_ADDRESS_LEN];      // ��ͥסַ
    char phone[MAX_PHONE_LEN];          // �绰
    char email[MAX_EMAIL_LEN];          // ����
    datatype total;                     // ѧ������
    struct student *next;               // ָ����һ��ѧ����ָ��
} stu;

class Student {
public:
    stu *student = (stu *) malloc(sizeof(stu));
    void init();                        // ��ʼ��,��db/student.txt�ļ��е�ѧ����Ϣ��ȡ���ڴ���
    void wirteStudent(stu *student);    // д��ѧ����Ϣ
    void addStudent();                  // ���ѧ��
    void deleteStudent();               // ɾ��ѧ��
    void modifyStudent();               // �޸�ѧ��
    stu *searchStudentSno(datatype sno);// ����ѧ��,��ѧ�Ų���
    stu *searchStudentName(char name[MAX_NAME_LEN]);    // ����ѧ��,����������
    void showAllStudent();              // ��ʾ����ѧ��
    void menu();                        // �˵�
};

#endif //STMS_STUDENT_H
