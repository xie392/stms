#include "student.h"

Stu *Student::init()
{
    this->total = 0;
    Stu *S = new Stu;
    S->next = NULL;
    return S;

    // 为学生信息分配内存
    // this->data = new Stu;
    // 初始化学生总数
    // this->total = 0;

    // 以二进制读的方式打开文件
    // TODO: 写入数据到 data->info
    // fstream fp(FILE_NAME, ios::in | ios::binary);

    // if (!fp.is_open())
    // {
    //     throw runtime_error("文件打开失败");
    // }
    // fp.close();
}

Stu *Student::find(Stu *S, string str)
{
    Stu *p = S;

    int i = 0;

    if (str != "" && this->total == 0)
    {
        std::cout << "没有该学生信息" << endl;
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

    // 寻找最后一个学生
    while (p && i++ < this->total)
    {
        std::cout << "p: " << p << endl;
        std::cout << "p->info: " << p->info << endl;
        std::cout << "p->info->name: " << p->info->name << endl;
        std::cout << "p->info->sno: " << p->info->sno << endl;
        // 如果要查找学生，那就匹配学号或者姓名，如果匹配成功就退出循环
        // if (str != "" && (p->info->sno != str || p->info->name != str))
        // {
        //     std::cout << "查找成功: " << p->info->sno << std::endl;
        //     break;
        // }
        p = p->next;
    }
    return p;
}

student *Student::addInput()
{
    // 为新的学生分配内存
    student *stu = new student;
    stu->sno = "123";
    stu->name = "123";
    // std::cout << "请输入学号：";
    // std::cin >> stu->sno;
    // TODO:检查学号是否重复
    // stu *p = searchStudent(s->sno);
    // if (p)
    // {
    //     std::cout << "学号已存在" << endl;
    //     return;
    // }
    // std::cout << "请输入姓名：";
    // std::cin >> stu->name;
    // std::cout << "请输入年龄：";
    // std::cin >> stu->age;
    // std::cout << "请输入性别：";
    // std::cin >> stu->gender;
    // std::cout << "请输入出生日期：";
    // std::cin >> stu->birthday;
    // std::cout << "请输入家庭住址：";
    // std::cin >> stu->address;
    // std::cout << "请输入电话：";
    // std::cin >> stu->phone;
    // std::cout << "请输入邮箱：";
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

    // 寻找最后一个学生
    q = find(S);

    std::cout << "查找到p: " << q << endl;

    // 将新学生添加到链表尾部
    // p->info = info;
    // p->next = q->next;
    // q->next = p;

    std::cout << "p: " << p << endl;
    std::cout << "p->info: " << p->info << endl;
    std::cout << "p->info->sno: " << p->info->sno << endl;
    std::cout << "p->info->name: " << p->info->name << endl;

    // p->next = NULL;

    // 学生总数加1
    this->total += 1;

    return S;
}

void Student::print(student *info, bool showHead)
{
    // 如果需要打印表头
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

    // 打印表头
    std::cout << TABLE_HEAD << endl;

    // 加多判断条件，防止死循环
    while (p && i++ < this->total)
    {
        print(p->info);
        p = p->next;
    }
}

string Student::findInput(string tips)
{
    string str;
    std::cout << "请输入" << tips << "：";
    std::cin >> str;
    return str;
}

Stu *Student::del(Stu *S, string sno)
{
    Stu *p = S, *q;

    // 寻找要删除的学生
    q = find(S, sno);

    std::cout << "p:" << p << endl;

    // 如果没有找到要删除的学生
    if (!q)
    {
        std::cout << "没有找到要删除的学生" << endl;
        return S;
    }

    // 删除学生
    p->next = q->next;
    delete q;

    // 学生总数减1
    this->total -= 1;

    std::cout << "已成功删除学号为 \"" << sno << "\" "
              << "的学生" << endl;

    return S;
}

void Student::menu()
{
    Stu *data;

    // 初始化
    data = init();

    Stu *p;

    // 显示菜单
    while (true)
    {
        std::cout << endl;
        std::cout << "========================= 学生管理系统start ==========================" << endl;
        std::cout << "1. 添加学生" << endl;
        std::cout << "2. 删除学生" << endl;
        std::cout << "3. 修改学生" << endl;
        std::cout << "4. 查找学生" << endl;
        std::cout << "5. 删除学生" << endl;
        std::cout << "6. 显示所有学生" << endl;
        std::cout << "0. 退出" << endl;
        std::cout << "========================= 学生管理系统end ==========================" << endl;
        std::cout << endl;

        int choice;
        std::cout << "请输入你的选择：";
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
            p = find(data, findInput("学号或姓名"));
            // std::cout<<"查找到的学生: " << p->info->sno << endl;
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
            // 保存学生信息到文件
            // saveStudent();
            exit(0);
        default:
            std::cout << "输入错误，请重新输入" << endl;
            break;
        }
    }
}