#include <stdio.h>
#include <string.h>

struct s_student
{
  int age;
  char name[40];
};

void student_init(struct s_student *this, int _age, const char* _name)
{
    strcpy(this->name, _name);
    this->age = _age;
    printf("I AM CREATED: %s - %d\n", this->name, this->age);
}

void student_aging(struct s_student *this)
{
      (this->age)++;
      printf("%s: I'm now %d years old.\n", this->name, this->age);
}

void student_print(const struct s_student *this)
{
    printf("%s - %d\n", this->name, this->age);
}

void student_destuct(struct s_student *this)
{
    printf("I AM DESTROYED. ");
    student_print(this);
}

int main()
{
    struct s_student petya;
    struct s_student vasya;

    student_print(&petya);

    student_init(&petya, 17, "Petya"); // init Petya
    student_aging(&petya);

    student_init(&vasya, 18, "Vasya"); // Create Vasya
    student_aging(&vasya);

    student_destuct(&petya);
    student_destuct(&vasya);
}
