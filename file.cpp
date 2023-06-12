//
// Created by 26363 on 2023/6/12.
//
#include "student.h"
#include <fstream>
//#include <utility>

#define FILE_NAME "db/student.bin"

/**
 * 读取文件函数
 * @param mode      打开模式
 * @return fstream
 * @example
 */
fstream openBinaryFile(ios::openmode mode = ios::in | ios::binary) {
    // 读取 db 目录下的 student.bin 文件
    fstream fp;
    // 以二进制方式打开文件
    fp.open(FILE_NAME, mode);
    // 如果文件打开失败
    if (!fp) {
        cout << "文件打开失败" << endl;
    }

//    return move(fp);
    return static_cast<fstream&&>(fp);
}

/**
 * 存储学生信息，每次存储一个学生信息后换行
 * @param filename  文件名
 * @param student   学生信息
 * @return
 * @example
 *     stu *student = (stu *) malloc(sizeof(stu));
 *     wirteBinaryFile("db/student.bin", student);
 */
void wirteBinaryFile(stu *student) {
    // 写入 db 目录下的 student 文件, 打开模式为追加写入
    fstream fp = openBinaryFile(ios::out | ios::app | ios::binary);
    // 写入文件
    fp.write((char *) student, sizeof(stu));
    // 换行
    fp << endl;
    // 关闭文件
    fp.close();
}

/**
 * 读取学生信息，每次读取一行
 * @return
 */
void readBinaryFile() {
    // 读取 db 目录下的 student.bin 文件
    fstream fp = openBinaryFile();

    stu *student = (stu *) malloc(sizeof(stu));

    // 读取文件
    while (fp && fp.read((char *) student, sizeof(stu))) {
        cout << " |" << student->sno << "\t|\t" << student->name << "\t|\t" << student->age << "\t|\t"
             << student->gender << "\t|\t" << student->birthday << "\t|\t" << student->address
             << "\t|\t" << student->phone << "\t|\t" << student->email << "\t|" << endl;
    }

    // 关闭文件
    fp.close();
}

/**
 * 根据学号删除学生信息
 * @param sno   学号
 * @return
 */
void deleteBinaryFile(char sno[MAX_BUFFER_LEN]) {
    // 读取 db 目录下的 student.bin 文件
    fstream fp = openBinaryFile();

    stu *student = (stu *) malloc(sizeof(stu));
    // 读取文件
    while (fp && fp.read((char *) student, sizeof(stu))) {
        if (student->sno != sno) {
            student->next = (stu *) malloc(sizeof(stu));
        }
    }

    // 关闭文件
    fp.close();
}
