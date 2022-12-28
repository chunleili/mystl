#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "mystl/vec3.hpp"

#include <vector>

using namespace mystl;

TEST_CASE("vec3 correctly construct", "[vec3]")
{
    SECTION( "constructing using 3 val3" ) 
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.x==1);
        REQUIRE(v.y==2);
        REQUIRE(v.z==3);
    }

    SECTION( "constructing using 1 val" ) 
    {
        mystl::vec3 v(1);
        REQUIRE(v.x==1);
        REQUIRE(v.y==1);
        REQUIRE(v.z==1);
    }

    SECTION( "constructing with empty" ) 
    {
        mystl::vec3 v;
    }

    SECTION( "constructing with double" ) 
    {
        double x = 1.0;
        mystl::vec3 v(x);
        REQUIRE(v.x==1);
        REQUIRE(v.y==1);
        REQUIRE(v.z==1);
    }

    SECTION( "constructing with 3 double" ) 
    {
        double x = 1.0, y = 1.0, z = 1.0;
        mystl::vec3 v(x,y,z);
        REQUIRE(v.x==1);
        REQUIRE(v.y==1);
        REQUIRE(v.z==1);
    }
}


TEST_CASE("vec3 correctly copy", "[vec3]")
{
    SECTION( "copy constructor" ) 
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(v);
        REQUIRE(v2.x==1);
        REQUIRE(v2.y==2);
        REQUIRE(v2.z==3);
    }

    SECTION( "copy assignment" ) 
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2 = v;
        REQUIRE(v2.x==1);
        REQUIRE(v2.y==2);
        REQUIRE(v2.z==3);
    }

    SECTION( "afterwards copy assignment" ) 
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2;
        v2 = v;
        REQUIRE(v2.x==1);
        REQUIRE(v2.y==2);
        REQUIRE(v2.z==3);
    }
}


TEST_CASE("ostream", "[vec3]")
{
    SECTION( "ostream" ) 
    {
        mystl::vec3 v(1,2,3);
        
        std::cout <<"vec3 is: "<< v << std::endl;
    }
}

TEST_CASE("work with vector", "[vec3]")
{
    SECTION( "std vector" ) 
    {
        std::vector<mystl::vec3> vv(3);
        vv[1] = mystl::vec3(1,2,3);
        REQUIRE(vv[1].x==1);
        REQUIRE(vv[1].y==2);
        REQUIRE(vv[1].z==3);

        std::cout <<"std::vector<mystl::vec3> is: \n";
        for(auto v: vv)
            std::cout << v << std::endl;
    }
}


TEST_CASE("norm", "[vec3]")
{
    SECTION( "norm" ) 
    {
        mystl::vec3 v(1,2,3);
        //其中Approx(14)是期望值，epsilon(0.0001)是允许的误差范围, 0.0001是相对误差, 即原始值的0.1%
        REQUIRE(v.norm()==Approx(std::sqrt(14)).epsilon(0.0001));
    }

    SECTION( "length" ) 
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.length()==Approx(std::sqrt(14)).epsilon(0.0001));
    }

    SECTION( "magnitude" ) 
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.magnitude()==Approx(std::sqrt(14)).epsilon(0.0001));
    }

    SECTION( "normSqr" ) 
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.normSqr()==Approx(14).epsilon(0.0001));
    }

    SECTION( "lengthSqr" ) 
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.lengthSqr()==Approx(14).epsilon(0.0001));
    }

    SECTION( "normalize" ) 
    {
        mystl::vec3 v(1,2,3);
        float length = std::sqrt(14);
        float x_normalized = 1.0/length;
        float y_normalized = 2.0/length;
        float z_normalized = 3.0/length;
        REQUIRE(v.normalize().x==Approx(x_normalized).epsilon(0.0001));
        REQUIRE(v.normalize().y==Approx(y_normalized).epsilon(0.0001));
        REQUIRE(v.normalize().z==Approx(z_normalized).epsilon(0.0001));
    }

}