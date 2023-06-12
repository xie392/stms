//
// Created by 26363 on 2023/6/12.
//

#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <cstdlib>
#include <iostream>
using namespace std;

#define datatype int                    // 定义数据类型

typedef struct student{
    string sno;                         // 学号
    string name;                        // 姓名
    datatype age;                       // 年龄
    string gender;                      // 性别
    string birthday;                    // 出生日期
    string address;                     // 家庭住址
    string phone;                       // 电话
    string email;                       // 邮箱
    datatype total;                     // 学生总数
    struct student *next;               // 指向下一个学生的指针
} stu;

class Student {
public:
    stu *student;                               // 学生信息
    void init();                                // 初始化,把db/student.txt文件中的学生信息读取到内存中
    void wirteStudent(stu *student);            // 写入学生信息
    void addStudent();                    // 添加学生
    void deleteStudent();                       // 删除学生
    void modifyStudent();                       // 修改学生
    stu *searchStudent(const string& str);      // 查找学生,按学号或姓名查找
    void showAllStudent();                      // 显示学生信息
    void menu();                                // 菜单
};

#endif //STMS_STUDENT_H
