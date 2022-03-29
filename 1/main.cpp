#include <iostream>
#include <string>

class Animal
{
public:
  virtual std::string whoAmI() = 0;
  virtual std::string greeting(const std::string& someBody) = 0;
};

class Dog : virtual public Animal
{
public:
  std::string whoAmI() {return "Dog";}
  std::string greeting(const std::string& someBody)
  {
    if (someBody == "Dog")
      return "Woof";
    else if (someBody == "Cat")
      return "Bark";
    else
      return "Who are you?";
  }
};

class Cat : virtual public Animal
{
public:
  std::string whoAmI() {return "Cat";}
  std::string greeting(const std::string& someBody)
  {
    if (someBody == "Dog")
      return "Meow";
    else if (someBody == "Cat")
      return "Purr";
    else
      return "Who are you?";
  }
};

void meeting(Animal* x, Animal* y)
{
  std::cout << x->greeting(y->whoAmI()) << " " << y->greeting(x->whoAmI()) << std::endl;
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
