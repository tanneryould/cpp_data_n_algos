#include "classes.h"
#include <iostream>

void Person::set_age(int age) {
    m_age = age;
}

int Person::get_age() {
    return m_age;
}

void Person::set_name(std::string name) {
    m_name = name;
}

std::string Person::get_name() {
    return m_name;
}

void Person::print() {
    std::cout << m_name;
    std::cout << m_age;
}

Employee::Employee(std::string name, int age, int employee_id) {
    set_name(name);
    set_age(age);
    set_employeeId(employee_id);
}
void Employee::set_employeeId(int id) {
    m_employeeId = id;
}

int Employee::get_employeeId() {
    return m_employeeId;
}

void Employee::print() {
    std::cout << "name: " << get_name() << std::endl;
    std::cout << "age: " << get_age() << std::endl;
    std::cout << "employee id: " << get_employeeId() << std::endl;
}
