#include <bits/stdc++.h>
using namespace std;

class Animal{
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Dog barks" << endl;
    }
};

class Cat : public Animal {
public:
    void speak() override {
        cout << "Cat meows" << endl;
    }
};

int main() {
    Animal myAnimal;
    myAnimal.speak();

    Dog myDog;
    myDog.speak();

    Cat myCat;
    myCat.speak();

    Animal* animalPtr;

    animalPtr = &myDog;
    animalPtr->speak();

    animalPtr = &myCat;
    animalPtr->speak();

    return 0;
}