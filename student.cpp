//
// Created by 26363 on 2023/6/12.
//
#include "student.h"

/**
 * TODO:��ʼ��,��db/student.txt�ļ��е�ѧ����Ϣ��ȡ���ڴ���
 * @return
 */
void Student::init() {
    student = (stu *) malloc(sizeof(stu));
//    // ��ȡ db Ŀ¼�µ� student.txt �ļ�
    FILE *fp = fopen("db/student.txt", "r");

    if (fp == nullptr) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }
}

/**
 * TODO:д��ѧ����Ϣ
 * @param s   ѧ����Ϣ
 * @return
 */
void Student::wirteStudent(stu *s) {
    // д�� db Ŀ¼�µ� student.txt �ļ�
    FILE *fp = fopen("db/student.txt", "a");

    if (fp == nullptr) {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    // TODO: ��ѧ����Ϣд���ļ�
    fwrite(s, sizeof(stu), 1, fp);
}

/**
* ���ѧ��
 * @return
 */
void Student::addStudent() {
    cout << "������ѧ�ţ�";
    cin >> student->sno;
    cout << "������������";
    cin >> student->name;
    cout << "���������䣺";
    cin >> student->age;
    cout << "�������Ա�";
    cin >> student->gender;
    cout << "������������ڣ�";
    cin >> student->birthday;
    cout << "�������ͥסַ��";
    cin >> student->address;
    cout << "������绰��";
    cin >> student->phone;
    cout << "���������䣺";
    cin >> student->email;

    // ѧ������ + 1
    student->total++;

    // TODO:д�� db Ŀ¼�µ� student.txt �ļ�
    wirteStudent(student);

    // ָ����һ��ѧ����ָ��
    student->next = (stu *) malloc(sizeof(stu));
}

/**
 * ɾ��ѧ��
 * @return
 */
void Student::deleteStudent() {
    cout << "������Ҫɾ����ѧ��ѧ�ţ�";
    string sno;
    cin >> sno;

    // ����ѧ��
    stu *p = searchStudent(sno);

    if (p) {
        cout << "����ѧ����" << p->sno << p->name << endl;
    }

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
stu *Student::searchStudent(const string &str) {
    stu *pre = nullptr, *p;
    if (!student) {
        cout << "ѧ����ϢΪ��" << endl;
        return student;
    }

    p = student;

    // ��������,����ѧ��
    while (p && (p->sno != str || p->name != str)) {
        pre = p;
        p = p->next;
    }

    if (!p) {
        cout << "û���ҵ�ѧ��,��������ѧ���Ƿ���ȷ" << endl;
        return student;
    }

    // ���Ҫɾ����ѧ���ǵ�һ��ѧ��
    if (!pre) {
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
    init();
    while (true) {
        cout << "========================= ѧ������ϵͳstart ==========================" << endl;
        cout << "1. ���ѧ��" << endl;
        cout << "2. ɾ��ѧ��" << endl;
        cout << "3. �޸�ѧ��" << endl;
        cout << "4. ����ѧ��" << endl;
        cout << "5. ��ʾ����ѧ��" << endl;
        cout << "0. �˳�" << endl;
        cout << "========================= ѧ������ϵͳend ==========================" << endl;
        cout << endl;

        int choice;
        cout << "���������ѡ��";
        cin >> choice;

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
//                searchStudent();
                break;
            case 5:
                showAllStudent();
                break;
            case 0:
                exit(0);
            default:
                cout << "�����������������" << endl;
                break;
        }
    }
}


