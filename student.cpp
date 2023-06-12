//
// Created by 26363 on 2023/6/12.
//
#include "student.h"

/**
 * TODO:初始化,把db/student.txt文件中的学生信息读取到内存中
 * @return
 */
void Student::init() {
    student = (stu *) malloc(sizeof(stu));
//    // 读取 db 目录下的 student.txt 文件
    FILE *fp = fopen("db/student.txt", "r");

    if (fp == nullptr) {
        cout << "文件打开失败" << endl;
        return;
    }
}

/**
 * TODO:写入学生信息
 * @param s   学生信息
 * @return
 */
void Student::wirteStudent(stu *s) {
    // 写入 db 目录下的 student.txt 文件
    FILE *fp = fopen("db/student.txt", "a");

    if (fp == nullptr) {
        cout << "文件打开失败" << endl;
        return;
    }

    // TODO: 把学生信息写入文件
    fwrite(s, sizeof(stu), 1, fp);
}

/**
* 添加学生
 * @return
 */
void Student::addStudent() {
    cout << "请输入学号：";
    cin >> student->sno;
    cout << "请输入姓名：";
    cin >> student->name;
    cout << "请输入年龄：";
    cin >> student->age;
    cout << "请输入性别：";
    cin >> student->gender;
    cout << "请输入出生日期：";
    cin >> student->birthday;
    cout << "请输入家庭住址：";
    cin >> student->address;
    cout << "请输入电话：";
    cin >> student->phone;
    cout << "请输入邮箱：";
    cin >> student->email;

    // 学生总数 + 1
    student->total++;

    // TODO:写入 db 目录下的 student.txt 文件
    wirteStudent(student);

    // 指向下一个学生的指针
    student->next = (stu *) malloc(sizeof(stu));
}

/**
 * 删除学生
 * @return
 */
void Student::deleteStudent() {
    cout << "请输入要删除的学生学号：";
    string sno;
    cin >> sno;

    // 查找学生
    stu *p = searchStudent(sno);

    if (p) {
        cout << "查找学生：" << p->sno << p->name << endl;
    }

}

/**
 * 修改学生
 * @return
 */
void Student::modifyStudent() {}

/**
 * 查找学生
 * @return
 */
stu *Student::searchStudent(const string &str) {
    stu *pre = nullptr, *p;
    if (!student) {
        cout << "学生信息为空" << endl;
        return student;
    }

    p = student;

    // 遍历链表,查找学生
    while (p && (p->sno != str || p->name != str)) {
        pre = p;
        p = p->next;
    }

    if (!p) {
        cout << "没有找到学生,请检查输入学号是否正确" << endl;
        return student;
    }

    // 如果要删除的学生是第一个学生
    if (!pre) {
        student = p->next;
    } else {
        pre->next = p->next;
    }

    free(p);

    return student;

}

/**
 * 显示所有学生
 * @return
 */
void Student::showAllStudent() {}


/**
* 菜单
 * @return
 */
void Student::menu() {
    init();
    while (true) {
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
                cout << "输入错误，请重新输入" << endl;
                break;
        }
    }
}


