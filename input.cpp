#include <limits>
#include "student.h"

/**
*  �ж�ѧ���Ƿ��ظ�
 *  @param Stu *S ѧ����Ϣ
 *  @param string sno ѧ��
 *  @return bool
*/
bool isRepeat(Stu *S, string sno) {
    bool is_Repeat = false;
    Stu *p = S;

    while (p) {
        // ����ҵ���ѧ����˵���Ѿ��ظ���
        if (p->info.sno == sno) {
            is_Repeat = true;
            break;
        }
        p = p->next;
    }

    return is_Repeat;
}


/**
 * �ӿ���̨����ѧ����Ϣ���������ѧ��ʱ���룬��������������
 * @param bool isUpdate �Ƿ��Ǹ���ѧ����Ϣ��Ĭ��Ϊfalse
 * @param Stu *S  ѧ����Ϣ
 * @return Info
*/
Info inputInfo(bool isUpdate = false, Stu *S = NULL) {
    Info info;
    string sno, name, gender, birthday, address, phone, email;
    int age;

    if (!isUpdate) {
        std::cout << "������ѧ�ţ�";
        std::cin >> sno;

        bool is_repeat = isRepeat(S, info.sno);
        // ���ѧ���Ƿ��ظ�
        if (is_repeat) {
            bool done = true;
            std::cout << "��ѧ�����ظ��������������µ�ѧ�Ż��˳����(y/�����ַ�):";

            string choice;
            std::cin >> choice;

            if (choice == "y" || choice == "Y") {
                done = true;
            } else {
                return Info();
            }
            while (done) {
                std::cout << "�������µ�ѧ�ţ�";
                std::cin >> sno;
                // �ݹ��ȥ�ж��Ƿ��ظ�
                if (!isRepeat(S, sno)) {
                    done = false;
                }
            }

        }
    }

    std::cout << "������������";
    std::cin >> name;

    std::cout << "���������䣺";
    while (true) {
        std::cin >> age;
        // �������С��0����������Ĳ������֣���ô����������
        if (age < 0 || std::cin.fail()) {
            std::cout << "���������������������:";
            // �������״̬
            std::cin.clear();
            // ������Ч������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "�������Ա�";
    while (true) {
        std::cin >> gender;
        // ����Ա𲻵��� �� �� Ů ����������
        if (gender != "��" && gender != "Ů") {
            std::cout << "�Ա������������������:";
            // �������״̬
            std::cin.clear();
            // ������Ч������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "������������ڣ�";
    std::cin >> birthday;

    std::cout << "�������ͥסַ��";
    std::cin >> address;

    std::cout << "�������ֻ��ţ�";
    while (true) {
        std::cin >> phone;
        // ����Ա𲻵��� �� �� Ů ����������
        if (phone.length() != 11) {
            std::cout << "�ֻ��������������������:";
            // �������״̬
            std::cin.clear();
            // ������Ч������
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "���������䣺";
    std::cin >> email;

    info.sno = sno;
    info.name = name;
    info.age = age;
    info.gender = gender;
    info.birthday = birthday;
    info.address = address;
    info.phone = phone;
    info.email = email;

    return info;
}


/**
 * �ӿ���̨����ѧ����Ϣ�����ڲ���ѧ��ʱ����ѧ�Ż���������ʾ�ʣ��������������
 * @param tips  ��ʾ�ʣ�Ĭ��Ϊ��ѧ�Ż�����
 * @return string
 */
string inputTips(string tips = "ѧ�Ż�����") {
    string str;
    std::cout << "������" << tips << "��";
    std::cin >> str;
    return str;
}

/**
 * �ӿ���̨����ѧ����Ϣ,���ڸ���ʱ���룬��������������
 * @param student *info ѧ����Ϣ
 * @return student  ����ѧ����Ϣ
 */
Info inputUpdateInfo(Info info) {
    Info stu = info;
    bool done = true;
    while (done) {
        std::cout << endl;
        std::cout << "��ѡ����ҪҪ�޸�ѧ������Ϣ: " << endl;
        std::cout << "========================= �޸�ѧ����Ϣstart ==========================" << endl;
        std::cout << "1������" << endl;
        std::cout << "2������" << endl;
        std::cout << "3���Ա�" << endl;
        std::cout << "4����������" << endl;
        std::cout << "5����ͥסַ" << endl;
        std::cout << "6���绰" << endl;
        std::cout << "7������" << endl;
        std::cout << "8��ȫ����Ϣ" << endl;
        std::cout << "0�����沢����" << endl;
        std::cout << "========================= �޸�ѧ����Ϣend ===========================" << endl;
        std::cout << endl;

        std::cout << "���������ѡ��";

        int choice;
        std::cin >> choice;


        switch (choice) {
            case 1:
                std::cout << "������������";
                std::cin >> stu.name;
                break;
            case 2:
                std::cout << "���������䣺";
                std::cin >> stu.age;
                break;
            case 3:
                std::cout << "�������Ա�";
                std::cin >> stu.gender;
                break;
            case 4:
                std::cout << "������������ڣ�";
                std::cin >> stu.birthday;
                break;
            case 5:
                std::cout << "�������ͥסַ��";
                std::cin >> stu.address;
                break;
            case 6:
                std::cout << "������绰��";
                std::cin >> stu.phone;
                break;
            case 7:
                std::cout << "���������䣺";
                std::cin >> stu.email;
                break;
            case 8:
                stu = inputInfo(true);
                break;
            case 0:
                std::cout << "���ڱ�����..." << endl;
                done = false;
                break;
            default:
                std::cout << "�����������������" << endl;
                break;
        }
    }
    return stu;
}


/**
 * �ӿ���̨�����������ͣ���������ʱ������������
 * @return  Sort
 */
Sort inputSort() {
    Sort sort;

    std::cout << "========================= ����ѧ����Ϣstart ==========================" << endl;
    std::cout << "��ѡ������ʽ��" << endl;
    std::cout << "1������ѧ����������" << endl;
    std::cout << "2������ѧ�Ž�������" << endl;
    std::cout << "3������������������" << endl;
    std::cout << "4���������併������" << endl;
    std::cout << "0��ȡ�����򣬷��ز˵�" << endl;
    std::cout << "========================= ����ѧ����Ϣstart ==========================" << endl;
    std::cout << "���������ѡ��";
    int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            sort.type = "sno";
            sort.order = "asc";
            break;
        case 2:
            sort.type = "sno";
            sort.order = "desc";
            break;
        case 3:
            sort.type = "age";
            sort.order = "asc";
            break;
        case 4:
            sort.type = "age";
            sort.order = "desc";
            break;
        case 0:
            break;
        default:
            std::cout << "�����������������" << endl;
            break;
    }

    return sort;
}

/**
 * ��ӡ��ͷ
 * @return void
 */
void printHead() {
    std::cout << "----------------------------------------------------------------------------------" << endl;
    std::cout << TABLE_HEAD << endl;
    std::cout << "----------------------------------------------------------------------------------" << endl;
}


/*
* �������
 * @return void
*/
void init_menu() {
    Student t = {};
    Stu *data;

    // ��ʼ��
    data = t.init();

    // ��ʾ�˵�
    while (true) {
        std::cout << endl;
        std::cout << "========================= ѧ������ϵͳstart ==========================" << endl;
        std::cout << "1. ���ѧ��" << endl;
        std::cout << "2. ɾ��ѧ��" << endl;
        std::cout << "3. �޸�ѧ��" << endl;
        std::cout << "4. ����ѧ��" << endl;
        std::cout << "5. ��ѧ�Ż�����������ʾѧ��" << endl;
        std::cout << "6. ��ʾ����ѧ��" << endl;
        std::cout << "0. �˳�" << endl;
        std::cout << "========================= ѧ������ϵͳend ==========================" << endl;
        std::cout << endl;

        int choice;
        std::cout << "���������ѡ��";
        std::cin >> choice;
        std::cout << endl;

        switch (choice) {
            case 1:
                data = t.add(data, inputInfo(false, data));
//                t.save(data);
                break;
            case 2:
                data = t.del(data, inputTips("��Ҫɾ����ѧ��"));
//                t.save(data);
                break;
            case 3:
                data = t.update(data, inputTips("ѧ��"));
//                t.save(data);
                break;
            case 4:
                t.find(data, inputTips("��Ҫ���ҵ�ѧ����ѧ�Ż�����"), true);
                break;
            case 5:
                data = t.sort(data, inputSort());
                break;
            case 6:
                t.printAll(data);
                break;
            case 0:
                t.save(data);
                exit(0);
            default:
                std::cout << "�����������������" << endl;
                break;
        }
    }
}




