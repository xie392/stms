#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

#define FILE_NAME "db/student.bin" // �����ļ���

//
#define TABLE_HEAD "\tѧ��\t | \t����\t | \t����\t | \t�Ա�\t | \t��������\t | \t��ͥסַ\t | \t�绰\t | \t����\t"

typedef struct
{
    string sno;      // ѧ��,Ψһ�������ظ���ÿ�����ѧ��ʱ���
    string name;     // ����
    int age;         // ����
    string gender;   // �Ա�
    string birthday; // ��������
    string address;  // ��ͥסַ
    string phone;    // �绰
    string email;    // ����
} student;

typedef struct S
{
    student *info;  // ѧ����Ϣ
    struct S *next; // ָ����һ��ѧ����ָ��
} Stu;

class Student
{
public:
    int total;

    /**
     * ��ʼ��,��db/student.bin�ļ��е�ѧ����Ϣ��ȡ���ڴ���
     * @return Stu * ����ѧ����Ϣ
     */
    Stu *init();

    /**
     * �������һ���������ǲ������һ��ѧ���������ֵ���һ���������ǲ���ָ��ѧ�Ż�������ѧ��
     * @param Stu *S ѧ����Ϣ
     */
    Stu *find(Stu *S, string str = "");

    /**
     * ����ѧ����Ϣ
     * @return student * ����ѧ����Ϣ
     */
    student *addInput();

    /**
     * ���ѧ��
     * @param Stu *S ѧ����Ϣ
     * @param student info ѧ����Ϣ
     * @return Stu * ����ѧ����Ϣ
     */
    Stu *add(Stu *S, student *info);

    /**
     * ��ӡѧ����Ϣ
     * @param stutent *info     ѧ����Ϣ
     * @param bool  showHead    �Ƿ���ʾ��ͷ
     * @return void
     */
    void print(student *info,bool showHead = false);


    /**
     * ��ӡ����ѧ����Ϣ
     * @param Stu *S ѧ����Ϣ
     * @return void
     */
    void printAll(Stu *S); 

    /**
     * ɾ��ѧ��
     * @param Stu *S ѧ����Ϣ
     * @param string sno ѧ��
     * @return Stu * ����ѧ����Ϣ
     */
    Stu *del(Stu *S, string sno); 

    /**
     * ���ڲ���ʱ��Ҫ����ѧ�Ż�����������ѧ�Ż�����
     * @param string tips ��ʾ��Ϣ��������ʾ��ʾ��Ϣ�������������ַ���
     * @return string ������ַ���
     * @example 
     *      findInput("ѧ��")  
     *      findInput("ѧ�� | ����")  
     */
    string findInput(string tips = "ѧ��");
    

    /**
     * �˵�
     * @return void
     */
    void menu(); 
};
