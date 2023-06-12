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
 * 初始化,把db/student文件中的学生信息读取到内存中
 * @return
 */
void Student::init()
{
    // 读取 db 目录下的 student.bin 文件
    fstream fp;
    fp.open("db/student.bin", ios::in | ios::binary);

    // 头指针指向链表的第一个节点
    stu *head = NULL;

    while (fp && fp.read((char *)student, sizeof(stu)))
    {
        // 创建一个新的节点
        stu *new_student = new stu;
        // 将读取的数据存储到新节点中
        memcpy(new_student, student, sizeof(stu));

        // 如果是第一个学生
        if (!head)
        {
            head = new_student;
        }
        else
        {
            // 否则添加到链表末尾
            stu *current = head;
            while (current->next)
            {
                current = current->next;
            }
            current->next = new_student;
        }
    }

    // 将头指针赋值给成员变量
    student = head;

    // 关闭文件
    fp.close();
}

/**
 * TODO:追加写入学生信息
 * @param s   学生信息
 * @return
 */
void Student::wirteStudent(stu *s)
{
    // 写入 db 目录下的 student 文件
    fstream fp;

    // 以二进制方式打开文件
    fp.open("db/student.bin", ios::out | ios::app | ios::binary);

    // 如果文件打开失败
    if (!fp)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    // 写入文件
    fp.write((char *)s, sizeof(stu));

    // 关闭文件
    fp.close();
}

/**
 * 添加学生
 * @return
 */
void Student::addStudent()
{
    // 为新的学生分配内存
    stu *s;
    s = (stu *)malloc(sizeof(stu));

    cout << "请输入学号：";
    cin >> s->sno;

    stu *p = searchStudent(s->sno);
    if (p)
    {
        cout << "学号已存在" << endl;
        return;
    }

    cout << "请输入姓名：";
    cin >> s->name;
    cout << "请输入年龄：";
    cin >> s->age;
    cout << "请输入性别：";
    cin >> s->gender;
    cout << "请输入出生日期：";
    cin >> s->birthday;
    cout << "请输入家庭住址：";
    cin >> s->address;
    cout << "请输入电话：";
    cin >> s->phone;
    cout << "请输入邮箱：";
    cin >> s->email;

    s->total = s->total ? s->total + 1 : 1;

    // 如果是第一个学生
    if (!student)
    {
        student = s;
    }
    else
    {
        // 指向下一个学生的指针
        student->next = s;
    }

    // TODO:写入 db 目录下的 student.bin 文件
    wirteStudent(s);

    // 释放内存
    free(s);
}

/**
 * 删除学生
 * @return
 */
void Student::deleteStudent()
{
    cout << "请输入要删除的学生学号：";
    char sno[MAX_BUFFER_LEN];
    cin >> sno;

    // 查找学生
    stu *p = searchStudent(sno);

    if (!p)
    {
        cout << "没有该学生" << endl;
    }

    // 如果是第一个学生
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
 * 修改学生
 * @return
 */
void Student::modifyStudent()
{
    cout << "请输入要修改的学生学号：";
    char sno[MAX_BUFFER_LEN];
    cin >> sno;

    // 查找学生
    stu *p = searchStudent(sno);

    if (!p)
    {
        cout << "学号不存在" << endl;
        return;
    }

    // 输出学生信息
    cout << "   学号   " << p->sno;
    cout << "   姓名   " << p->name;
    cout << "   年龄   " << p->age;
    cout << "   性别   " << p->gender;

    while (true)
    {
        cout << "请选择你要修改的信息：" << endl;
        cout << "1.姓名" << endl;
        cout << "2.年龄" << endl;
        cout << "3.性别" << endl;
        cout << "4.出生日期" << endl;
        cout << "5.家庭住址" << endl;
        cout << "6.电话" << endl;
        cout << "7.邮箱" << endl;
        cout << "0.退出修改" << endl;

        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "请输入姓名：";
            cin >> p->name;
            break;
        case 2:
            cout << "请输入年龄：";
            cin >> p->age;
            break;
        case 3:
            cout << "请输入性别：";
            cin >> p->gender;
        case 4:
            cout << "请输入出生日期：";
            cin >> p->birthday;
        case 5:
            cout << "请输入家庭住址：";
            cin >> p->address;
        case 6:
            cout << "请输入电话：";
            cin >> p->phone;
        case 7:
            cout << "请输入邮箱：";
            cin >> p->email;
        case 0:
            return;
        default:
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
}

/**
 * 查找学生
 * @param str       学号或姓名
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

    // 遍历链表,查找学生
    while (p && (strcmp(p->sno, str) != 0) && (strcmp(p->name, str) != 0))
    {
        pre = p;
        p = p->next;
    }

    if (!p)
    {
        return NULL;
    }

    // 如果要删除的学生是第一个学生
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
 * 显示所有学生
 * @return
 */
void Student::showAllStudent()
{
    fstream fp;

    // 以二进制方式打开文件
    fp.open("db/student.bin", ios::in | ios::binary);

    // 如果文件打开失败
    if (!fp)
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << " |学号\t|\t姓名\t|\t年龄\t|\t性别\t|\t出生日期\t|\t家庭地址\t|\t电话\t|\t邮箱\t| " << endl;
    cout << endl;

    // 读取文件
    while (fp.read((char *)student, sizeof(stu)))
    {
        cout << " |" << student->sno << "\t|\t" << student->name << "\t|\t" << student->age << "\t|\t"
             << student->gender << "\t|\t" << student->birthday << "\t|\t" << student->address
             << "\t|\t" << student->phone << "\t|\t" << student->email << "\t|" << endl;
    }

    cout << endl;
    // 关闭文件
    fp.close();
}

/**
 * 菜单
 * @return
 */
void Student::menu()
{
    // 初始化
    init();

    // 显示菜单
    while (true)
    {
        cout << "========================= 学生管理系统start ==========================" << endl;
        cout << "1. 添加学生" << endl;
        cout << "2. 删除学生" << endl;
        cout << "3. 修改学生" << endl;
        cout << "4. 查找学生" << endl;
        cout << "5. 显示所有学生" << endl;
        cout << "0. 退出" << endl;
        cout << "========================= 学生管理系统end ==========================" << endl;
        cout << endl;

        int choice;
        cout << "请输入你的选择：";
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
            // 释放内存
            free(student);
            cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
}
