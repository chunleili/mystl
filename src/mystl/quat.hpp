#pragma once

#include <iostream>
#include <cmath>

namespace mystl
{

class quat
{
public:
    float x, y, z, w;
    quat(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    quat(float val) : x(val), y(val), z(val), w(val) {}
    quat() : x(0), y(0), z(0), w(0) {}

    friend std::ostream &operator<<(std::ostream &os, const quat &q)
    {
        os << q.x << "i + " << q.y << "j + " << q.z<< "k + " << q.w << " ";
        return os;
    };
    void show() const
    {
        std::cout << x << "i + " << y << "j + " << z<< "k + " << w << "\n";
    };


    /* -------------------------------------------------------------------------- */
    /*                       quat之间加减法和+= -=                                 */
    /* -------------------------------------------------------------------------- */
    quat operator+(const quat &q) const
    {
        return quat(x + q.x, y + q.y, z + q.z, w + q.w);
    }
    quat operator-(const quat &q) const
    {
        return quat(x - q.x, y - q.y, z - q.z, w - q.w);
    }

    quat &operator+=(const quat &q)
    {
        x += q.x;
        y += q.y;
        z += q.z;
        w += q.w;
        return *this;
    }
    quat &operator-=(const quat &q)
    {
        x -= q.x;
        y -= q.y;
        z -= q.z;
        w -= q.w;
        return *this;
    }

    /* -------------------------------------------------------------------------- */
    /*                                quat之间乘法和乘等                          */
    /* -------------------------------------------------------------------------- */
    quat operator*(const quat &q) const
    {
        return quat(w * q.x + x * q.w + y * q.z - z * q.y,
                    w * q.y - x * q.z + y * q.w + z * q.x,
                    w * q.z + x * q.y - y * q.x + z * q.w,
                    w * q.w - x * q.x - y * q.y - z * q.z);
    }
    quat &operator*=(const quat &q)
    {
        float nx = w * q.x + x * q.w + y * q.z - z * q.y;
        float ny = w * q.y - x * q.z + y * q.w + z * q.x;
        float nz = w * q.z + x * q.y - y * q.x + z * q.w;
        float nw = w * q.w - x * q.x - y * q.y - z * q.z;
        x = nx;
        y = ny;
        z = nz;
        w = nw;
        return *this;
    }

    
    /* -------------------------------------------------------------------------- */
    /*                           与标量的加减乘除                                   */
    /* -------------------------------------------------------------------------- */
    quat operator+(const float &s) const
    {
        return quat(x + s, y + s, z + s, w + s);
    }
    friend quat operator+(const float &s, const quat & q) //数字在左边
    {
        return quat(q.x + s, q.y + s, q.z + s, q.w + s);
    }
    quat operator-(const float &s) const
    {
        return quat(x - s, y - s, z - s, w - s);
    }
    friend quat operator-(const float &s, const quat & q) //数字在左边
    {
        return quat(s - q.x, s - q.y, s - q.z, s - q.w);
    }
    quat operator*(const float &s) const
    {
        return quat(x * s, y * s, z * s, w * s);
    }
    friend quat operator*(const float &s, const quat & q) //数字在左边
    {
        return quat(q.x * s, q.y * s, q.z * s, q.w * s);
    }
    quat operator/(const float &s) const
    {
        return quat(x / s, y / s, z / s, w / s);
    }
    friend quat operator/(const float &s, const quat & q) //数字在左边
    {
        return quat(s/q.x, s/q.y, s/q.z, s/q.w);
    }



    /* -------------------------------------------------------------------------- */
    /*                             与标量的+= -= *= /=                             */
    /* -------------------------------------------------------------------------- */
    quat &operator+=(const float &s)
    {
        x += s;
        y += s;
        z += s;
        w += s;
        return *this;
    }
    quat &operator-=(const float &s)
    {
        x -= s;
        y -= s;
        z -= s;
        w -= s;
        return *this;
    }
    quat &operator*=(const float &s)
    {
        x *= s;
        y *= s;
        z *= s;
        w *= s;
        return *this;
    }
    quat &operator/=(const float &s)
    {
        x /= s;
        y /= s;
        z /= s;
        w /= s;
        return *this;
    }


    /* -------------------------------------------------------------------------- */
    /*                                单目运算符                                   */
    /* -------------------------------------------------------------------------- */
    //取负
    quat operator-() const
    {
        return quat(-x, -y, -z, -w);
    }
    float norm() const
    {
        return sqrt(x * x + y * y + z * z + w * w);
    }
    float normSqr() const
    {
        return (x * x + y * y + z * z + w * w);
    }
    quat &normalize() //会对自身进行修改
    {
        float len = sqrt(x * x + y * y + z * z + w * w);
        x /= len;
        y /= len;
        z /= len;
        w /= len;
        return *this;
    }
    quat normalized() const //不会对自身进行修改
    {
        float len = sqrt(x * x + y * y + z * z + w * w);
        return quat(x / len, y / len, z / len, w / len);
    }

    quat conjugate() const
    {
        return quat(-x, -y, -z, w);
    }

    quat inverse() const
    {
        float normSqr = this->normSqr();
        return quat(-x, -y, -z, w) / normSqr;
    }

    quat& setIdentity()
    {
        x = 0;
        y = 0;
        z = 0;
        w = 1;
        return *this;
    }


    bool operator==(const quat &q) const
    {
        return (x == q.x && y == q.y && z == q.z && w == q.w);
    }

    bool operator!=(const quat &q) const
    {
        return (x != q.x || y != q.y || z != q.z || w != q.w);
    }

    // TODO: 旋转向量 
    //TODO: 变换为点
    
    // vec3 rotate(const vec3 &v) const
    // {
    //     quat qv(v.x, v.y, v.z, 0);
    //     quat res = (*this) * qv * (*this).inverse();
    //     return vec3(res.x, res.y, res.z);
    // }
};


} // namespace mystl



