#include "model.h"

/**
 * ���캯��
 * @param fileName  �ļ���
 */
Model::Model(string fileName)
{
    this->fileName = fileName;
}

// /**
//  * ���ļ�
//  * @param mode  ��ģʽ
//  * @return      �ļ���
//  */
// fstream Model::open(std::ios_base::openmode mode) const
// {
//     std::fstream fp(fileName, mode);
//     if (!fp.is_open())
//     {
//         std::cout << "���ļ�ʧ�ܣ�" << fileName << std::endl;
//     }
//     return fp;
// }

/**
 * �����ļ�
 * @param data  ����
 * @return      void
 */
void Model::save(student *data)
{
    // д�� db Ŀ¼�µ� student �ļ�
    fstream fp;
    fp.open(fileName, std::ios::out | std::ios::app | std::ios::binary);

    if (fp.is_open())
    {
        fp.write((char *)data, sizeof(student));
        // ÿ��д�껻��
        fp << std::endl;
    }

    fp.close();
}

/**
 * ����ѧ��ɾ��ѧ��
 * @param data  ����
 * @return      void
 */
void Model::dele(student *data)
{
    fstream fp, fp2;
    // ��ȡ db Ŀ¼�µ� student.bin �ļ�
    fp.open("db/student.bin", ios::in | ios::binary);
    // ��ʱ�ļ������ڴ洢ɾ���������
    fp2.open("db/temp.bin", ios::out | ios::binary);

    student *stu = NULL;

    while (fp && fp.read((char *)stu, sizeof(student)))
    {
        // ���ѧ�Ų���ȣ���д����ʱ�ļ�
        if (stu->sno != data->sno)
        {
            // д���ļ�
            fp2.write((char *)stu, sizeof(student));
        }
    }

    fp.close();
    fp2.close();

    // ɾ��ԭ�ļ�
    remove(fileName.c_str());
    // ��������ʱ�ļ�
    rename("db/temp.bin", fileName.c_str());
}

/**
 * ����ѧ���޸�ѧ����Ϣ
 * @param data  ����
 * @return      void
 */
void Model::update(student *data)
{
    fstream fp, fp2;
    // ��ȡ db Ŀ¼�µ� student.bin �ļ�
    fp.open("db/student.bin", ios::in | ios::binary);
    // ��ʱ�ļ������ڴ洢ɾ���������
    fp2.open("db/temp.bin", ios::out | ios::binary);

    student *stu = NULL;

    while (fp && fp.read((char *)stu, sizeof(student)))
    {
        // ���ѧ�Ų���ȣ���д����ʱ�ļ�
        if (stu->sno != data->sno)
        {
            // д���ļ�
            fp2.write((char *)stu, sizeof(student));
        }
        else
        {
            // д���ļ�
            fp2.write((char *)data, sizeof(student));
        }
    }

    fp.close();
    fp2.close();

    // ɾ��ԭ�ļ�
    remove(fileName.c_str());
    // ��������ʱ�ļ�
    rename("db/temp.bin", fileName.c_str());
}