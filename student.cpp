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
        std::cout << "���ļ�ʧ��" << endl;
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
            // תΪint
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
        // ���ѧ��
        S = add(S, info);
    }

    infile.close();

    return S;
}

void Student::print(Info info, bool show_head) {

    if (show_head) {
        // ��ӡ��ͷ
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
    // ��ֵ��ͷ���
    Stu *p = S;

    // �Ƿ���ҳɹ�
    bool success = false,is_name = true;

    if (!p && !str.empty()) {
        showMessage && std::cout << "û�и�ѧ����Ϣ" << endl;
        return S;
    }

    // һֱѰ����һ��ѧ����Ϣ,֪���ҵ�Ϊֹ
    while (p) {
        // ���������� str, ��ô����ÿ�β���ʱƥ��ѧ�Ż�������
        if (!str.empty() && p->info.sno == str) {
            // �ҵ���ѧ��,��ӡ��Ϣ������̨
            if (showMessage) print(p->info, true);
            success = true;
            break;
        }

        // ����,��Ϊ���ֿ��ܻ��ж����ͬ������ȫ������
        if (!str.empty() && p->info.name == str) {
            // �ҵ���ѧ��,��ӡ��Ϣ������̨
            if (showMessage) print(p->info, is_name);
            success = true;
            // ���ƴ�ӡ��ͷ�ģ�ֻ��Ҫ��ӡһ�ξ���
            is_name = false;
        }

        p = p->next;
    }

    // ���û���ҵ�ѧ������ô�ͷ��� NULL
    if (!str.empty() && !success) {
        showMessage && std::cout << "û�и�ѧ����Ϣ" << endl;
        return NULL;
    }

    return p;
}

Stu *Student::add(Stu *S, Info info) {
    // �ж�ѧ���Ƿ��ظ�
    if (!info.sno.empty() && find(S, info.sno, false)) {
        return S;
    }

    if (this->total == 0) {
        S = new Stu;
        S->info = info;
        S->next = NULL;
    } else {
        Stu *p = S, *q = new Stu;
        // �ҵ����һ�����
        while (p->next) p = p->next;

        q->info = info;
        q->next = NULL;

        // ���½����ӵ����һ�����ĺ���
        p->next = q;
    }

    // ѧ������ + 1
    this->total += 1;

    return S;
}

Stu *Student::del(Stu *S, string str) {
    Stu *p, *q;

    // ����Ҫɾ����ѧ��
    p = find(S, str);

    // ���û���ҵ�Ҫɾ����ѧ��
    if (!p) {
        std::cout << "û�и�ѧ����Ϣ" << endl;
        return S;
    }

    // ���Ҫɾ����ѧ���ǵ�һ�����
    if (p == S) {
        S = p->next;
    } else {
        // �ҵ�Ҫɾ����ѧ����ǰһ�����
        q = S;
        while (q->next != p) q = q->next;

        // ɾ����ѧ��
        q->next = p->next;
    }

    // �ͷ��ڴ�
    delete p;

    // ѧ������ - 1
    this->total -= 1;

    return S;
}

void Student::printAll(Stu *S) {
    Stu *p = S;

    // ���û��ѧ����Ϣ
    if (!p) {
        std::cout << "û��ѧ����Ϣ" << endl;
        return;
    }

    // ��ӡ��ͷ
    printHead();

    // ��ӡ����ѧ����Ϣ
    while (p) {
        print(p->info, false);
        p = p->next;
    }
    std::cout << "----------------------------------------------------------------------------------" << endl;
    cout << "ѧ������: " << this->total << endl;
    cout << endl;
}

Stu *Student::update(Stu *S, string sno) {
    // ����Ҫ�޸ĵ�ѧ����Ϣ
    Stu *p = find(S, sno);

    if (!p) {
        std::cout << "û�и�ѧ����Ϣ" << endl;
        return S;
    }

    // ����ѧ����Ϣ
    Info info = inputUpdateInfo(p->info);

    std::cout << "�޸ĵ�name: " << info.name << endl;

    // �޸�ѧ����Ϣ
    p->info = info;

    return S;
}

Stu *Student::sort(Stu *S, Sort sort) {
    Stu *p = S, *q;

    if (this->total == 0) {
        std::cout << "����ѧ����Ϣ" << endl;
        return S;
    }

    // ���û�������������ͻ�������˳����ô�Ͳ���������
    if (sort.type.empty() || sort.order.empty()) {
        return S;
    }

    // ������������
    string operatorType = (sort.order == "asc") ? ">" : "<";


    // ���ѭ��
    while (p) {
        // �ȶԵ���һ�����
        q = p->next;

        // �ȶ�ѭ��
        while (q) {
            // ������ж�����
            bool flag = false;

            // ȷ���ж�����
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

            // ���������������ô�ͽ���������������
            if (flag) {
                Info temp = p->info;
                p->info = q->info;
                q->info = temp;
            }

            // ���в���
            q = q->next;

        }
        // ����������
        p = p->next;
    }

    printAll(S);

    return S;
}

void Student::save(Stu *S) {
    if (!S) {
        return;
    }

    // ����д��
    ofstream outfile(FILE_NAME, ios::out);

    if (!outfile.is_open()) {
        std::cout << "���ļ�ʧ��" << endl;
        return;
    }

    Stu *current = S;

    while (current) {
        // ������תΪ�ַ���
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
