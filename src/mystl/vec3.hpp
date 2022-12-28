#pragma once

#include <initializer_list>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <cmath>

/**
 * @brief 进行数学运算的vec3类。支持加、减、点乘、叉乘、norm等运算。
 * 
 */
namespace mystl
{

class vec3
{
public:
    float x, y, z;  // 分量

    vec3() = default; // 默认构造函数
    vec3(const vec3 &rhs) = default;  // 默认拷贝构造函数
    vec3 &operator=(const vec3 &rhs) = default;   // 默认拷贝赋值运算符
    vec3(float val): x(val), y(val), z(val){};  // 用一个值初始化所有分量
    vec3(float x_, float y_, float z_): x(x_), y(y_), z(z_){};    // 用三个值初始化所有分量

    bool operator==(const vec3 &rhs) const;  // 判断相等
    bool operator!=(const vec3 &rhs) const;  // 判断不等
    const vec3 & operator+=(const vec3 &rhs); //加等
    const vec3 & operator-=(const vec3 &rhs); //减等
    vec3 operator+(const vec3 &rhs) const; //加法
    vec3 operator-(const vec3 &rhs) const; //减法
    vec3 operator*(const float rhs) const; //数乘
    vec3 operator/(const float rhs) const; //数除
    const vec3 & operator*=(const float rhs); //数乘等
    const vec3 & operator/=(const float rhs); //数除等
    float operator*(const vec3 &rhs) const; //点乘
    vec3 operator^(const vec3 &rhs) const; //叉乘
    float dot(const vec3 &rhs) const; //点乘
    vec3 cross(const vec3 &rhs) const; //叉乘
    float &operator[](int i); //下标访问
    const float &operator[](int i) const; //下标访问

    //模长
    float norm() const
    {
        return std::sqrt(x * x + y * y + z * z);
    }; 
    float magnitude() const{return this->norm();}; //模长
    float length() const{return this->norm();}; //模长
    float normSqr() const   //模长的平方
    {
        return (x * x + y * y + z * z);
    }; 
    float lengthSqr() const{return this->normSqr();}; //模长的平方
    const vec3 & normalize()//单位化
    {
        float n = this->norm();
        x /= n;
        y /= n;
        z /= n;
        return *this;
    }; 

    //输出
    friend std::ostream &operator<<(std::ostream &os, const vec3 &v)
    {
        os << v.x << " " << v.y << " " << v.z;
        return os;
    }; 
};

} // namespace mystl
