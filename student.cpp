#include<iostream>

struct Student
{
  int age;
  std::string name;

  Student(int _age, const std::string& _name)
  {
      name = _name;
      age = _age;
      std::cout << "I AM CREATED: " << name << "-" << age << std::endl;
  }

  void aging()
  {
      age++;
      std::cout << name << ": I'm now " << age << " years old" << "\n";
  }

  void print() const    // We cannot change the object itself
  {
      std::cout << name << "-" << age << "\n";
  }

  ~Student()
  {
      std::cout << "I AM DESTROYED. ";
      print();
  }
};

int main()
{
    Student c(17, "Petya"); // Create Petya
    c.aging();
    {
        Student b(18, "Vasya"); // Create Vasya
        b.aging();
    }   // Destroy Vasya
}   // Destroy Petya
