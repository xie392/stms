//
// Created by 26363 on 2023/6/12.
//
#include "student.h"
#include <cstdlib>
#include <fstream>
#include <string.h>
#include "model.cpp"

Model model("db/student.bin");

/**
 * ��ʼ��,��db/student�ļ��е�ѧ����Ϣ��ȡ���ڴ���
 * @return
 */
void Student::init()
{
    // ��ȡ db Ŀ¼�µ� student.bin �ļ�
    fstream fp;
    fp.open("db/student.bin", ios::in | ios::binary);

    // ͷָ��ָ������ĵ�һ���ڵ�
    stu *head = NULL;

    while (fp && fp.read((char *)student, sizeof(stu)))
    {
        // ����һ���µĽڵ�
        stu *new_student = new stu;
        // ����ȡ�����ݴ洢���½ڵ���
        memcpy(new_student, student, sizeof(stu));

        // ����ǵ�һ��ѧ��
        if (!head)
        {
            head = new_student;
        }
        else
        {
            // ������ӵ�����ĩβ
            stu *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = new_student;
        }
    }

    // ��ͷָ�븳ֵ����Ա����
    student = head;

    // �ر��ļ�
    fp.close();
}

/**
 * TODO:׷��д��ѧ����Ϣ
 * @param s   ѧ����Ϣ
 * @return
 */
void Student::wirteStudent(stu *s)
{
    // д�� db Ŀ¼�µ� student �ļ�
    fstream fp;

    // �Զ����Ʒ�ʽ���ļ�
    fp.open("db/student.bin", ios::out | ios::app | ios::binary);

    // ����ļ���ʧ��
    if (!fp)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    // д���ļ�
    fp.write((char *)s, sizeof(stu));

    // �ر��ļ�
    fp.close();
}

/**
 * ���ѧ��
 * @return
 */
void Student::addStudent()
{
    // Ϊ�µ�ѧ�������ڴ�
    stu *s;
    s = (stu *)malloc(sizeof(stu));

    cout << "������ѧ�ţ�";
    cin >> s->sno;

    stu *p = searchStudent(s->sno);
    if (p)
    {
        cout << "ѧ���Ѵ���" << endl;
        return;
    }

    cout << "������������";
    cin >> s->name;
    cout << "���������䣺";
    cin >> s->age;
    cout << "�������Ա�";
    cin >> s->gender;
    cout << "������������ڣ�";
    cin >> s->birthday;
    cout << "�������ͥסַ��";
    cin >> s->address;
    cout << "������绰��";
    cin >> s->phone;
    cout << "���������䣺";
    cin >> s->email;

    s->total = s->total ? s->total + 1 : 1;

    // ����ǵ�һ��ѧ��
    if (!student)
    {
        student = s;
    }
    else
    {
        // ָ����һ��ѧ����ָ��
        student->next = s;
    }

    // TODO:д�� db Ŀ¼�µ� student.bin �ļ�
    wirteStudent(s);

    // �ͷ��ڴ�
    free(s);
}

/**
 * ɾ��ѧ��
 * @return
 */
void Student::deleteStudent()
{
    cout << "������Ҫɾ����ѧ��ѧ�ţ�";
    char sno[MAX_BUFFER_LEN];
    cin >> sno;

    // ����ѧ��
    stu *p = searchStudent(sno);

    if (!p)
    {
        cout << "û�и�ѧ��" << endl;
    }

    // ����ǵ�һ��ѧ��
    if (p == student)
    {
        student = student->next;
    }
    else
    {
        stu *pre = student;
        while (pre->next != p)
        {
            pre = pre->next;
        }
        pre->next = p->next;
    }
}

/**
 * �޸�ѧ��
 * @return
 */
void Student::modifyStudent()
{
    cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�";
    char sno[MAX_BUFFER_LEN];
    cin >> sno;

    // ����ѧ��
    stu *p = searchStudent(sno);

    if (!p)
    {
        cout << "ѧ�Ų�����" << endl;
        return;
    }

    // ���ѧ����Ϣ
    cout << "   ѧ��   " << p->sno;
    cout << "   ����   " << p->name;
    cout << "   ����   " << p->age;
    cout << "   �Ա�   " << p->gender;

    while (true)
    {
        cout << "��ѡ����Ҫ�޸ĵ���Ϣ��" << endl;
        cout << "1.����" << endl;
        cout << "2.����" << endl;
        cout << "3.�Ա�" << endl;
        cout << "4.��������" << endl;
        cout << "5.��ͥסַ" << endl;
        cout << "6.�绰" << endl;
        cout << "7.����" << endl;
        cout << "0.�˳��޸�" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "������������";
            cin >> p->name;
            break;
        case 2:
            cout << "���������䣺";
            cin >> p->age;
            break;
        case 3:
            cout << "�������Ա�";
            cin >> p->gender;
        case 4:
            cout << "������������ڣ�";
            cin >> p->birthday;
        case 5:
            cout << "�������ͥסַ��";
            cin >> p->address;
        case 6:
            cout << "������绰��";
            cin >> p->phone;
        case 7:
            cout << "���������䣺";
            cin >> p->email;
        case 0:
            return;
        default:
            cout << "�����������������" << endl;
            break;
        }
    }
}

/**
 * ����ѧ��
 * @param str       ѧ�Ż�����
 * @return
 */
stu *Student::searchStudent(char str[MAX_BUFFER_LEN])
{
    stu *pre = NULL, *p;

    if (!student)
    {
        return NULL;
    }

    p = student;

    // ��������,����ѧ��
    while (p && (strcmp(p->sno, str) != 0) && (strcmp(p->name, str) != 0))
    {
        pre = p;
        p = p->next;
    }

    if (!p)
    {
        return NULL;
    }

    // ���Ҫɾ����ѧ���ǵ�һ��ѧ��
    if (!pre)
    {
        student = p->next;
    }
    else
    {
        pre->next = p->next;
    }

    free(p);

    return student;
}

/**
 * ��ʾ����ѧ��
 * @return
 */
void Student::showAllStudent()
{
    fstream fp;

    // �Զ����Ʒ�ʽ���ļ�
    fp.open("db/student.bin", ios::in | ios::binary);

    // ����ļ���ʧ��
    if (!fp)
    {
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    cout << " |ѧ��\t|\t����\t|\t����\t|\t�Ա�\t|\t��������\t|\t��ͥ��ַ\t|\t�绰\t|\t����\t| " << endl;
    cout << endl;

    // ��ȡ�ļ�
    while (fp.read((char *)student, sizeof(stu)))
    {
        cout << " |" << student->sno << "\t|\t" << student->name << "\t|\t" << student->age << "\t|\t"
             << student->gender << "\t|\t" << student->birthday << "\t|\t" << student->address
             << "\t|\t" << student->phone << "\t|\t" << student->email << "\t|" << endl;
    }

    cout << endl;
    // �ر��ļ�
    fp.close();
}

/**
 * �˵�
 * @return
 */
void Student::menu()
{
    // ��ʼ��
    init();

    // ��ʾ�˵�
    while (true)
    {
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
        cout << endl;

        switch (choice)
        {
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
            // �ͷ��ڴ�
            free(student);
            cout << "�����������������" << endl;
            break;
        }
    }
}
