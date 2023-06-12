//
// Created by 26363 on 2023/6/12.
//

#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <cstdlib>
#include <iostream>
using namespace std;

#define datatype int                    // ������������

typedef struct student{
    string sno;                         // ѧ��
    string name;                        // ����
    datatype age;                       // ����
    string gender;                      // �Ա�
    string birthday;                    // ��������
    string address;                     // ��ͥסַ
    string phone;                       // �绰
    string email;                       // ����
    datatype total;                     // ѧ������
    struct student *next;               // ָ����һ��ѧ����ָ��
} stu;

class Student {
public:
    stu *student;                               // ѧ����Ϣ
    void init();                                // ��ʼ��,��db/student.txt�ļ��е�ѧ����Ϣ��ȡ���ڴ���
    void wirteStudent(stu *student);            // д��ѧ����Ϣ
    void addStudent();                    // ���ѧ��
    void deleteStudent();                       // ɾ��ѧ��
    void modifyStudent();                       // �޸�ѧ��
    stu *searchStudent(const string& str);      // ����ѧ��,��ѧ�Ż���������
    void showAllStudent();                      // ��ʾѧ����Ϣ
    void menu();                                // �˵�
};

#endif //STMS_STUDENT_H
