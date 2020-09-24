#include "classes.h"
#include <iostream>
#include <string>

int main() {
    Person* person = new Employee("Bob", 50, 175); //[0]

    person->print();//[1]

    delete person;//[2]

    return 0;
}

/*
Here's my understanding of some things.

0. I changed 'employee' to 'person' because the pointer could potentially be used to point to many different derived
classes of the base "Person" class. For example: customers, volunteers, students... etc.

1. The benefit of using a pointer from the base class is that when we point it to a derived class, the derived class's
functions can override virtual functions of the base class. Calling print() on the base pointer can do different things
depending on where that pointer is pointing. Is this a basic implementation of polymorphism? I think there's more to it than this.

2. Ok so here we're running delete person - does this actually only run on the derived class because the base class's
destructor function is virtual and we override it? When stepping through the code in the debugger, it looks like both functions are visited.
More to learn!

*/
