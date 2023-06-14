#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#define FILE_NAME "db/student.bin" // 定义文件名

//
#define TABLE_HEAD "\t学号\t | \t姓名\t | \t年龄\t | \t性别\t | \t出生日期\t | \t家庭住址\t | \t电话\t | \t邮箱\t"

typedef struct
{
    string sno;      // 学号,唯一，不可重复，每次添加学生时检查
    string name;     // 姓名
    int age;         // 年龄
    string gender;   // 性别
    string birthday; // 出生日期
    string address;  // 家庭住址
    string phone;    // 电话
    string email;    // 邮箱
} student;

typedef struct S
{
    student *info;  // 学生信息
    struct S *next; // 指向下一个学生的指针
} Stu;

class Student
{
public:
    int total;

    /**
     * 初始化,把db/student.bin文件中的学生信息读取到内存中
     * @return Stu * 返回学生信息
     */
    Stu *init();

    /**
     * 不传最后一个参数就是查找最后一个学生，如果传值最后一个参数就是查找指定学号或姓名的学生
     * @param Stu *S 学生信息
     */
    Stu *find(Stu *S, string str = "");

    /**
     * 输入学生信息
     * @return student * 返回学生信息
     */
    student *addInput();

    /**
     * 添加学生
     * @param Stu *S 学生信息
     * @param student info 学生信息
     * @return Stu * 返回学生信息
     */
    Stu *add(Stu *S, student *info);

    /**
     * 打印学生信息
     * @param stutent *info     学生信息
     * @param bool  showHead    是否显示表头
     * @return void
     */
    void print(student *info,bool showHead = false);


    /**
     * 打印所有学生信息
     * @param Stu *S 学生信息
     * @return void
     */
    void printAll(Stu *S); 

    /**
     * 删除学生
     * @param Stu *S 学生信息
     * @param string sno 学号
     * @return Stu * 返回学生信息
     */
    Stu *del(Stu *S, string sno); 

    /**
     * 用于查找时需要输入学号或姓名，返回学号或姓名
     * @param string tips 提示信息，用于显示提示信息，可以是任意字符串
     * @return string 输入的字符串
     * @example 
     *      findInput("学号")  
     *      findInput("学号 | 姓名")  
     */
    string findInput(string tips = "学号");
    

    /**
     * 菜单
     * @return void
     */
    void menu(); 
};
