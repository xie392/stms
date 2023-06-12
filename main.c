#include "student.c"

int main() {
    student *s = NULL;
//    init(s);

    while (1) {
        printf("========================= 学生管理系统start ==========================\n");
        printf("1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生\n");
        printf("4. 查找学生\n");
        printf("5. 显示所有学生\n");
        printf("0. 退出\n");
        printf("========================= 学生管理系统end   ==========================\n");
        printf("\n");

        int choice;
        printf("请输入选项：");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(s);
                break;
            case 0:
                exit(0);
            default:
                // 释放内存
                free(s);
                printf("输入错误，请重新输入\n");
                break;
        }
    }

    return 0;
}
