#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

#include "student.h"

using namespace std;

class Model {
public:
    Model(string fileName);           // 构造函数
    // fstream open(std::ios_base::openmode mode = std::ios::in | std::ios::binary) const; // 打开文件
    void save(student *data);         // 保存文件
    void dele(student *data);         //  根据学号删除学生
    void update(student *data);       //  根据学号更新学生

private:
    string fileName;

};

