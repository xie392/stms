#include "student.h"
#include "input.cpp"
#include <sstream>
#include <vector>
#include <cstdio>
#include <cstdlib>

Stu *Student::init() {
    this->total = 0;
    Stu *S = NULL;

    ifstream infile(FILE_NAME);

    if (!infile.is_open()) {
        std::cout << "打开文件失败" << endl;
        return S;
    }

    string line;
    while (getline(infile, line)) {
        stringstream ss(line);
        string field;
        Info info;

        while (getline(ss, field, ',')) {
            std::stringstream ss(line);
            std::string field;

            std::getline(ss, field, ',');
            info.sno = field;

            std::getline(ss, field, ',');
            // 转为int
            info.age = atoi(field.c_str());

            std::getline(ss, field, ',');
            info.name = field;

            std::getline(ss, field, ',');
            info.gender = field;

            std::getline(ss, field, ',');
            info.birthday = field;

            std::getline(ss, field, ',');
            info.address = field;

            std::getline(ss, field, ',');
            info.phone = field;

            std::getline(ss, field, ',');
            info.email = field;
        }
        // 添加学生
        S = add(S, info);
    }

    infile.close();

    return S;
}

void Student::print(Info info, bool show_head) {

    if (show_head) {
        // 打印表头
        printHead();
    }

    std::cout << info.sno << "     ";
    std::cout << info.name << "     ";
    std::cout << info.age << "     ";
    std::cout << info.gender << "    ";
    std::cout << info.birthday << "     ";
    std::cout << info.address << "     ";
    std::cout << info.phone << "     ";
    std::cout << info.email << "     ";
    std::cout << endl;
}

Stu *Student::find(Stu *S, string str, bool showMessage) {
    // 赋值给头结点
    Stu *p = S;

    // 是否查找成功
    bool success = false,is_name = true;

    if (!p && !str.empty()) {
        showMessage && std::cout << "没有该学生信息" << endl;
        return S;
    }

    // 一直寻找下一个学生信息,知道找到为止
    while (p) {
        // 如果传入参数 str, 那么就在每次查找时匹配学号或者姓名
        if (!str.empty() && p->info.sno == str) {
            // 找到该学生,打印信息到控制台
            if (showMessage) print(p->info, true);
            success = true;
            break;
        }

        // 名字,因为名字可能会有多个相同，所有全部找完
        if (!str.empty() && p->info.name == str) {
            // 找到该学生,打印信息到控制台
            if (showMessage) print(p->info, is_name);
            success = true;
            // 控制打印表头的，只需要打印一次就行
            is_name = false;
        }

        p = p->next;
    }

    // 如果没有找到学生，那么就返回 NULL
    if (!str.empty() && !success) {
        showMessage && std::cout << "没有该学生信息" << endl;
        return NULL;
    }

    return p;
}

Stu *Student::add(Stu *S, Info info) {
    // 判断学号是否重复
    if (!info.sno.empty() && find(S, info.sno, false)) {
        return S;
    }

    if (this->total == 0) {
        S = new Stu;
        S->info = info;
        S->next = NULL;
    } else {
        Stu *p = S, *q = new Stu;
        // 找到最后一个结点
        while (p->next) p = p->next;

        q->info = info;
        q->next = NULL;

        // 将新结点添加到最后一个结点的后面
        p->next = q;
    }

    // 学生总数 + 1
    this->total += 1;

    return S;
}

Stu *Student::del(Stu *S, string str) {
    Stu *p, *q;

    // 查找要删除的学生
    p = find(S, str);

    // 如果没有找到要删除的学生
    if (!p) {
        std::cout << "没有该学生信息" << endl;
        return S;
    }

    // 如果要删除的学生是第一个结点
    if (p == S) {
        S = p->next;
    } else {
        // 找到要删除的学生的前一个结点
        q = S;
        while (q->next != p) q = q->next;

        // 删除该学生
        q->next = p->next;
    }

    // 释放内存
    delete p;

    // 学生总数 - 1
    this->total -= 1;

    return S;
}

void Student::printAll(Stu *S) {
    Stu *p = S;

    // 如果没有学生信息
    if (!p) {
        std::cout << "没有学生信息" << endl;
        return;
    }

    // 打印表头
    printHead();

    // 打印所有学生信息
    while (p) {
        print(p->info, false);
        p = p->next;
    }
    std::cout << "----------------------------------------------------------------------------------" << endl;
    cout << "学生总数: " << this->total << endl;
    cout << endl;
}

Stu *Student::update(Stu *S, string sno) {
    // 查找要修改的学生信息
    Stu *p = find(S, sno);

    if (!p) {
        std::cout << "没有该学生信息" << endl;
        return S;
    }

    // 输入学生信息
    Info info = inputUpdateInfo(p->info);

    std::cout << "修改的name: " << info.name << endl;

    // 修改学生信息
    p->info = info;

    return S;
}

Stu *Student::sort(Stu *S, Sort sort) {
    Stu *p = S, *q;

    if (this->total == 0) {
        std::cout << "暂无学生信息" << endl;
        return S;
    }

    // 如果没有输入排序类型或者排序顺序，那么就不进行排序
    if (sort.type.empty() || sort.order.empty()) {
        return S;
    }

    // 升序或排序符号
    string operatorType = (sort.order == "asc") ? ">" : "<";


    // 外层循环
    while (p) {
        // 比对的下一个结点
        q = p->next;

        // 比对循环
        while (q) {
            // 排序的判断条件
            bool flag = false;

            // 确定判断条件
            if (sort.type == "sno") {
                if (operatorType == ">") {
                    flag = p->info.sno > q->info.sno;
                } else {
                    flag = p->info.sno < q->info.sno;
                }
            } else {
                if (operatorType == ">") {
                    flag = p->info.age > q->info.age;
                } else {
                    flag = p->info.age < q->info.age;
                }
            }

            // 如果满足条件，那么就交换两个结点的数据
            if (flag) {
                Info temp = p->info;
                p->info = q->info;
                q->info = temp;
            }

            // 进行步进
            q = q->next;

        }
        // 外层继续步进
        p = p->next;
    }

    printAll(S);

    return S;
}

void Student::save(Stu *S) {
    if (!S) {
        return;
    }

    // 覆盖写入
    ofstream outfile(FILE_NAME, ios::out);

    if (!outfile.is_open()) {
        std::cout << "打开文件失败" << endl;
        return;
    }

    Stu *current = S;

    while (current) {
        // 把年龄转为字符串
        char str[20];
        sprintf(str, "%d", current->info.age);
        outfile << current->info.sno << ",";
        outfile << str << ",";
        outfile << current->info.name << ",";
        outfile << current->info.gender << ",";
        outfile << current->info.birthday << ",";
        outfile << current->info.address << ",";
        outfile << current->info.phone << ",";
        outfile << current->info.email << "\n";
        current = current->next;
    }

    outfile.close();
}
