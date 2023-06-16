#ifndef STMS_STUDENT_H
#define STMS_STUDENT_H

#define FILE_NAME "data.bin"
#define TABLE_HEAD "ѧ��     ����    ����    �Ա�    ��������     ��ͥסַ     �绰           ����  "

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

struct Info {
    string sno;             // ѧ��,Ψһ�������ظ���ÿ�����ѧ��ʱ���
    string name;            // ����
    int age;                // ����
    string gender;          // �Ա�
    string birthday;        // ��������
    string address;         // ��ͥסַ
    string phone;           // �绰
    string email;           // ����
};

typedef struct S {
    struct Info info;       // ѧ����Ϣ
    struct S *next;         // ָ����һ��ѧ����ָ��
} Stu;

typedef struct {
    string type;            // �������ͣ��磺 ѧ�� | ����
    string order;           // ����ʽ���磺 ���� | ����
} Sort;


class Student {
public:
    int total;

    /**
     * ��ʼ������db/student.bin�ļ��е�ѧ����Ϣ��ȡ���ڴ���
     * @return Stu* ����ѧ����Ϣ
     */
    Stu *init();

    /**
     * ��ӡѧ����Ϣ
     * @param Info *info  ѧ����Ϣ
     * @param bool show_head �Ƿ���ʾ��ͷ
     * @return void
     */
    void print(Info info, bool show_head = true);

    /**
     * ����ѧ��
     * @param Stu *S ѧ����Ϣ
     * @param string str ѧ�Ż�����[��ѡ,Ĭ�Ͽ�]
     * @param bool showMessage �Ƿ���ʾ��ʾ��Ϣ[��ѡ,Ĭ��false]
     * @return Stu* ����ѧ����Ϣ
     */
    Stu *find(Stu *S, string str = "", bool showMessage = false);

    /**
     * ���ѧ��
     * @param   Stu *S  ѧ����Ϣ
     * @param   Info *info ѧ����Ϣ
     * @return  Stu* ��������ѧ����Ϣ
     */
    Stu *add(Stu *S, Info info);

    /**
     * ɾ��ѧ��
     * @param   Stu *S  ѧ����Ϣ
     * @param   string str ѧ�Ż�����
     * @return  Stu* ��������ѧ����Ϣ
     */
    Stu *del(Stu *S, string str);

    /**
     * ��ӡ����ѧ����Ϣ
     * @param   Stu *S  ѧ����Ϣ
     * @return  void
     */
    void printAll(Stu *S);

    /**
   * �޸�ѧ����Ϣ
   * @param Stu *S ѧ����Ϣ
   * @param string sno ѧ��
   * @return Stu * ����ѧ����Ϣ
   */
    Stu *update(Stu *S, string sno);

    /**
     * ����ѧ����Ϣ,���԰���ѧ�Ż���������
     * @param   Stu *S  ѧ����Ϣ
     * @param   Sort sort ������Ϣ type: �������ͣ��磺 ѧ�� | ���� order: ����ʽ���磺 ���� | ����
     * @return  Stu* ��������ѧ����Ϣ
     */
    Stu *sort(Stu *S, Sort sort);

    /**
     * �����ļ�
     * @param Stu *S ѧ����Ϣ
     * @return void
     */
    void save(Stu *S);

};


#endif //STMS_STUDENT_H
