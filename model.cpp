#include "model.h"

/**
 * 构造函数
 * @param fileName  文件名
 */
Model::Model(string fileName)
{
    this->fileName = fileName;
}

// /**
//  * 打开文件
//  * @param mode  打开模式
//  * @return      文件流
//  */
// fstream Model::open(std::ios_base::openmode mode) const
// {
//     std::fstream fp(fileName, mode);
//     if (!fp.is_open())
//     {
//         std::cout << "打开文件失败：" << fileName << std::endl;
//     }
//     return fp;
// }

/**
 * 保存文件
 * @param data  数据
 * @return      void
 */
void Model::save(student *data)
{
    // 写入 db 目录下的 student 文件
    fstream fp;
    fp.open(fileName, std::ios::out | std::ios::app | std::ios::binary);

    if (fp.is_open())
    {
        fp.write((char *)data, sizeof(student));
        // 每次写完换行
        fp << std::endl;
    }

    fp.close();
}

/**
 * 根据学号删除学生
 * @param data  数据
 * @return      void
 */
void Model::dele(student *data)
{
    fstream fp, fp2;
    // 读取 db 目录下的 student.bin 文件
    fp.open("db/student.bin", ios::in | ios::binary);
    // 临时文件，用于存储删除后的数据
    fp2.open("db/temp.bin", ios::out | ios::binary);

    student *stu = NULL;

    while (fp && fp.read((char *)stu, sizeof(student)))
    {
        // 如果学号不相等，就写入临时文件
        if (stu->sno != data->sno)
        {
            // 写入文件
            fp2.write((char *)stu, sizeof(student));
        }
    }

    fp.close();
    fp2.close();

    // 删除原文件
    remove(fileName.c_str());
    // 重命名临时文件
    rename("db/temp.bin", fileName.c_str());
}

/**
 * 根据学号修改学生信息
 * @param data  数据
 * @return      void
 */
void Model::update(student *data)
{
    fstream fp, fp2;
    // 读取 db 目录下的 student.bin 文件
    fp.open("db/student.bin", ios::in | ios::binary);
    // 临时文件，用于存储删除后的数据
    fp2.open("db/temp.bin", ios::out | ios::binary);

    student *stu = NULL;

    while (fp && fp.read((char *)stu, sizeof(student)))
    {
        // 如果学号不相等，就写入临时文件
        if (stu->sno != data->sno)
        {
            // 写入文件
            fp2.write((char *)stu, sizeof(student));
        }
        else
        {
            // 写入文件
            fp2.write((char *)data, sizeof(student));
        }
    }

    fp.close();
    fp2.close();

    // 删除原文件
    remove(fileName.c_str());
    // 重命名临时文件
    rename("db/temp.bin", fileName.c_str());
}