#include "classes.h"
#include <iostream>
#include <string>

int main() {
    Pointer* employee = new Employee("Bob", 50, 175);

    employee->print();

    delete employee;

    return 0;
}
