//
// Created by 26363 on 2023/6/12.
//
#include "student.h"
namespace std

/**
 * TODO:��ʼ��,��db/student.txt�ļ��е�ѧ����Ϣ��ȡ���ڴ���
 * @return
 */
 void Student::init(){
    FILE *fp = fopen("db/student.txt", "r");
 }

/**
 * TODO:д��ѧ����Ϣ
 * @param student   ѧ����Ϣ
 * @return
 */
void Student::wirteStudent(stu *student) {
    // д�� db Ŀ¼�µ� student.txt �ļ�
    FILE *fp = fopen("db/student.txt", "a");

    if (fp == NULL) {
        std::cout << "�ļ���ʧ��" << std::endl;
        return;
    }

    // ��ѧ����Ϣд���ļ�

}

/**
* ���ѧ��
 * @return
 */
void Student::addStudent() {
    std::cout << "������ѧ����Ϣ" << std::endl;
    std::cout << "������ѧ�ţ�";
    std::cin >> student->sno;
    std::cout << "������������";
    std::cin >> student->name;
    std::cout << "���������䣺";
    std::cin >> student->age;
    std::cout << "�������Ա�";
    std::cin >> student -> gender;
    std::cout << "������������ڣ�";
    std::cin >> student->birthday;
    std::cout << "�������ͥסַ��";
    std::cin >> student->address;
    std::cout << "������绰��";
    std::cin >> student->phone;
    std::cout << "���������䣺";
    std::cin >> student->email;

    student -> total++;

    // TODO:д�� db Ŀ¼�µ� student.txt �ļ�

    // ָ����һ��ѧ����ָ��
    student -> next = (stu *) malloc(sizeof(stu));
}

/**
 * ɾ��ѧ��
 * @return
 */
void Student::deleteStudent() {
    std::cout << "������Ҫɾ����ѧ��ѧ�ţ�";
    std::string sno;
    std::cin >> sno;

    // ����ѧ��
    stu *p = searchStudent(sno);

}

/**
 * �޸�ѧ��
 * @return
 */
void Student::modifyStudent() {}

/**
 * ����ѧ��
 * @return
 */
stu *Student::searchStudent(char str[MAX_NAME_LEN]) {
    stu *pre = NULL, *p;
    if(!student) {
        std::cout << "ѧ����ϢΪ��" << std::endl;
        return student;
    }

    p = student;

    // ��������,����ѧ��
    while (p && p->sno != str || p->name != str) {
        pre = p;
        p = p->next;
    }

    if (!p) {
        std::cout << "û���ҵ�ѧ��,��������ѧ���Ƿ���ȷ" << std::endl;
        return student;
    }

    // ���Ҫɾ����ѧ���ǵ�һ��ѧ��
    if(!pre) {
        student = p->next;
    } else {
        pre->next = p->next;
    }

    free(p);

    return student;

}

/**
 * ��ʾ����ѧ��
 * @return
 */
void Student::showAllStudent() {}


/**
* �˵�
 * @return
 */
void Student::menu() {
    while (1) {
        std::cout << "========================= ѧ������ϵͳstart ==========================" << std::endl;
        std::cout << "1. ���ѧ��" << std::endl;
        std::cout << "2. ɾ��ѧ��" << std::endl;
        std::cout << "3. �޸�ѧ��" << std::endl;
        std::cout << "4. ����ѧ��" << std::endl;
        std::cout << "5. ��ʾ����ѧ��" << std::endl;
        std::cout << "0. �˳�" << std::endl;
        std::cout << "========================= ѧ������ϵͳend ==========================" << std::endl;
        std::cout<< std::endl;

        int choice;
        std::cout << "���������ѡ��";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                modifyStudent();
                break;
            case 4:
                searchStudent();
                break;
            case 5:
                showAllStudent();
                break;
            case 0:
                exit(0);
            default:
                std::cout << "�����������������" << std::endl;
                break;
        }
    }
}