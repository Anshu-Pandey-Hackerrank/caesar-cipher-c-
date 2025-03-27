#include <fstream>

#include "person.hpp"

Person::Person(std::string file_name)
{
  std::ifstream person_file(file_name, std::ifstream::binary);
  person_file >> _person;
}

std::string Person::getFirstName()
{
  // write code here
  return "";
}

std::string Person::getLastName()
{
  // write code here
  return "";
}

std::string Person::getSsn()
{
  // write code here
  return "";
}
