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
I read one article somewhere that said something about doing this loads in a bunch of functionality that will
just bloat the program but the main concern seems to be the posibility of conflicting namespaces.

After doing a small amount of research, I have found that "using namespace std" can cause conflicts.
From what I understand, say we have namespace std and namespace foo. If they both have a string type
sort of like std::string and foo::string and we went on to declare a string after declaring the namespaces, it would
use foo::string and not std::string. Better to be explict I suppose - easier for bug fixing.
source: https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

I'm curious what your team thinks about this.

Guillaume: "using namespace" is a tricky question. To simplify:
- never in header files
- for source files, follows the coding rules of the project.
For beginers, I recommande to not use "using namespace", to learn which features come from "std".
*/

// Guillaume: the habit in C++ is to split the declaration of the classe in header file and the definition in source file. 
class Person
{
public:
  // Guillaume: here, you can use `= default` too. See (4) in https://en.cppreference.com/w/cpp/language/default_constructor
  Person() // Constructor
  {
  }

  ~Person() = default; // Destructor
  /*
  A destructor is a special member function that is called when the
  lifetime of an object ends. The purpose of the destructor is to free
  the resources that the object may have acquired during its lifetime.

  https://en.cppreference.com/w/cpp/language/destructor
  
  So this is run when we move out of the scope of an object or delete a pointer, yes?
  Guillaume: yes.
  Another point, if a class is used in inheritance, the destructor should be virtual. See C++ Primer, chap 15.7.1.
  */

  // Guillaume: this function should be virtual function in a base class, then it should have `virtual`. See C++ Primer, chap 15.3.
  void print()
  {
    std::cout << "name: " << m_name << std::endl;
    std::cout << "age: "  << m_age  << std::endl;
  }
  /*
  We can instantiate these variables after the print() function because
  we don't need them until the print() function is actually called.
  Guillaume: the order of the declarations is not really important. But:
   - the definition of the function should be in a source file.
   - the member variables should be private. See "encapsulation" concept in C++Primer, chap 7.2.
   - the primitive types (int, float, etc) are not default initialized in C++ (random value). Default initialize them. See C++ Primer, chap 7.1.2.
   */
  int m_age;
  std::string m_name;
  /*
  I probably would have done just age and name instead of m_age and m_name to be clearer. Is there a
  reason for the 'm's? 
  Guillaume: historical reason. Just follow the coding rules of the project. (This coding rule come from the code of Qt, we just follow the same rule).
  Also would we want to define these as consts? If this were some sort of database
  probably not, because what if the user changes their name? Oh and their age will certainly increase. 
  EDIT: No of course we wouldn't define them as consts because consts need have a value at compiling time!
  Guillaume: it's possible to use const here, that depends on the class semantics. But it's not a simple question, it's ok to not use const.
  Note: `const` doesn't mean "const at compile time". The compile time constant is `constexpr`.
  */
};

class Employee : public Person
{
public:
  // Guillaume: same about the use of `= default`.
  Employee()
  {
  }

  ~Employee() = default; // Hey, this is called when we run delete pointer. Neat! (and the same goes for the other destructor)

  // Guillaume: this function should be a virtual function in a child class, then it should have `override`. See C++ Primer, chap 15.2.2.
  void print() // Turns out you can have the same function name in a child class.
  {
    Person::print(); // Call this function from the parent class.
    std::cout << "employee id: " << m_employeeId << std::endl;
  }

  // Guillaume: same, use `private` and default initialization.
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
  expression is also a constant expression.

  C++ Primer, Fifth Edition, page 102

  Also strings can't be given the constexpr declaration and must use const for reasons that I don't yet understand.
  Guillaume: Me too :) In fact, it's hard to write a `constexpr` constructor for strings, then it's not possible to use `constexpr` in this case before C++20.
  */

  /*
  Previously:
  Person* employee = new Employee();

  This didn't work because employee was declared as Person.
  After some tests, I noticed that using type Person* employee = new Employee(); doesn't cause a compiler error as long as
  we don't try to set an employeeId, and print() will just run the function in the Person class.
  So what exactly is new Employee()? Are we just calling the constructor there, and because Person and Employee both have
  empty constructors, they don't cause a compiler error? But if we try Employee* employee = new Person(); we get an error.
  I need to look into this more.
  
  Guillaume: the previous line means we create a "Employee" object and we manipulate it with a pointer to "Person". This is correct, because
  "Employee" IS-AN "Person" in inheritance. "Employee* employee = new Person();" is incorrect, as "Person" is not always an "Employee".
  This is a major concept of the object programming, see "polymorphism" in C++ Primer, chap 15.3.
  
  In "modern" C++, the habit is to avoid to delete manually the objects. Then the previous line should be replaced by:
  std::unique_ptr<Employee> employee = std::make_unique<Employee>(); // C++ Primer, chap 12.1.5.
  or
  auto employee = std::make_unique<Employee>(); // C++ Primer, chap 2.5.2.
  or just: 
  Employee employee; // if there is no reason to use pointer
  */
  
  Employee* employee = new Employee();
  /*
  new Employee works with or without a trailing ()
   This probably would not work without the () if there was a constructor
   that asked for parameters */
  // Guillaume: this is a special syntaxe of `new`, which can be used without ().
  
  /*
  Also why pointers over just objects?
  It seems as though objects are given automatic storage duration and will be
  destroyed after we go out of scope whereas pointers need to be explicitly
  created and destroyed.
  Why use a pointer here over an object? Just to test syntax?
  // Guillaume: yes
  Are there other reasons beyond memory management?

  Also what about other types of pointers (unique, smart, etc)? People seem to discourage using
  raw pointers. https://stackoverflow.com/questions/22146094/why-should-i-use-a-pointer-rather-than-the-object-itself
  // Guillaume: yes. But be careful, Qt is a special case.
  */

  /*
  Previously:
  employee.name = name;
  employee.age = age;
  employee.employeeId = employeeId;

  employee.print();

  The above didn't work because instead of dot notation
  we use "->" to point to where we want to assign the value.
  // Guillaume: yes

  Also because it should be "m_name" etc that we're assigning.
  // Guillaume: yes, but with encapsulation, members should be private and it should not be possible to access to them directly.

  To the best of my knowledge, this dot notation would have worked if we hadn't
  used a pointer in our instantiation of employee.
  (ie Employee employee;)
  // Guillaume: yes
  */

  /* 
  Regarding below. Would it be better for the overall app size if we defined these in
  the constructor rather than defining variables and then passing their values
  to the object's member variables? 
  // Guillaume: yes
  Is this where pointers come in handy, by setting the variable
  once and then pointing to it from the class?
  // Guillaume: no, pointers change nothing for that.
  */
  employee->m_name = name;
  employee->m_age = age;
  employee->m_employeeId = employeeId;

  employee->print();

  delete employee;
  /*
  I need to study "delete" more but from what I understand, it can free up the
  memory that the pointer... points to and allow other variables to occupy it?
  I know that if we don't, whatever's at that memory location will be persistant 
  even outside current scope.
  Guillaume: yes. Note this "delete" must be removed if you're using smart pointers.
  */

  return 0;
}

// Guillaume: some additional notes
// C++ Primer is a big book. If you want a short book (but less pedagogic), you can read "A Tour of C++", Bjarne Stroustrup.
// For Qt, I didn't read the recent books, I can't recommande one of them. But the doc is good: https://doc.qt.io/qt-5/gettingstarted.html
// For QML, there is a good serie of videos in KDAB YouTube channel: https://www.youtube.com/watch?v=JxyTkXLbcV4&list=PL6CJYn40gN6hdNC1IGQZfVI707dh9DPRc&ab_channel=KDAB
