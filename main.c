#include "student.c"

int main() {
    student *s = NULL;
//    init(s);

    while (1) {
        printf("========================= ѧ������ϵͳstart ==========================\n");
        printf("1. ���ѧ��\n");
        printf("2. ɾ��ѧ��\n");
        printf("3. �޸�ѧ��\n");
        printf("4. ����ѧ��\n");
        printf("5. ��ʾ����ѧ��\n");
        printf("0. �˳�\n");
        printf("========================= ѧ������ϵͳend   ==========================\n");
        printf("\n");

        int choice;
        printf("������ѡ�");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent(s);
                break;
            case 0:
                exit(0);
            default:
                // �ͷ��ڴ�
                free(s);
                printf("�����������������\n");
                break;
        }
    }

    return 0;
}
