#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "student.h"

using namespace std;

class Model {
public:
    Model(string fileName);           // ���캯��
    // fstream open(std::ios_base::openmode mode = std::ios::in | std::ios::binary) const; // ���ļ�
    void save(student *data);         // �����ļ�
    void dele(student *data);         //  ����ѧ��ɾ��ѧ��
    void update(student *data);       //  ����ѧ�Ÿ���ѧ��

private:
    string fileName;

};

