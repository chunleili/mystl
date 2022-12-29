#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include <iostream>
#include <cmath>
#include <Eigen/Dense>

#include "mystl/quat.hpp"

using namespace Eigen;
using namespace mystl;


TEST_CASE("constructor","[quat]")
{
    SECTION("default constructor")
    {
        quat q1;
        REQUIRE(q1.x==0);
        REQUIRE(q1.y==0);
        REQUIRE(q1.z==0);
        REQUIRE(q1.w==0);
    }
    SECTION("constructor with 4 float")
    {
        quat q1{1,2,3,4};
        REQUIRE(q1.x==1);
        REQUIRE(q1.y==2);
        REQUIRE(q1.z==3);
        REQUIRE(q1.w==4);
    }
    SECTION("constructor with 1 float")
    {
        quat q1{1};
        REQUIRE(q1.x==1);
        REQUIRE(q1.y==1);
        REQUIRE(q1.z==1);
        REQUIRE(q1.w==1);
    }
}

TEST_CASE("output","[quat]")
{
    SECTION("output with <<")
    {
        quat q1{1,2,3,4};
        std::cout<<q1<<std::endl;
    }
    SECTION("output with show()")
    {
        quat q1{1,2,3,4};
        q1.show();
    }
}

TEST_CASE("operator+-","[quat]")
{
    SECTION("operator+")
    {
        quat q1{1,2,3,4}, q2{5,6,7,8}, res;
        res = q1 + q2;
        REQUIRE(res.x==6);
        REQUIRE(res.y==8);
        REQUIRE(res.z==10);
        REQUIRE(res.w==12);
    }
    SECTION("operator-")
    {
        quat q1{1,2,3,4}, q2{5,6,7,8}, res;
        res = q1 - q2;
        REQUIRE(res.x==-4);
        REQUIRE(res.y==-4);
        REQUIRE(res.z==-4);
        REQUIRE(res.w==-4);
    }

    SECTION("operator+=")
    {
        quat q1{1,2,3,4}, q2{5,6,7,8};
        q1 += q2;
        REQUIRE(q1.x==6);
        REQUIRE(q1.y==8);
        REQUIRE(q1.z==10);
        REQUIRE(q1.w==12);
    }
    SECTION("operator-=")
    {
        quat q1{1,2,3,4}, q2{5,6,7,8};
        q1 -= q2;
        REQUIRE(q1.x==-4);
        REQUIRE(q1.y==-4);
        REQUIRE(q1.z==-4);
        REQUIRE(q1.w==-4);
    }
}

TEST_CASE("operator*","[quat]")
{
    SECTION("operator*")
    {
        //请注意我们是以xyzw的顺序存储的，而Eigen是以wxyz的顺序存储的
        Quaternionf q1_{4,1,2,3}, q2_{8,5,6,7}, res_eigen;
        res_eigen = q1_ * q2_;
        std::cout<<"Eigen:\n"<<res_eigen<<std::endl;

        quat q1{1,2,3,4}, q2{5,6,7,8}, res;
        res = q1 * q2;
        std::cout<<"my:"<<std::endl;
        res.show();
        REQUIRE(res.x==res_eigen.x());
        REQUIRE(res.y==res_eigen.y());
        REQUIRE(res.z==res_eigen.z());
        REQUIRE(res.w==res_eigen.w());
        //Answer is:  24i + 48j + 48k + -6
    }
}

TEST_CASE("operator*=","[quat]")
{
    SECTION("operator*=")
    {
        quat q1{1,2,3,4}, q2{5,6,7,8}, res;
        res = q1;
        res *= q2;
        REQUIRE(res.x==24);
        REQUIRE(res.y==48);
        REQUIRE(res.z==48);
        REQUIRE(res.w==-6);
    }
}

TEST_CASE("operator with scalar","[quat]")
{
    SECTION("operator+ with scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1 + 5.0;
        REQUIRE(res.x==6);
        REQUIRE(res.y==7);
        REQUIRE(res.z==8);
        REQUIRE(res.w==9);
    }
    SECTION("operator- with scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1 - 5.0;
        REQUIRE(res.x==-4);
        REQUIRE(res.y==-3);
        REQUIRE(res.z==-2);
        REQUIRE(res.w==-1);
    }
    SECTION("operator* with scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1 * 5.0;
        REQUIRE(res.x==5);
        REQUIRE(res.y==10);
        REQUIRE(res.z==15);
        REQUIRE(res.w==20);
    }
    SECTION("operator/ with scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1 / 5.0;
        REQUIRE(res.x==Approx(0.2));
        REQUIRE(res.y==Approx(0.4));
        REQUIRE(res.z==Approx(0.6));
        REQUIRE(res.w==Approx(0.8));
    }

    SECTION("operator+ with scalar on the left")
    {
        quat q1{1,2,3,4}, res;
        res = 5.0 + q1;
        REQUIRE(res.x==6);
        REQUIRE(res.y==7);
        REQUIRE(res.z==8);
        REQUIRE(res.w==9);
    }
    SECTION("operator- with scalar on the left")
    {
        quat q1{1,2,3,4}, res;
        res = 5.0 - q1;
        REQUIRE(res.x==4);
        REQUIRE(res.y==3);
        REQUIRE(res.z==2);
        REQUIRE(res.w==1);
    }
    SECTION("operator* with scalar on the left")
    {
        quat q1{1,2,3,4}, res;
        res = 5.0 * q1;
        REQUIRE(res.x==5);
        REQUIRE(res.y==10);
        REQUIRE(res.z==15);
        REQUIRE(res.w==20);
    }
    SECTION("operator/ with scalar on the left")
    {
        quat q1{1,2,3,4}, res;
        res = 5.0 / q1;
        REQUIRE(res.x==Approx(5.0));
        REQUIRE(res.y==Approx(2.5));
        REQUIRE(res.z==Approx(1.6666666666666666666666666666667));
        REQUIRE(res.w==Approx(1.25));
    }
}


TEST_CASE("operator+= -= *= /= scalar","[quat]")
{
    SECTION("operator+= scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1;
        res += 5.0;
        REQUIRE(res.x==6);
        REQUIRE(res.y==7);
        REQUIRE(res.z==8);
        REQUIRE(res.w==9);
    }

    SECTION("operator-= scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1;
        res -= 5.0;
        REQUIRE(res.x==-4);
        REQUIRE(res.y==-3);
        REQUIRE(res.z==-2);
        REQUIRE(res.w==-1);
    }

    SECTION("operator*= scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1;
        res *= 5.0;
        REQUIRE(res.x==5);
        REQUIRE(res.y==10);
        REQUIRE(res.z==15);
        REQUIRE(res.w==20);
    }

    SECTION("operator/= scalar")
    {
        quat q1{1,2,3,4}, res;
        res = q1;
        res /= 5.0;
        REQUIRE(res.x==Approx(0.2));
        REQUIRE(res.y==Approx(0.4));
        REQUIRE(res.z==Approx(0.6));
        REQUIRE(res.w==Approx(0.8));
    }
}



TEST_CASE("unary operation","[quat]")
{
    SECTION("negation")
    {
        quat q1{1,2,3,4}, res;
        res = -q1;
        REQUIRE(res.x==-1);
        REQUIRE(res.y==-2);
        REQUIRE(res.z==-3);
        REQUIRE(res.w==-4);
    }
    SECTION("norm")
    {
        Quaternionf q_{4, 1,2,3};
        float res_ = q_.norm();
        std::cout<<"norm in eigen: "<<res_<<std::endl;

        quat q1{1,2,3,4};
        float res = q1.norm();
        REQUIRE(res==Approx(5.477225575051661));
        REQUIRE(res==Approx(res_));
    }


    SECTION("conjugate")
    {
        quat q1{1,2,3,4}, res;
        res = q1.conjugate();
        REQUIRE(res.x==-1);
        REQUIRE(res.y==-2);
        REQUIRE(res.z==-3);
        REQUIRE(res.w==4);
    }

    SECTION("normalize")
    {
        quat res{1,2,3,4};
        res.normalize();
        REQUIRE(res.x==Approx(0.182574185835055));
        REQUIRE(res.y==Approx(0.36514837167011));
        REQUIRE(res.z==Approx(0.547722557505165));
        REQUIRE(res.w==Approx(0.730296743340221));
        REQUIRE(res.norm()==Approx(1.0));
    }

    SECTION("normalized")
    {
        //与normalize的区别在于，normalized不会改变原来的值
        quat q1{1,2,3,4}, res;
        res = q1.normalized();
        REQUIRE(res.x==Approx(0.182574185835055));
        REQUIRE(res.y==Approx(0.36514837167011));
        REQUIRE(res.z==Approx(0.547722557505165));
        REQUIRE(res.w==Approx(0.730296743340221));
        REQUIRE(res.norm()==Approx(1.0));

        REQUIRE(q1.x==1);
        REQUIRE(q1.y==2);
        REQUIRE(q1.z==3);
        REQUIRE(q1.w==4);
    }


    SECTION("inverse")
    {
        Quaternionf q_{4, 1,2,3};
        Quaternionf res_ = q_.inverse();
        std::cout<<"inverse in eigen:\n"<<res_<<std::endl;

        quat q1{1,2,3,4};
        quat res = q1.inverse();
        std::cout<<"inverse of mine:\n";
        res.show();

        //一个四元数乘以它的逆等于1(w=1,x=y=z=0)
        std::cout<<"q1*q1.inverse():\n"<<q1 * q1.inverse()<<std::endl;

        REQUIRE(res_.x() == Approx(res.x));
        REQUIRE(res_.y() == Approx(res.y));
        REQUIRE(res_.z() == Approx(res.z));
        REQUIRE(res_.w() == Approx(res.w));
    }
}


TEST_CASE("relation operator","[quat]")
{
    SECTION("operator==")
    {
        quat q1{1,2,3,4}, q2{1,2,3,4};
        REQUIRE(q1==q2);
    }

    SECTION("operator!=")
    {
        quat q1{1,2,3,4}, q2{1,2,3,5};
        REQUIRE(q1!=q2);
    }
}

// int main()
// {
//     Quaternionf q1{1,2,3,4}, q2{5,6,7,8}, res;

//     // std::cout<<q1 <<std::endl;
//     // std::cout<<q2 <<std::endl;


//     // res = qadd(q1, q2); //加法
//     // std::cout<< res <<std::endl;


//     // res =  qscale(q1, 5.0); //数乘
//     // std::cout<< res <<std::endl;


//     // std::cout<< q1*q2<<std::endl;  //Eigen自带乘法
//     // res = qmul(q1,q2);   //乘法1
//     // std::cout<< res <<std::endl;
//     // res = qmul2(q1,q2);  //乘法2
//     // std::cout<< res <<std::endl;


//     // q1 = q1.normalized();
//     // q2 = q2.normalized();


//     // std::cout<< q1.inverse()<<std::endl;
//     // res = qinv(q1);  //求逆
//     // std::cout<< res <<std::endl;

//     //用四元数旋转
//     Vector3f point{1.0, 1.0, 0};
//     point = point.normalized();
//     Quaternionf p;
//     p.vec() = point;
//     p.w() = 0;

//     float theta = 45.0 / 180 * 3.14159265358979323846;
//     Vector3f axis{0,0,1};

//     Quaternionf q{cos(theta/2), sin(theta/2) * axis[0], sin(theta/2) * axis[1], sin(theta/2) * axis[2]};
//     std::cout<<q<<std::endl;

//     Quaternionf p_new = q * p * q.inverse();
//     std::cout<<p_new<<std::endl;

//     Vector3f point_new=p_new.vec();
//     std::cout<<point_new<<std::endl;
// }
