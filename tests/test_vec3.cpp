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

TEST_CASE("input output", "[vec3]")
{
    SECTION( "ostream" ) 
    {
        mystl::vec3 v(1,2,3);
        std::cout <<"vec3 is: "<< v << std::endl;
    }

}




TEST_CASE("norm", "[vec3]")
{
    SECTION( "norm" ) 
    {
        mystl::vec3 v(1,2,3);
        //其中Approx(14)是期望值，epsilon(0.0001)是允许的误差范围, 0.0001是相对误差, 即原始值的0.01%
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

TEST_CASE("operator", "[vec3]")
{
    SECTION("+")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        mystl::vec3 v3 = v + v2;
        REQUIRE(v3.x==2);
        REQUIRE(v3.y==4);
        REQUIRE(v3.z==6);
    }
    SECTION("-")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        mystl::vec3 v3 = v - v2;
        REQUIRE(v3.x==0);
        REQUIRE(v3.y==0);
        REQUIRE(v3.z==0);
    }
    SECTION("+(with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = v + scalar;
        REQUIRE(v2.x==3);
        REQUIRE(v2.y==4);
        REQUIRE(v2.z==5);
    }
    SECTION("-(with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = v - scalar;
        REQUIRE(v2.x==-1);
        REQUIRE(v2.y==0);
        REQUIRE(v2.z==1);
    }
    SECTION("*(with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = v * scalar;
        REQUIRE(v2.x==2);
        REQUIRE(v2.y==4);
        REQUIRE(v2.z==6);
    }
    SECTION("/(with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = v / scalar;
        REQUIRE(v2.x==0.5);
        REQUIRE(v2.y==1);
        REQUIRE(v2.z==1.5);
    }
    SECTION("+(scalar on the left)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = scalar + v;
        REQUIRE(v2.x==3);
        REQUIRE(v2.y==4);
        REQUIRE(v2.z==5);
    }
    SECTION("-(scalar on the left)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = scalar - v;
        REQUIRE(v2.x==1);
        REQUIRE(v2.y==0);
        REQUIRE(v2.z==-1);
    }
    SECTION("*(scalar on the left)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = scalar * v;
        REQUIRE(v2.x==2);
        REQUIRE(v2.y==4);
        REQUIRE(v2.z==6);
    }
    SECTION("/(scalar on the left)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        mystl::vec3 v2 = scalar / v;
        REQUIRE(v2.x==2);
        REQUIRE(v2.y==1);
        REQUIRE(v2.z==Approx(2.0/3.0).epsilon(0.0001));
    }

    SECTION("*")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        float dot = v * v2;
        REQUIRE(dot == 14);
    }
    SECTION("dot")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        float dot = v.dot(v2);
        REQUIRE(dot==14);
    }
    SECTION("^")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        mystl::vec3 v3 = v^v2;
        REQUIRE(v3.x==0);
        REQUIRE(v3.y==0);
        REQUIRE(v3.z==0);
    }
    SECTION("cross")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        mystl::vec3 v3 = v.cross(v2);
        REQUIRE(v3.x==0);
        REQUIRE(v3.y==0);
        REQUIRE(v3.z==0);
    }
    SECTION("cwise_mul")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        mystl::vec3 v3 = v.cwise_mul(v2);
        REQUIRE(v3.x==1);
        REQUIRE(v3.y==4);
        REQUIRE(v3.z==9);
    }



}

TEST_CASE("operator += -= *= /=","[vec3]")
{
    SECTION("+= (with vec3)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        v += v2;
        REQUIRE(v.x==2);
        REQUIRE(v.y==4);
        REQUIRE(v.z==6);
    }

    SECTION("-= (with vec3)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        v += v2;
        REQUIRE(v.x==2);
        REQUIRE(v.y==4);
        REQUIRE(v.z==6);
    }

    SECTION("+= (with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        v += scalar;
        REQUIRE(v.x==3);
        REQUIRE(v.y==4);
        REQUIRE(v.z==5);
    }

    SECTION("-= (with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        v -= scalar;
        REQUIRE(v.x==-1);
        REQUIRE(v.y==0);
        REQUIRE(v.z==1);
    }

    SECTION("*= (with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        v *= scalar;
        REQUIRE(v.x==2);
        REQUIRE(v.y==4);
        REQUIRE(v.z==6);
    }

    SECTION("/= (with scalar)")
    {
        mystl::vec3 v(1,2,3);
        float scalar = 2;
        v /= scalar;
        REQUIRE(v.x==0.5);
        REQUIRE(v.y==1);
        REQUIRE(v.z==1.5);
    }
}

TEST_CASE("relation operator","[vec3]")
{
    SECTION("==")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,3);
        REQUIRE(v==v2);
    }
    SECTION("!=")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v!=v2);
    }
    SECTION("< (norm)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v<v2);
    }
    SECTION("<= (norm)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v<=v2);
    }
    SECTION("> (norm)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v2>v);
    }
    SECTION(">= (norm)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v2>=v);
    }
}

TEST_CASE("operator []","[vec3]")
{
    SECTION("operator [] (const)")
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v[0]==1);
        REQUIRE(v[1]==2);
        REQUIRE(v[2]==3);
    }

    SECTION("operator [] (non-const)")
    {
        mystl::vec3 v(1,2,3);
        v[0] = 2;
        v[1] = 3;
        v[2] = 4;
        REQUIRE(v[0]==2);
        REQUIRE(v[1]==3);
        REQUIRE(v[2]==4);
    }

    SECTION("at ")
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(v.at(0)==1);
        REQUIRE(v.at(1)==2);
        REQUIRE(v.at(2)==3);
    }

    SECTION("at (out of range)")
    {
        mystl::vec3 v(1,2,3);
        REQUIRE_THROWS_AS(v.at(3),std::out_of_range);
    }
}

TEST_CASE("unary operator","[vec3]")
{
    SECTION("unary -")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2 = -v;
        REQUIRE(v2.x==-1);
        REQUIRE(v2.y==-2);
        REQUIRE(v2.z==-3);
    }
}


TEST_CASE("other","vec3")
{
    SECTION("distance")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        REQUIRE(v.distance(v2)==1);
    }

    SECTION("distance (friend)")
    {
        mystl::vec3 v(1,2,3);
        mystl::vec3 v2(1,2,4);
        float d = mystl::distance(v,v2);
        REQUIRE(d==1);
    }

    SECTION("norm (non-member)")
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(mystl::norm(v)==Approx(std::sqrt(14)).epsilon(0.0001));
    }

    SECTION("length (non-member)")
    {
        mystl::vec3 v(1,2,3);
        REQUIRE(mystl::length(v)==Approx(std::sqrt(14)).epsilon(0.0001));
    }

    SECTION("normalize (non-member)")
    {
        mystl::vec3 v(1,2,3);
        float length = std::sqrt(14);
        float x_normalized = 1.0/length;
        float y_normalized = 2.0/length;
        float z_normalized = 3.0/length;
        mystl::vec3 v2;
        v2 = mystl::normalize(v);
        REQUIRE(v2.x == Approx(x_normalized).epsilon(0.0001));
        REQUIRE(v2.y == Approx(y_normalized).epsilon(0.0001));
        REQUIRE(v2.z == Approx(z_normalized).epsilon(0.0001));
    }

}