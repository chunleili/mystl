#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mystl/vector.hpp"

using namespace mystl;

TEST_CASE("vector_capacity")
{
    mystl::vector v(10);
    REQUIRE(v.capacity()==10);
}

TEST_CASE("vector_size")
{
    mystl::vector v(10);
    REQUIRE(v.size()==0);
}