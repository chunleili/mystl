#define CATCH_CONFIG_MAIN
#include "catch.hpp"
TEST_CASE("case1", "subcase1") {
  int actual = 1;
  int expected = 1;
  REQUIRE(actual == expected);
}