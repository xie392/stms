#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define datatype int                    // ������������
#define MAX_BUFFER_LEN  20              // ������󻺳�������
#define MAX_ADDRESS_LEN 100             // ��������ַ����

typedef struct student{
    char sno[MAX_BUFFER_LEN];           // ѧ��
    char name[MAX_BUFFER_LEN];          // ����
    datatype age;                       // ����
    char gender[2];                     // �Ա�
    char birthday[MAX_BUFFER_LEN];      // ��������
    char address[MAX_ADDRESS_LEN];      // ��ͥסַ
    char phone[MAX_BUFFER_LEN];         // �绰
    char email[MAX_BUFFER_LEN];         // ����
    datatype total;                     // ѧ������
    struct student *next;               // ָ����һ��ѧ����ָ��
} stu;

class Student {
public:
    stu *student;                       // ѧ����Ϣ
    void init();                        // ��ʼ��,��db/student.txt�ļ��е�ѧ����Ϣ��ȡ���ڴ���
    void wirteStudent(stu *student);    // д��ѧ����Ϣ
    void addStudent();                  // ���ѧ��
    void deleteStudent();               // ɾ��ѧ��
    void modifyStudent();               // �޸�ѧ��
    stu *searchStudent(char str[MAX_BUFFER_LEN]);             // ����ѧ��,��ѧ�Ż���������
    void showAllStudent();              // ��ʾѧ����Ϣ
    void menu();                        // �˵�
};

#endif //STMS_STUDENT_H
