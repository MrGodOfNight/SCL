#include <iostream>
#include "../modules/randomizer/randomizer.hpp"

int main()
{
  //randomizer test
  SCL::Randomizer random;

  //int test
  std::cout << "random int 1: " << random.randomInt(0, 10) << std::endl;
  std::cout << "random int 2: " << random.randomInt(0, 10) << std::endl;
  std::cout << "random int 3: " << random.randomInt(0, 10) << std::endl;
  std::cout << "random int 4: " << random.randomInt(0, 10) << std::endl;
  std::cout << "random int 5: " << random.randomInt(0, 10) << std::endl;

  //float test
  std::cout << "random float 1: " << random.randomFloat(0.0, 10.0) << std::endl;
  std::cout << "random float 2: " << random.randomFloat(0.0, 10.0) << std::endl;
  std::cout << "random float 3: " << random.randomFloat(0.0, 10.0) << std::endl;
  std::cout << "random float 4: " << random.randomFloat(0.0, 10.0) << std::endl;
  std::cout << "random float 5: " << random.randomFloat(0.0, 10.0) << std::endl;

  //double test
  std::cout << "random double 1: " << random.randomDouble(0.0, 10.0) << std::endl;
  std::cout << "random double 2: " << random.randomDouble(0.0, 10.0) << std::endl;
  std::cout << "random double 3: " << random.randomDouble(0.0, 10.0) << std::endl;
  std::cout << "random double 4: " << random.randomDouble(0.0, 10.0) << std::endl;
  std::cout << "random double 5: " << random.randomDouble(0.0, 10.0) << std::endl;

  //bool test
  std::cout << "random bool 1: " << random.randomBool() << std::endl;
  std::cout << "random bool 2: " << random.randomBool() << std::endl;
  std::cout << "random bool 3: " << random.randomBool() << std::endl;
  std::cout << "random bool 4: " << random.randomBool() << std::endl;
  std::cout << "random bool 5: " << random.randomBool() << std::endl;

  return 0;
}