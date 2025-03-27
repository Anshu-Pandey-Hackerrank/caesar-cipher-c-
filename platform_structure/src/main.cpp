#include <iostream>

#include "include/person.hpp"

int main(int argc, char* argv[])
{
  std::string file_name;

  if (argc == 2) {
    file_name = argv[1];
  } else {
    std::cout << "Invalid command line arguments provided\n";
    std::cout << "Please provide the JSON file name\n";

    return 1;
  }

  Person person(file_name);

  std::cout << "First Name: " << person.getFirstName() << std::endl;
  std::cout << "Last Name:  " << person.getLastName() << std::endl;
  std::cout << "Ssn:        " << person.getSsn() << std::endl;

  return 0;
}
