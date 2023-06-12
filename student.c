//
// Created by 26363 on 2023/6/12.
//
#include "student.h"

/**
* TODO:初始化,把db/student文件中的学生信息读取到内存中
 * @return
*/
void init(student *s) {
    // 分配内存
    s = (student *) malloc(sizeof(student));

    // 读取 db 目录下的 student.bin 文件
    FILE *fp = fopen("db/student.bin", "r");

    // 如果文件打开失败
    if (!fp) {
        printf("文件打开失败\n");
        return;
    }

    while (fread(s, sizeof(student), 1, fp)) {
        // 指向下一个学生的指针
        s->next = (student *) malloc(sizeof(student));
        s = s->next;
    }

    // 关闭文件
    fclose(fp);
}


/**
* TODO:追加写入学生信息
 * @param s   学生信息
 * @return
*/
void wirteStudent(student *s) {
    // 写入 db 目录下的 student 文件
    FILE *fp = fopen("db/student.bin", "a");

    // 如果文件打开失败
    if (!fp) {
        printf("文件打开失败\n");
        return;
    }

    // 写入文件
    fwrite(s, sizeof(student), 1, fp);

    // 关闭文件
    fclose(fp);
}

/**
* TODO:添加学生
 * @return
*/
void addStudent(student *s) {
    student *temp;
    temp = (student *) malloc(sizeof(student));
    printf("请输入学生学号：");
    scanf("%s", temp->sno);
    printf("请输入学生姓名：");
    scanf("%s", temp->name);
    printf("请输入学生年龄：");
    scanf("%d", &temp->age);
    printf("请输入学生性别：");
    scanf("%s",temp->gender);
    printf("请输入学生出生日期：");
    scanf("%s", temp->birthday);
    printf("请输入学生家庭住址：");
    scanf("%s", temp->address);
    printf("请输入学生电话：");
    scanf("%s", temp->phone);
    printf("请输入学生邮箱：");
    scanf("%s", temp->email);

    // 学生总数 + 1
    if(!s->total) {
        s->total = 1;
    } else {
        s->total++;
    }

    // 指向下一个学生的指针
    s->next = (student *) malloc(sizeof(student));

    // 写入文件
    wirteStudent(s);
}