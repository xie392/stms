#include <limits>
#include "student.h"

/**
*  判断学号是否重复
 *  @param Stu *S 学生信息
 *  @param string sno 学号
 *  @return bool
*/
bool isRepeat(Stu *S, string sno) {
    bool is_Repeat = false;
    Stu *p = S;

    while (p) {
        // 如果找到该学生，说明已经重复了
        if (p->info.sno == sno) {
            is_Repeat = true;
            break;
        }
        p = p->next;
    }

    return is_Repeat;
}


/**
 * 从控制台输入学生信息，用于添加学生时输入，返回输入后的内容
 * @param bool isUpdate 是否是更新学生信息，默认为false
 * @param Stu *S  学生信息
 * @return Info
*/
Info inputInfo(bool isUpdate = false, Stu *S = NULL) {
    Info info;
    string sno, name, gender, birthday, address, phone, email;
    int age;

    if (!isUpdate) {
        std::cout << "请输入学号：";
        std::cin >> sno;

        bool is_repeat = isRepeat(S, info.sno);
        // 检查学号是否重复
        if (is_repeat) {
            bool done = true;
            std::cout << "该学号已重复，请重新输入新的学号或退出添加(y/其他字符):";

            string choice;
            std::cin >> choice;

            if (choice == "y" || choice == "Y") {
                done = true;
            } else {
                return Info();
            }
            while (done) {
                std::cout << "请输入新的学号：";
                std::cin >> sno;
                // 递归回去判断是否重复
                if (!isRepeat(S, sno)) {
                    done = false;
                }
            }

        }
    }

    std::cout << "请输入姓名：";
    std::cin >> name;

    std::cout << "请输入年龄：";
    while (true) {
        std::cin >> age;
        // 如果年龄小于0，或者输入的不是数字，那么就重新输入
        if (age < 0 || std::cin.fail()) {
            std::cout << "年龄输入错误，请重新输入:";
            // 清除错误状态
            std::cin.clear();
            // 忽略无效的输入
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "请输入性别：";
    while (true) {
        std::cin >> gender;
        // 如果性别不等于 男 或 女 就重新输入
        if (gender != "男" && gender != "女") {
            std::cout << "性别输入错误，请重新输入:";
            // 清除错误状态
            std::cin.clear();
            // 忽略无效的输入
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "请输入出生日期：";
    std::cin >> birthday;

    std::cout << "请输入家庭住址：";
    std::cin >> address;

    std::cout << "请输入手机号：";
    while (true) {
        std::cin >> phone;
        // 如果性别不等于 男 或 女 就重新输入
        if (phone.length() != 11) {
            std::cout << "手机号输入错误，请重新输入:";
            // 清除错误状态
            std::cin.clear();
            // 忽略无效的输入
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            break;
        }
    }

    std::cout << "请输入邮箱：";
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
 * 从控制台输入学生信息，用于查找学生时输入学号或者姓名提示词，返回输入的内容
 * @param tips  提示词，默认为：学号或姓名
 * @return string
 */
string inputTips(string tips = "学号或姓名") {
    string str;
    std::cout << "请输入" << tips << "：";
    std::cin >> str;
    return str;
}

/**
 * 从控制台输入学生信息,用于更新时输入，返回输入后的内容
 * @param student *info 学生信息
 * @return student  返回学生信息
 */
Info inputUpdateInfo(Info info) {
    Info stu = info;
    bool done = true;
    while (done) {
        std::cout << endl;
        std::cout << "请选择你要要修改学生的信息: " << endl;
        std::cout << "========================= 修改学生信息start ==========================" << endl;
        std::cout << "1、姓名" << endl;
        std::cout << "2、年龄" << endl;
        std::cout << "3、性别" << endl;
        std::cout << "4、出生日期" << endl;
        std::cout << "5、家庭住址" << endl;
        std::cout << "6、电话" << endl;
        std::cout << "7、邮箱" << endl;
        std::cout << "8、全部信息" << endl;
        std::cout << "0、保存并返回" << endl;
        std::cout << "========================= 修改学生信息end ===========================" << endl;
        std::cout << endl;

        std::cout << "请输入你的选择：";

        int choice;
        std::cin >> choice;


        switch (choice) {
            case 1:
                std::cout << "请输入姓名：";
                std::cin >> stu.name;
                break;
            case 2:
                std::cout << "请输入年龄：";
                std::cin >> stu.age;
                break;
            case 3:
                std::cout << "请输入性别：";
                std::cin >> stu.gender;
                break;
            case 4:
                std::cout << "请输入出生日期：";
                std::cin >> stu.birthday;
                break;
            case 5:
                std::cout << "请输入家庭住址：";
                std::cin >> stu.address;
                break;
            case 6:
                std::cout << "请输入电话：";
                std::cin >> stu.phone;
                break;
            case 7:
                std::cout << "请输入邮箱：";
                std::cin >> stu.email;
                break;
            case 8:
                stu = inputInfo(true);
                break;
            case 0:
                std::cout << "正在保存中..." << endl;
                done = false;
                break;
            default:
                std::cout << "输入错误，请重新输入" << endl;
                break;
        }
    }
    return stu;
}


/**
 * 从控制台输入排序类型，用于排序时输入排序类型
 * @return  Sort
 */
Sort inputSort() {
    Sort sort;

    std::cout << "========================= 排序学生信息start ==========================" << endl;
    std::cout << "请选择排序方式：" << endl;
    std::cout << "1、按照学号升序排序" << endl;
    std::cout << "2、按照学号降序排序" << endl;
    std::cout << "3、按照年龄升序排序" << endl;
    std::cout << "4、按照年龄降序排序" << endl;
    std::cout << "0、取消排序，返回菜单" << endl;
    std::cout << "========================= 排序学生信息start ==========================" << endl;
    std::cout << "请输入你的选择：";
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
            std::cout << "输入错误，请重新输入" << endl;
            break;
    }

    return sort;
}

/**
 * 打印表头
 * @return void
 */
void printHead() {
    std::cout << "----------------------------------------------------------------------------------" << endl;
    std::cout << TABLE_HEAD << endl;
    std::cout << "----------------------------------------------------------------------------------" << endl;
}


/*
* 程序入口
 * @return void
*/
void init_menu() {
    Student t = {};
    Stu *data;

    // 初始化
    data = t.init();

    // 显示菜单
    while (true) {
        std::cout << endl;
        std::cout << "========================= 学生管理系统start ==========================" << endl;
        std::cout << "1. 添加学生" << endl;
        std::cout << "2. 删除学生" << endl;
        std::cout << "3. 修改学生" << endl;
        std::cout << "4. 查找学生" << endl;
        std::cout << "5. 按学号或姓名排序显示学生" << endl;
        std::cout << "6. 显示所有学生" << endl;
        std::cout << "0. 退出" << endl;
        std::cout << "========================= 学生管理系统end ==========================" << endl;
        std::cout << endl;

        int choice;
        std::cout << "请输入你的选择：";
        std::cin >> choice;
        std::cout << endl;

        switch (choice) {
            case 1:
                data = t.add(data, inputInfo(false, data));
//                t.save(data);
                break;
            case 2:
                data = t.del(data, inputTips("你要删除的学号"));
//                t.save(data);
                break;
            case 3:
                data = t.update(data, inputTips("学号"));
//                t.save(data);
                break;
            case 4:
                t.find(data, inputTips("你要查找的学生的学号或姓名"), true);
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
                std::cout << "输入错误，请重新输入" << endl;
                break;
        }
    }
}




