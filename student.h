//
// Created by 26363 on 2023/6/12.
//

#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <stdlib.h>
#include <iostream>

#define MAX_NAME_LEN 20                 // 姓名最大长度
#define MAX_BIRTHDAY_LEN 20             // 出生日期最大长度
#define MAX_ADDRESS_LEN 100             // 家庭住址最大长度
#define MAX_PHONE_LEN 20                // 电话最大长度
#define MAX_EMAIL_LEN 20                // 邮箱最大长度

#define datatype int                    // 定义数据类型

typedef struct student{
    datatype sno;                       // 学号
    char name[MAX_NAME_LEN];            // 姓名
    datatype age;                       // 年龄
    char gender[2];                     // 性别
    char birthday[MAX_BIRTHDAY_LEN];    // 出生日期
    char address[MAX_ADDRESS_LEN];      // 家庭住址
    char phone[MAX_PHONE_LEN];          // 电话
    char email[MAX_EMAIL_LEN];          // 邮箱
    datatype total;                     // 学生总数
    struct student *next;               // 指向下一个学生的指针
} stu;

class Student {
public:
    stu *student = (stu *) malloc(sizeof(stu));
    void init();                        // 初始化,把db/student.txt文件中的学生信息读取到内存中
    void wirteStudent(stu *student);    // 写入学生信息
    void addStudent();                  // 添加学生
    void deleteStudent();               // 删除学生
    void modifyStudent();               // 修改学生
    stu *searchStudentSno(datatype sno);// 查找学生,按学号查找
    stu *searchStudentName(char name[MAX_NAME_LEN]);    // 查找学生,按姓名查找
    void showAllStudent();              // 显示所有学生
    void menu();                        // 菜单
};

#endif //STMS_STUDENT_H
