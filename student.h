#include <stdlib.h>
#include <stdio.h>

#define datatype int                    // ������������

#define MAX_BUFFER_LEN  20              // ������󻺳�������
#define MAX_ADDRESS_LEN 100             // ��������ַ����

typedef struct stu{
    char sno[MAX_BUFFER_LEN];           // ѧ��
    char name[MAX_BUFFER_LEN];          // ����
    datatype age;                       // ����
    char gender[2];                     // �Ա�
    char birthday[MAX_BUFFER_LEN];      // ��������
    char address[MAX_ADDRESS_LEN];      // ��ͥסַ
    char phone[MAX_BUFFER_LEN];         // �绰
    char email[MAX_BUFFER_LEN];         // ����
    datatype total;                     // ѧ������
    struct stu *next;                   // ָ����һ��ѧ����ָ��
} student;