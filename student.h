#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#define FILE_NAME "data.bin"
#define TABLE_HEAD "学号     姓名    年龄    性别    出生日期     家庭住址     电话           邮箱  "

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Info {
    string sno;             // 学号,唯一，不可重复，每次添加学生时检查
    string name;            // 姓名
    int age;                // 年龄
    string gender;          // 性别
    string birthday;        // 出生日期
    string address;         // 家庭住址
    string phone;           // 电话
    string email;           // 邮箱
};

typedef struct S {
    struct Info info;       // 学生信息
    struct S *next;         // 指向下一个学生的指针
} Stu;

typedef struct {
    string type;            // 排序类型，如： 学号 | 姓名
    string order;           // 排序方式，如： 升序 | 降序
} Sort;


class Student {
public:
    int total;

    /**
     * 初始化，把db/student.bin文件中的学生信息读取到内存中
     * @return Stu* 返回学生信息
     */
    Stu *init();

    /**
     * 打印学生信息
     * @param Info *info  学生信息
     * @param bool show_head 是否显示表头
     * @return void
     */
    void print(Info info, bool show_head = true);

    /**
     * 查找学生
     * @param Stu *S 学生信息
     * @param string str 学号或姓名[可选,默认空]
     * @param bool showMessage 是否显示提示信息[可选,默认false]
     * @return Stu* 返回学生信息
     */
    Stu *find(Stu *S, string str = "", bool showMessage = false);

    /**
     * 添加学生
     * @param   Stu *S  学生信息
     * @param   Info *info 学生信息
     * @return  Stu* 返回最新学生信息
     */
    Stu *add(Stu *S, Info info);

    /**
     * 删除学生
     * @param   Stu *S  学生信息
     * @param   string str 学号或姓名
     * @return  Stu* 返回最新学生信息
     */
    Stu *del(Stu *S, string str);

    /**
     * 打印所有学生信息
     * @param   Stu *S  学生信息
     * @return  void
     */
    void printAll(Stu *S);

    /**
   * 修改学生信息
   * @param Stu *S 学生信息
   * @param string sno 学号
   * @return Stu * 返回学生信息
   */
    Stu *update(Stu *S, string sno);

    /**
     * 排序学生信息,可以按照学号或年龄排序
     * @param   Stu *S  学生信息
     * @param   Sort sort 排序信息 type: 排序类型，如： 学号 | 姓名 order: 排序方式，如： 升序 | 降序
     * @return  Stu* 返回最新学生信息
     */
    Stu *sort(Stu *S, Sort sort);

    /**
     * 保存文件
     * @param Stu *S 学生信息
     * @return void
     */
    void save(Stu *S);

};


#endif //STMS_STUDENT_H
