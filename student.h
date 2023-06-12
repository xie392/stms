#include <stdlib.h>
#include <stdio.h>

#define datatype int                    // 定义数据类型

#define MAX_BUFFER_LEN  20              // 定义最大缓冲区长度
#define MAX_ADDRESS_LEN 100             // 定义最大地址长度

typedef struct stu{
    char sno[MAX_BUFFER_LEN];           // 学号
    char name[MAX_BUFFER_LEN];          // 姓名
    datatype age;                       // 年龄
    char gender[2];                     // 性别
    char birthday[MAX_BUFFER_LEN];      // 出生日期
    char address[MAX_ADDRESS_LEN];      // 家庭住址
    char phone[MAX_BUFFER_LEN];         // 电话
    char email[MAX_BUFFER_LEN];         // 邮箱
    datatype total;                     // 学生总数
    struct stu *next;                   // 指向下一个学生的指针
} student;