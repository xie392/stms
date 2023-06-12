//
// Created by 26363 on 2023/6/12.
//
#include "student.h"
namespace std

/**
 * TODO:初始化,把db/student.txt文件中的学生信息读取到内存中
 * @return
 */
 void Student::init(){
    FILE *fp = fopen("db/student.txt", "r");
 }

/**
 * TODO:写入学生信息
 * @param student   学生信息
 * @return
 */
void Student::wirteStudent(stu *student) {
    // 写入 db 目录下的 student.txt 文件
    FILE *fp = fopen("db/student.txt", "a");

    if (fp == NULL) {
        std::cout << "文件打开失败" << std::endl;
        return;
    }

    // 把学生信息写入文件

}

/**
* 添加学生
 * @return
 */
void Student::addStudent() {
    std::cout << "请输入学生信息" << std::endl;
    std::cout << "请输入学号：";
    std::cin >> student->sno;
    std::cout << "请输入姓名：";
    std::cin >> student->name;
    std::cout << "请输入年龄：";
    std::cin >> student->age;
    std::cout << "请输入性别：";
    std::cin >> student -> gender;
    std::cout << "请输入出生日期：";
    std::cin >> student->birthday;
    std::cout << "请输入家庭住址：";
    std::cin >> student->address;
    std::cout << "请输入电话：";
    std::cin >> student->phone;
    std::cout << "请输入邮箱：";
    std::cin >> student->email;

    student -> total++;

    // TODO:写入 db 目录下的 student.txt 文件

    // 指向下一个学生的指针
    student -> next = (stu *) malloc(sizeof(stu));
}

/**
 * 删除学生
 * @return
 */
void Student::deleteStudent() {
    std::cout << "请输入要删除的学生学号：";
    std::string sno;
    std::cin >> sno;

    // 查找学生
    stu *p = searchStudent(sno);

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
stu *Student::searchStudent(char str[MAX_NAME_LEN]) {
    stu *pre = NULL, *p;
    if(!student) {
        std::cout << "学生信息为空" << std::endl;
        return student;
    }

    p = student;

    // 遍历链表,查找学生
    while (p && p->sno != str || p->name != str) {
        pre = p;
        p = p->next;
    }

    if (!p) {
        std::cout << "没有找到学生,请检查输入学号是否正确" << std::endl;
        return student;
    }

    // 如果要删除的学生是第一个学生
    if(!pre) {
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
    while (1) {
        std::cout << "========================= 学生管理系统start ==========================" << std::endl;
        std::cout << "1. 添加学生" << std::endl;
        std::cout << "2. 删除学生" << std::endl;
        std::cout << "3. 修改学生" << std::endl;
        std::cout << "4. 查找学生" << std::endl;
        std::cout << "5. 显示所有学生" << std::endl;
        std::cout << "0. 退出" << std::endl;
        std::cout << "========================= 学生管理系统end ==========================" << std::endl;
        std::cout<< std::endl;

        int choice;
        std::cout << "请输入你的选择：";
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
                std::cout << "输入错误，请重新输入" << std::endl;
                break;
        }
    }
}