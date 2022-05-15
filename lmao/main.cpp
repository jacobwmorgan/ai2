#include <iostream>
#include <Animal.h>

int main(int, char**) {
    Animal *a = new Animal();
    std::cout << a->getName() << "\n";
    std::cout << "lmao, world!\n";
}
