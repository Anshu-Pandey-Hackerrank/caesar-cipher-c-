#ifndef PERSON_PERSON_HPP
#define PERSON_PERSON_HPP

#include <json/json.h>

class Person {
public:
  Person(std::string file_name);

  std::string getFirstName();
  std::string getLastName();
  std::string getSsn();
private:
  Json::Value _person;
};

#endif // PERSON_PERSON_HPP
