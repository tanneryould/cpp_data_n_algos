#ifndef CLASSES_H
#define CLASSES_H

#include <string>

class Person {
private:
    int m_age;
    std::string m_name;
public:
    Person() = default;
    virtual ~Person() = default;
    void set_age(int age);
    int get_age();

    void set_name(std::string name);
    std::string get_name();

    virtual void print();
};

class Employee : public Person {
private:
    int m_employeeId;
public:
    Employee(std::string name="", int age=-1, int employee_id=-1);
    ~Employee() = default;
    void set_employeeId(int id);
    int get_employeeId();

    void print() override;
};

#endif // CLASSES_H
