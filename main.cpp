#include "student.cpp"
#include "model.cpp"

int main()
{
    Student student{};
    // student.menu(
    stu *s;
    s = (stu *)malloc(sizeof(stu));

    strcpy(s->sno, "2018110101");
    strcpy(s->name, "��444��");
    
    Model model("db/student.bin");
    model.save(s);
    return 0;
};
