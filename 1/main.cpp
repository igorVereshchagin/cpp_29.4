#include <iostream>
#include <string>

class Animal
{
public:
  virtual std::string greeting(Animal* someBody) = 0;
};

class Dog : virtual public Animal
{
public:
  std::string greeting(Animal *someBody);
};

class Cat : virtual public Animal
{
public:
  std::string greeting(Animal* someBody);
};

std::string Cat::greeting(Animal* someBody)
{
  if (nullptr != dynamic_cast<Dog*>(someBody))
    return "Meow";
  else if (nullptr != dynamic_cast<Cat*>(someBody))
    return "Purr";
  else
    return "Who are you?";
}

std::string Dog::greeting(Animal* someBody)
{
  if (nullptr != dynamic_cast<Dog*>(someBody))
    return "Woof";
  else if (nullptr != dynamic_cast<Cat*>(someBody))
    return "Bark";
  else
    return "Who are you?";
}

void meeting(Animal* x, Animal* y)
{
  std::cout << x->greeting(y) << " " << y->greeting(x) << std::endl;
}

int main()
{
  Animal* d1 = new Dog();
  Animal* d2 = new Dog();
  Animal* c1 = new Cat();
  Animal* c2 = new Cat();
  meeting(d1,d2);
  meeting(d1,c1);
  meeting(c1,d1);
  meeting(c1,c2);
  return 0;
}
