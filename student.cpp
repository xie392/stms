#include "student.h"

Stu *Student::init()
{
    this->total = 0;
    Stu *S = new Stu;
    S->next = NULL;
    return S;

    // Ϊѧ����Ϣ�����ڴ�
    // this->data = new Stu;
    // ��ʼ��ѧ������
    // this->total = 0;

    // �Զ����ƶ��ķ�ʽ���ļ�
    // TODO: д�����ݵ� data->info
    // fstream fp(FILE_NAME, ios::in | ios::binary);

    // if (!fp.is_open())
    // {
    //     throw runtime_error("�ļ���ʧ��");
    // }
    // fp.close();
}

Stu *Student::find(Stu *S, string str)
{
    Stu *p = S;

    int i = 0;

    if (str != "" && this->total == 0)
    {
        std::cout << "û�и�ѧ����Ϣ" << endl;
        return NULL;
    }

    std::cout << "stotal: " << this->total << endl;

    // if (this->total > 0)
    // {
    //     std::cout << "s: " << S << endl;
    //     std::cout << "s->info: " << S->info << endl;
    //     std::cout << "s->info->name: " << S->info->name << endl;
    //     std::cout << "s->info->sno: " << S->info->sno << endl;
    // }

    // Ѱ�����һ��ѧ��
    while (p && i++ < this->total)
    {
        std::cout << "p: " << p << endl;
        std::cout << "p->info: " << p->info << endl;
        std::cout << "p->info->name: " << p->info->name << endl;
        std::cout << "p->info->sno: " << p->info->sno << endl;
        // ���Ҫ����ѧ�����Ǿ�ƥ��ѧ�Ż������������ƥ��ɹ����˳�ѭ��
        // if (str != "" && (p->info->sno != str || p->info->name != str))
        // {
        //     std::cout << "���ҳɹ�: " << p->info->sno << std::endl;
        //     break;
        // }
        p = p->next;
    }
    return p;
}

student *Student::addInput()
{
    // Ϊ�µ�ѧ�������ڴ�
    student *stu = new student;
    stu->sno = "123";
    stu->name = "123";
    // std::cout << "������ѧ�ţ�";
    // std::cin >> stu->sno;
    // TODO:���ѧ���Ƿ��ظ�
    // stu *p = searchStudent(s->sno);
    // if (p)
    // {
    //     std::cout << "ѧ���Ѵ���" << endl;
    //     return;
    // }
    // std::cout << "������������";
    // std::cin >> stu->name;
    // std::cout << "���������䣺";
    // std::cin >> stu->age;
    // std::cout << "�������Ա�";
    // std::cin >> stu->gender;
    // std::cout << "������������ڣ�";
    // std::cin >> stu->birthday;
    // std::cout << "�������ͥסַ��";
    // std::cin >> stu->address;
    // std::cout << "������绰��";
    // std::cin >> stu->phone;
    // std::cout << "���������䣺";
    // std::cin >> stu->email;

    return stu;
}

Stu *Student::add(Stu *S, student *info)
{
    Stu *p = new Stu, *q;

    // if (this->total > 0)
    // {
    //     std::cout << "1s: " << S << endl;
    //     std::cout << "1s->info: " << S->info << endl;
    //     std::cout << "1s->info->name: " << S->info->name << endl;
    //     std::cout << "1s->info->sno: " << S->info->sno << endl;
    // }

    // Ѱ�����һ��ѧ��
    q = find(S);

    std::cout << "���ҵ�p: " << q << endl;

    // ����ѧ����ӵ�����β��
    // p->info = info;
    // p->next = q->next;
    // q->next = p;

    std::cout << "p: " << p << endl;
    std::cout << "p->info: " << p->info << endl;
    std::cout << "p->info->sno: " << p->info->sno << endl;
    std::cout << "p->info->name: " << p->info->name << endl;

    // p->next = NULL;

    // ѧ��������1
    this->total += 1;

    return S;
}

void Student::print(student *info, bool showHead)
{
    // �����Ҫ��ӡ��ͷ
    if (showHead)
    {
        std::cout << TABLE_HEAD << endl;
    }

    std::cout << info->sno << "\t";
    // std::cout<< info->name << "\t";
    // std::cout<< info->age << "\t";
    // std::cout<< info->gender << "\t";
    // std::cout<< info->birthday << "\t";
    // std::cout<< info->address << "\t";
    // std::cout<< info->phone << "\t";
    // std::cout<< info->email << "\t";
    std::cout << endl;
}

void Student::printAll(Stu *S)
{
    Stu *p;
    p = S->next;
    int i = 0;

    // ��ӡ��ͷ
    std::cout << TABLE_HEAD << endl;

    // �Ӷ��ж���������ֹ��ѭ��
    while (p && i++ < this->total)
    {
        print(p->info);
        p = p->next;
    }
}

string Student::findInput(string tips)
{
    string str;
    std::cout << "������" << tips << "��";
    std::cin >> str;
    return str;
}

Stu *Student::del(Stu *S, string sno)
{
    Stu *p = S, *q;

    // Ѱ��Ҫɾ����ѧ��
    q = find(S, sno);

    std::cout << "p:" << p << endl;

    // ���û���ҵ�Ҫɾ����ѧ��
    if (!q)
    {
        std::cout << "û���ҵ�Ҫɾ����ѧ��" << endl;
        return S;
    }

    // ɾ��ѧ��
    p->next = q->next;
    delete q;

    // ѧ��������1
    this->total -= 1;

    std::cout << "�ѳɹ�ɾ��ѧ��Ϊ \"" << sno << "\" "
              << "��ѧ��" << endl;

    return S;
}

void Student::menu()
{
    Stu *data;

    // ��ʼ��
    data = init();

    Stu *p;

    // ��ʾ�˵�
    while (true)
    {
        std::cout << endl;
        std::cout << "========================= ѧ������ϵͳstart ==========================" << endl;
        std::cout << "1. ���ѧ��" << endl;
        std::cout << "2. ɾ��ѧ��" << endl;
        std::cout << "3. �޸�ѧ��" << endl;
        std::cout << "4. ����ѧ��" << endl;
        std::cout << "5. ɾ��ѧ��" << endl;
        std::cout << "6. ��ʾ����ѧ��" << endl;
        std::cout << "0. �˳�" << endl;
        std::cout << "========================= ѧ������ϵͳend ==========================" << endl;
        std::cout << endl;

        int choice;
        std::cout << "���������ѡ��";
        cin >> choice;
        std::cout << endl;

        switch (choice)
        {
        case 1:
            if(this->total>0){printAll(data);}
            data = add(data, addInput());
            break;
        case 2:
            // deleteStudent();
            break;
        case 3:

            break;
        case 4:
            p = find(data, findInput("ѧ�Ż�����"));
            // std::cout<<"���ҵ���ѧ��: " << p->info->sno << endl;
            // if (p)
            // {
            //     print(p->info,true);
            // }
            break;
        case 5:
            data = del(data, findInput());
            break;
        case 6:
            printAll(data);
            break;
        case 0:
            // ����ѧ����Ϣ���ļ�
            // saveStudent();
            exit(0);
        default:
            std::cout << "�����������������" << endl;
            break;
        }
    }
}