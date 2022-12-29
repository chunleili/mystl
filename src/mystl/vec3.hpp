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
    float x, y, z; // 分量

    vec3() = default;                                           // 默认构造函数
    vec3(const vec3 &rhs) = default;                            // 默认拷贝构造函数
    vec3 &operator=(const vec3 &rhs) = default;                 // 默认拷贝赋值运算符
    vec3(float val) : x(val), y(val), z(val){};                 // 用一个值初始化所有分量
    vec3(float x_, float y_, float z_) : x(x_), y(y_), z(z_){}; // 用三个值初始化所有分量

    /* -------------------------------------------------------------------------- */
    /*                                    输入输出                                 */
    /* -------------------------------------------------------------------------- */
    friend std::ostream &operator<<(std::ostream &os, const vec3 &v)
    {
        os << v.x << " " << v.y << " " << v.z<< " ";
        return os;
    };

    void show() const
    {
        std::cout << x << " " << y << " " << z << "\n";
    };


    /* -------------------------------------------------------------------------- */
    /*                                  与模长有关的运算                            */
    /* -------------------------------------------------------------------------- */
    float norm() const // 模长
    {
        return std::sqrt(x * x + y * y + z * z);
    };
    float magnitude() const // 模长
    {
        return this->norm();
    }
    float length() const // 模长
    {
        return this->norm();
    }
    float normSqr() const // 模长的平方
    {
        return (x * x + y * y + z * z);
    }
    float lengthSqr() const // 模长的平方
    { 
        return this->normSqr(); 
    }
    const vec3 &normalize() // 单位化
    {
        float n = this->norm();
        x /= n;
        y /= n;
        z /= n;
        return *this;
    };


    /* -------------------------------------------------------------------------- */
    /*                              与vec3加减乘除运算符                           */
    /* -------------------------------------------------------------------------- */
    vec3 operator+(const vec3 &rhs) const    // 加法
    {
        return vec3(this->x + rhs.x, this->y + rhs.y, this->z + rhs.z);
    }
    vec3 operator-(const vec3 &rhs) const // 减法
    {
        return vec3(this->x - rhs.x, this->y - rhs.y, this->z - rhs.z);
    }
    vec3 operator+(const float rhs) const // 数加
    {
        return vec3(this->x + rhs, this->y + rhs, this->z + rhs);
    }
    vec3 operator-(const float rhs) const // 数减
    {
        return vec3(this->x - rhs, this->y - rhs, this->z - rhs);
    }
    vec3 operator*(const float rhs) const // 数乘
    {
        return vec3(this->x * rhs, this->y * rhs, this->z * rhs);
    }
    vec3 operator/(const float rhs) const // 数除
    {
        return vec3(this->x / rhs, this->y / rhs, this->z / rhs);
    }
    

    
    float operator*(const vec3 &rhs) const // 点乘
    {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }
    float dot(const vec3 &rhs) const // 点乘
    {
        return this->x * rhs.x + this->y * rhs.y + this->z * rhs.z;
    }
    vec3 operator^(const vec3 &rhs) const // 叉乘
    {
        return vec3(this->y * rhs.z - this->z * rhs.y, this->z * rhs.x - this->x * rhs.z, this->x * rhs.y - this->y * rhs.x);
    }
    vec3 cross(const vec3 &rhs) const // 叉乘
    {
        return vec3(this->y * rhs.z - this->z * rhs.y, this->z * rhs.x - this->x * rhs.z, this->x * rhs.y - this->y * rhs.x);
    }
    vec3 cwise_mul(const vec3 &rhs) const // 逐个分量相乘
    {
        return vec3(this->x * rhs.x, this->y * rhs.y, this->z * rhs.z);
    }

    /* -------------------------------------------------------------------------- */
    /*                                  带等号的运算符重载                          */
    /* -------------------------------------------------------------------------- */
    const vec3 &operator+=(const vec3 &rhs) // 加等
    {
        this->x += rhs.x;
        this->y += rhs.y;
        this->z += rhs.z;
        return *this;
    }
    const vec3 &operator-=(const vec3 &rhs) // 减等
    {
        this->x -= rhs.x;
        this->y -= rhs.y;
        this->z -= rhs.z;
        return *this;
    }
    const vec3 &operator+=(const float rhs) // 数加等
    {
        this->x += rhs;
        this->y += rhs;
        this->z += rhs;
        return *this;
    }
    const vec3 &operator-=(const float rhs) // 数减等
    {
        this->x -= rhs;
        this->y -= rhs;
        this->z -= rhs;
        return *this;
    }
    const vec3 &operator*=(const float rhs) // 数乘等
    {
        this->x *= rhs;
        this->y *= rhs;
        this->z *= rhs;
        return *this;
    }
    const vec3 &operator/=(const float rhs) // 数除等
    {
        this->x /= rhs;
        this->y /= rhs;
        this->z /= rhs;
        return *this;
    }


    /* -------------------------------------------------------------------------- */
    /*                                   关系运算符                                */
    /* -------------------------------------------------------------------------- */
    bool operator==(const vec3 &rhs) const  // 判断相等(所有分量相等返回true)
    {
        return this->x == rhs.x && this->y == rhs.y && this->z == rhs.z;
    }
    bool operator!=(const vec3 &rhs) const  // 判断不等(任何分量不等于都返回true)
    {
        return this->x != rhs.x || this->y != rhs.y || this->z != rhs.z;
    }
    bool operator>(const vec3 &rhs) const   // 判断大于(norm)
    {
        return this->norm() > rhs.norm();
    }
    bool operator<(const vec3 &rhs) const   // 判断小于(norm)
    {
        return this->norm() < rhs.norm();
    }
    bool operator>=(const vec3 &rhs) const  // 判断大于等于(norm)
    {
        return this->norm() >= rhs.norm();
    }
    bool operator<=(const vec3 &rhs) const  // 判断小于等于(norm)
    {
        return this->norm() <= rhs.norm();
    }

    /* -------------------------------------------------------------------------- */
    /*                                    下标运算符                               */
    /* -------------------------------------------------------------------------- */
    float &operator[](int i)             // 下标访问
    {
        return (&x)[i];
    }
    const float &operator[](int i) const // 下标访问
    {
        return (&x)[i];
    }
    float & at(int i)     
    {
        if (i < 0 || i > 2)
            throw std::out_of_range("vec3 index out of range");
        return (&x)[i];
    }        
    const float &at(int i) const   
    {
        if (i < 0 || i > 2)
            throw std::out_of_range("vec3 index out of range");
        return (&x)[i];
    }          

    /* -------------------------------------------------------------------------- */
    /*                                    单目运算符                               */
    /* -------------------------------------------------------------------------- */
    vec3 operator-() const // 取负
    {
        return vec3(-this->x, -this->y, -this->z);
    }

    /* -------------------------------------------------------------------------- */
    /*                                     其他                                   */
    /* -------------------------------------------------------------------------- */
    float distance(const vec3 &rhs) const // 两点间距离
    {
        return sqrt((this->x - rhs.x) * (this->x - rhs.x) + (this->y - rhs.y) * (this->y - rhs.y) + (this->z - rhs.z) * (this->z - rhs.z));
    }
};

/* -------------------------------------------------------------------------- */
/*                                    全局函数                                 */
/* -------------------------------------------------------------------------- */
float distance(const vec3 &lhs, const vec3 &rhs) // 两点间距离
{
    return sqrt((lhs.x - rhs.x) * (lhs.x - rhs.x) + (lhs.y - rhs.y) * (lhs.y - rhs.y) + (lhs.z - rhs.z) * (lhs.z - rhs.z));
}

float norm(const vec3 &v) // 模长
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
};
float length(const vec3 &v) // 模长
{
    return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
};
vec3 normalize(const vec3 &v) // 单位化
{
    float n = std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
    return vec3(v.x / n, v.y / n, v.z / n);
};


vec3 operator+(const float lhs, const vec3 &rhs)// 数加(标量在左)
{
    return vec3(lhs + rhs.x, lhs + rhs.y, lhs + rhs.z);
}

vec3 operator-(const float lhs, const vec3 &rhs)// 数减(标量在左)
{
    return vec3(lhs - rhs.x, lhs - rhs.y, lhs - rhs.z);
}

vec3 operator*(const float lhs, const vec3 &rhs)// 数乘(标量在左)
{
    return vec3(lhs * rhs.x, lhs * rhs.y, lhs * rhs.z);
}

vec3 operator/(const float lhs, const vec3 &rhs)// 数除(标量在左)
{
    return vec3(lhs / rhs.x, lhs / rhs.y, lhs / rhs.z);
}

} // namespace mystl
