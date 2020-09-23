// So here's the solution to the code challenge I was presented with, brimming with comments to show
// my thinking process and also show that I didn't just copy and paste things -- I actually took the time
// to learn this. There's still a lot to learn and I hope to get the chance to do that.
// - Tanner

// Instructions:
// You may change anything in the code. Focus on:
// 1. Fix any compile errors.
// 2. Get the expected output.
// 3. Use proper OO techniques.
// 4. Identify and fix problems with the code that are not compiler errors.

// Expectation - code must print:
// name: Bob
// age: 50
// employee id: 175


#include <string>
#include <iostream>

// using namespace std;
/*
I decided to comment this out because I've read that "using namespace std" may not be a best practice.
I read one article somewhere that said something about loading in a bunch of functionality that will
just bloat the program but the main concern seems to be the posibility of conflicting namespaces.

After doing a small amount of research "using namespace std" can cause conflicts.
From what I understand, say we have std::string and foo::string, if we went on to declare a string, it would
use foo::string and not std::string. Better to be explict I suppose - easier for bug fixing.
source: https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

I'm curious what your team thinks about this.
*/

class Person
{
public:
  Person() // Constructor
  {
  }

  ~Person() = default; // Destructor
  /*A destructor is a special member function that is called when the
  lifetime of an object ends. The purpose of the destructor is to free
  the resources that the object may have acquired during its lifetime.

  https://en.cppreference.com/w/cpp/language/destructor
  */

  void print()
  {
    std::cout << "name: " << m_name << std::endl;
    std::cout << "age: "  << m_age  << std::endl;
  }
  // We can instantiate these variables after the print() function because
  // we don't need them until the print() function is actually called.
  int m_age;
  std::string m_name;
  /* I probably would have done just age and name instead of m_age and m_name to be clearer. Is there a
     reason for the 'm's? Also would we want to define these as consts? If this were some sort of database
     probably not, because what if the user changes their name? Oh and their age will certainly increase. */
};

class Employee : public Person
{
public:
  Employee()
  {
  }

  ~Employee() = default; // Hey, this is called when we run delete pointer. Neat!

  void print() // Turns out you can have the same function name in a child class.
  {
    Person::print(); // Call this function from the parent class.
    std::cout << "employee id: " << m_employeeId << std::endl;
  }

  int m_employeeId;
};

int main()
{
  const std::string name = "Bob";
  constexpr int age = 50;
  constexpr int employeeId = 175;

  /*
  A constant expression is an expression whose value cannot
  change and that can be evaluated at compile time. A literal is a
  constant expression. A const object that is initialized from a constant
  expression is also a constant expression. As we’ll see, there are several
  contexts in the language that require constant expressions.

  C++ Primer, Fifth Edition, page 102-103

  Also strings can't be given the constexpr declaration for reasons that I don't yet understand.
  */

  /*Previously:
  Person* employee = new Employee();

  Didn't work because employee was declared as Person.
  After some tests, I noticed that using type Person doesn't cause a compiler error as long as
  we don't try to set an employeeId and print() will just run the function in the Person class.
  So what exactly is new Employee()? Space allocated for that particular class?
  */
  Employee* employee = new Employee();
    /* new Employee works with or without a trailing ()
     This probably would work if there was a constructor
     that asked for parameters */

    /* Also why pointers over just objects?
    It seems as though objects are given automatic storage duration and will be
    destroyed after we go out of scope whereas pointers need to be explicitly
    created and destroyed.
    So why use a pointer here over an object? Just to test syntax?
    */

    /*
    Also what of other types of pointers (unique, smart, etc)? People seem to discourage using
    raw pointers. https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
    */

  /* Previously:
  employee.name = name;
  employee.age = age;
  employee.employeeId = employeeId;

  employee.print();

  The above didn't work because instead of dot notation
  we use "->" to point to where we want to assign the value.

  Also because it should be "m_name" etc that we're assigning.

  To the best of my knowledge, this would have worked if we hadn't
  used a pointer in our instantiation of employee.
  (ie Employee employee;)

  */

  /* Regarding below. Would it be better for the overall app size if we defined these in
     the constructor rather than defining variables and then setting them
     to the object's member variables? Is this where pointers come in handy? */
  employee->m_name = name;
  employee->m_age = age;
  employee->m_employeeId = employeeId;

  employee->print();

  delete employee;
  /* I need to study "delete" more but from what I understand, it can free up the
     memory that the pointer... points to and allow other variables to occupy it?
     I know that if we don't, the object will be persistant even outside current scope.
    */

  return 0;
}
