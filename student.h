#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#include <cstdlib>
#include <iostream>

using namespace std;

#define datatype int                    // 定义数据类型
#define MAX_BUFFER_LEN  20              // 定义最大缓冲区长度
#define MAX_ADDRESS_LEN 100             // 定义最大地址长度

typedef struct student{
    char sno[MAX_BUFFER_LEN];           // 学号
    char name[MAX_BUFFER_LEN];          // 姓名
    datatype age;                       // 年龄
    char gender[2];                     // 性别
    char birthday[MAX_BUFFER_LEN];      // 出生日期
    char address[MAX_ADDRESS_LEN];      // 家庭住址
    char phone[MAX_BUFFER_LEN];         // 电话
    char email[MAX_BUFFER_LEN];         // 邮箱
    datatype total;                     // 学生总数
    struct student *next;               // 指向下一个学生的指针
} stu;

class Student {
public:
    stu *student;                       // 学生信息
    void init();                        // 初始化,把db/student.txt文件中的学生信息读取到内存中
    void wirteStudent(stu *student);    // 写入学生信息
    void addStudent();                  // 添加学生
    void deleteStudent();               // 删除学生
    void modifyStudent();               // 修改学生
    stu *searchStudent(char str[MAX_BUFFER_LEN]);             // 查找学生,按学号或姓名查找
    void showAllStudent();              // 显示学生信息
    void menu();                        // 菜单
};

#endif //STMS_STUDENT_H
