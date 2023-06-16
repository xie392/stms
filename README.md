# һ����������

ѧ����Ϣ����:ѧ�š����������䡢�Ա𡢳������¡���ַ���绰�� E-mail�ȡ������һ��ѧ����Ϣ�������ʵ��ѧ����Ϣ�ĵ��ӻ�����Ҫ��:ʹ���ļ���ʽ�洢����,����������֯ѧ�����ݡ�

# �������˼· 

- 1�����ѧ���ĸ�����Ϣ����ѧ�š����������䡢�Ա𡢳������¡���ַ���绰�� E-mail��
- 2����ѯѧ����Ϣ�����Ը���ѧ�Ż���������ѯѧ����Ϣ
- 3��ɾ��ѧ����Ϣ�����Ը���ѧ��ɾ��ѧ����Ϣ
- 4���޸�ѧ����Ϣ�����Ը���ѧ�ź�ѧ��������Ҫ�޸ĵ�ѧ����Ϣ��Ȼ��ѡ���޸���Ӧ������
- 5������ѧ����Ϣ������ѧ����ѧ�Ż���������Ӧ����

# �������ݽṹ����

## 1������ÿ��ȫ�ֱ�����ṹ��

`student.h` ��Ҫ��������һЩȫ�ֱ����ͽṹ��

```c_cpp
#define FILE_NAME "data.bin"
#define TABLE_HEAD "ѧ��     ����    ����    �Ա�    ��������     ��ͥסַ     �绰           ����  "

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
```

## 2������ѧ����

���������д������ѧ���࣬�����ݴ�����`student.h`

```c_cpp
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
```

## 3��ͨ�÷�������Ҫ�������̨����

`input.cpp` ��Ҫ����һЩ�Ƚϼ򵥺��ظ����߼��������̨�������ʾ��Ϣ���Լ���������

```c_cpp
/**
 * �ӿ���̨����ѧ����Ϣ���������ѧ��ʱ���룬��������������
 * @param bool isUpdate �Ƿ��Ǹ���ѧ����Ϣ��Ĭ��Ϊfalse
 * @return Info
*/
Info inputInfo(bool isUpdate = false);

/**
 * ���ڲ���ѧ��ʱ����ѧ�Ż���������ʾ�ʣ��������������
 * @param tips  ��ʾ�ʣ�Ĭ��Ϊ��ѧ�Ż�����
 * @return string
 */
string inputTips(string tips = "ѧ�Ż�����");

/**
 * �ӿ���̨����ѧ����Ϣ,���ڸ���ʱ���룬��������������
 * @param student *info ѧ����Ϣ
 * @return student  ����ѧ����Ϣ
 */
Info inputUpdateInfo(Info info);

/**
 * �ӿ���̨�����������ͣ���������ʱ������������
 * @return  Sort
 */
Sort inputSort();

/**
*  �ж�ѧ���Ƿ��ظ�
 *  @param Stu *S ѧ����Ϣ
 *  @param string sno ѧ��
 *  @return bool
*/
bool isRepeat(Stu *S, char *sno);

/*
* ������ڣ���ʾϵͳ�˵�
 * @return void
*/
void init_menu();
```

<br/>

# �ġ�������

1. main �������� init_menu;������ʾ���˵���
2. �� init_menu�����а���ʾ���˵�������Ҫ����ָ��������ѧ�����е����ѧ����Ϣ���� add��������ʾ����ѧ����Ϣ����printAll����ѯѧ����Ϣ����find��ɾ��ѧ����Ϣ����del���޸�ѧ������update��������ʾѧ����Ϣ����sort��
3. ���ѧ����Ҫ���ѧ���Ƿ��Ѿ����ڣ���麯��isRepeat����鵽�Ѿ����˸�ѧ�ţ���ʾ�Ӳ˵���ѡ���Ƿ������ӻ����˳���ӣ����������ӣ���ô����������ѧ����Ϣ��
4. ����ѧ�������Һ�����Ϊһ��ͨ�ú��������Դ��ݲ�������ͬ�Ĺ��ܣ����磬������ѧ�Ż���������ֱ�Ӳ���β��㣬���Ҫ����ѧ������ô�ͷ��ز��ҵ���ѧ����
5. ɾ��ѧ�����ȵ��ò��Һ����������Ƿ��и�ѧ�������ҵ�Ҫɾ����ѧ����Ϣ������о�ɾ������֮��ʾû�и�ѧ����Ϣ��
6. �޸�ѧ�����ȵ��ò��Һ����������Ƿ��и�ѧ��������о���ʾ�Ӳ˵����Ӳ˵�����ѡ����Ҫ�޸ĵ�ѧ����Ϣ��
7. ������ʾ����ʾ�Ӳ˵���������Ҫ��������ͣ�����ɹ�����ʾ������������ѧ����Ϣ��Ҳ��ʱ������ʾ������Ϣ����printAll��
8. ��ʾ����ѧ������ӡ����ѧ����Ϣ�����������̨��
9. �˳����򲢱�����Ϣ�������ļ�

<br/>

# �塢��������Է���

## 1����ʾ���˵�ʵ���˻���������

![��ͼ](./images/3de1c90c26ffe6fb281fccce67c165d8.png)

<br/>

## 2�����ѧ����Ϣ

![��ͼ](./images/f9af9990ced6aea2fdcbc1a3cfd97e0e.png)

## 3����ʾ����ѧ����Ϣ��ѧ�Ŵ�С����

![��ͼ](./images/88859f88380c164cbf9fa0d89e290236.png)

## 4����ʾ����ѧ����Ϣ�������С����

![��ͼ](./images/425b375db4f488f07c8f6e8b77e67a72.png)