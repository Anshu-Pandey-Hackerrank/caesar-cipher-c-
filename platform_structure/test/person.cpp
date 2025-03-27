#define BOOST_TEST_MODULE person_tests

#include <boost/test/unit_test.hpp>
#include "../src/include/person.hpp"

BOOST_AUTO_TEST_SUITE(tests_suite)

BOOST_AUTO_TEST_CASE(person_first_name_test)
{
  Person person("test/person.json");
  BOOST_CHECK_EQUAL(person.getFirstName(), "John");
}

BOOST_AUTO_TEST_CASE(person_last_name_test)
{
  Person person("test/person.json");
  BOOST_CHECK_EQUAL(person.getLastName(), "Doe");
}

BOOST_AUTO_TEST_CASE(person_ssn_test)
{
  Person person("test/person.json");
  BOOST_CHECK_EQUAL(person.getSsn(), "123456789");
}

BOOST_AUTO_TEST_SUITE_END()
