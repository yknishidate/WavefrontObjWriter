#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>
#include <cfloat>

namespace wow{

class Vec2{
public:
    float x, y;

    Vec2(const float& n = 0): x(n), y(n){}
    Vec2(const float& x, const float& y): x(x), y(y){}

    bool operator==(const Vec2& vec){
        return (fabs(x - vec.x) <= FLT_EPSILON) && (fabs(y - vec.y) <= FLT_EPSILON);
    }
    bool operator!=(const Vec2& vec){
        return !(*this == vec);
    }

    // Vec + Vec
    Vec2 operator+(const Vec2& vec){
        return Vec2(x + vec.x, y + vec.y);
    }
    Vec2 operator-(const Vec2& vec){
        return Vec2(x - vec.x, y - vec.y);
    }
    Vec2 operator*(const Vec2& vec){
        return Vec2(x * vec.x, y * vec.y);
    }
    Vec2 operator/(const Vec2& vec){
        return Vec2(x / vec.x, y / vec.y);
    }
    Vec2 operator+=(const Vec2& vec){
        x += vec.x;
        y += vec.y;
        return *this;
    }
    Vec2 operator-=(const Vec2& vec){
        x -= vec.x;
        y -= vec.y;
        return *this;
    }
    Vec2 operator*=(const Vec2& vec){
        x *= vec.x;
        y *= vec.y;
        return *this;
    }
    Vec2 operator/=(const Vec2& vec){
        x /= vec.x;
        y /= vec.y;
        return *this;
    }

    // Vec + float
    Vec2 operator+(const float& value){
        return Vec2(x + value, y + value);
    }
    Vec2 operator-(const float& value){
        return Vec2(x - value, y - value);
    }
    Vec2 operator*(const float& value){
        return Vec2(x * value, y * value);
    }
    Vec2 operator/(const float& value){
        return Vec2(x / value, y / value);
    }
    Vec2 operator+=(const float& value){
        x += value;
        y += value;
        return *this;
    }
    Vec2 operator-=(const float& value){
        x -= value;
        y -= value;
        return *this;
    }
    Vec2 operator*=(const float& value){
        x *= value;
        y *= value;
        return *this;
    }
    Vec2 operator/=(const float& value){
        x /= value;
        y /= value;
        return *this;
    }

    // 2D cross product is not mathematically defined
    // However, this implementation assumes both vectors as 3D vectors with z=0
    // And returns the norm of the cross product between them
    // This is useful for some geometrical applications
    float cross(Vec2 b) {
      return x*b.y-y*b.x;
    }

    float dot(Vec2 b) {
      return x*b.x+y*b.y;
    }

    float norm() {
      return sqrt(x*x+y*y);
    }

    Vec2 normalize() {
      return (*this)/this->norm();
    }

    float dist(Vec2 to) {
      return (to-*this).norm();
    }

    float angleTo(Vec2 vec) {
      return acos(this->dot(vec)/(this->norm()*vec.norm()));
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec2& vec){
        os << vec.x << ", " << vec.y;
        return os;
    }
};


class Vec3{
public:
    float x, y, z;

    Vec3(const float& n = 0): x(n), y(n), z(n){};
    Vec3(const float& x, const float& y, const float& z): x(x), y(y), z(z){};

    bool operator==(const Vec3& vec){
    return (fabs(x - vec.x) <= FLT_EPSILON)
            && (fabs(y - vec.y) <= FLT_EPSILON)
            && (fabs(z - vec.z) <= FLT_EPSILON);
    }
    bool operator!=(const Vec3& vec){
        return !(*this == vec);
    }

    // Vec3 + Vec3
    Vec3 operator+(const Vec3& vec){
        return Vec3(x + vec.x, y + vec.y, z + vec.z);
    }

    Vec3 operator-(const Vec3& vec){
        return Vec3(x - vec.x, y - vec.y, z - vec.z);
    }

    Vec3 operator*(const Vec3& vec){
        return Vec3(x * vec.x, y * vec.y, z * vec.z);
    }

    Vec3 operator/(const Vec3& vec){
        return Vec3(x / vec.x, y / vec.y, z / vec.z);
    }

    Vec3 operator+=(const Vec3& vec){
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    Vec3 operator-=(const Vec3& vec){
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        return *this;
    }

    Vec3 operator*=(const Vec3& vec){
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;
        return *this;
    }

    Vec3 operator/=(const Vec3& vec){
        x /= vec.x;
        y /= vec.y;
        z /= vec.z;
        return *this;
    }

    // Vec + float
    Vec3 operator+(const float& value){
        return Vec3(x + value, y + value, z + value);
    }

    Vec3 operator-(const float& value){
        return Vec3(x - value, y - value, z - value);
    }

    Vec3 operator*(const float& value){
        return Vec3(x * value, y * value, z * value);
    }

    Vec3 operator/(const float& value){
        return Vec3(x / value, y / value, z / value);
    }

    Vec3 operator+=(const float& value){
        x += value;
        y += value;
        z += value;
        return *this;
    }

    Vec3 operator-=(const float& value){
        x -= value;
        y -= value;
        z -= value;
        return *this;
    }

    Vec3 operator*=(const float& value){
        x *= value;
        y *= value;
        z *= value;
        return *this;
    }

    Vec3 operator/=(const float& value){
        x /= value;
        y /= value;
        z /= value;
        return *this;
    }

    Vec3 cross(Vec3 b) {
      return Vec3(y*b.z-z*b.y,
                  z*b.x-x*b.z,
                  x*b.y-y*b.x);
    }

    float dot(Vec3 b) {
      return x*b.x+y*b.y+z*b.z;
    }

    float norm() {
      return sqrt(x*x+y*y+z*z);
    }

    Vec3 normalize() {
      return (*this)/this->norm();
    }

    float dist(Vec3 to) {
      return (to-*this).norm();
    }

    float angleTo(Vec3 vec, Vec3 perp) {
      float angle = acos(this->dot(vec)/(this->norm()*vec.norm()));
      if (vec.dot(perp) < 0)
        angle = 2*M_PI - angle;
      return angle;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& vec){
        os << vec.x << ", " << vec.y << ", " << vec.z;
        return os;
    }
};


class Vec4{
public:
    float x, y, z, w;

    Vec4(const float& n = 0): x(n), y(n), z(n), w(n){};
    Vec4(const float& x, const float& y, const float& z, const float& w): x(x), y(y), z(z), w(w){};


    bool operator==(const Vec4& vec){
        return (fabs(x - vec.x) <= FLT_EPSILON)
                && (fabs(y - vec.y) <= FLT_EPSILON)
                && (fabs(z - vec.z) <= FLT_EPSILON)
                && (fabs(w - vec.w) <= FLT_EPSILON);
    }
    bool operator!=(const Vec4& vec){
        return !(*this == vec);
    }

    // Vec4 + Vec4
    Vec4 operator+(const Vec4& vec){
        return Vec4(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
    }

    Vec4 operator-(const Vec4& vec){
        return Vec4(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
    }

    Vec4 operator*(const Vec4& vec){
        return Vec4(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
    }

    Vec4 operator/(const Vec4& vec){
        return Vec4(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
    }

    // Vec4 += Vec4
    Vec4 operator+=(const Vec4& vec){
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;
        return *this;
    }

    Vec4 operator-=(const Vec4& vec){
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        w -= vec.w;
        return *this;
    }

    Vec4 operator*=(const Vec4& vec){
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;
        w *= vec.w;
        return *this;
    }

    Vec4 operator/=(const Vec4& vec){
        x /= vec.x;
        y /= vec.y;
        z /= vec.z;
        w /= vec.w;
        return *this;
    }

    // Vec4 + float
    Vec4 operator+(const float& value){
        return Vec4(x + value, y + value, z + value, w + value);
    }

    Vec4 operator-(const float& value){
        return Vec4(x - value, y - value, z - value, w - value);
    }

    Vec4 operator*(const float& value){
        return Vec4(x * value, y * value, z * value, w * value);
    }

    Vec4 operator/(const float& value){
        return Vec4(x / value, y / value, z / value, w / value);
    }

    // Vec4 += float
    Vec4 operator+=(const float& value){
        x += value;
        y += value;
        z += value;
        w += value;
        return *this;
    }

    Vec4 operator-=(const float& value){
        x -= value;
        y -= value;
        z -= value;
        w -= value;
        return *this;
    }

    Vec4 operator*=(const float& value){
        x *= value;
        y *= value;
        z *= value;
        w *= value;
        return *this;
    }

    Vec4 operator/=(const float& value){
        x /= value;
        y /= value;
        z /= value;
        w /= value;
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const Vec4& vec){
        os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
        return os;
    }

};


class Vec4i{
public:
    std::int32_t x, y, z, w;

    Vec4i(const std::int32_t& n = 0): x(n), y(n), z(n), w(n){};
    Vec4i(const std::int32_t& x, const std::int32_t& y, const std::int32_t& z, const std::int32_t& w): x(x), y(y), z(z), w(w){};


    bool operator==(const Vec4i& vec){
        return x == vec.x && y == vec.y && z == vec.z && w == vec.w;
    }
    bool operator!=(const Vec4i& vec){
        return !(*this == vec);
    }

    // Vec4i + Vec4i
    Vec4i operator+(const Vec4i& vec){
        return Vec4i(x + vec.x, y + vec.y, z + vec.z, w + vec.w);
    }

    Vec4i operator-(const Vec4i& vec){
        return Vec4i(x - vec.x, y - vec.y, z - vec.z, w - vec.w);
    }

    Vec4i operator*(const Vec4i& vec){
        return Vec4i(x * vec.x, y * vec.y, z * vec.z, w * vec.w);
    }

    Vec4i operator/(const Vec4i& vec){
        return Vec4i(x / vec.x, y / vec.y, z / vec.z, w / vec.w);
    }

    // Vec4i += Vec4i
    Vec4i operator+=(const Vec4i& vec){
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;
        return *this;
    }

    Vec4i operator-=(const Vec4i& vec){
        x -= vec.x;
        y -= vec.y;
        z -= vec.z;
        w -= vec.w;
        return *this;
    }

    Vec4i operator*=(const Vec4i& vec){
        x *= vec.x;
        y *= vec.y;
        z *= vec.z;
        w *= vec.w;
        return *this;
    }

    Vec4i operator/=(const Vec4i& vec){
        x /= vec.x;
        y /= vec.y;
        z /= vec.z;
        w /= vec.w;
        return *this;
    }

    // Vec4i + std::int32_t
    Vec4i operator+(const std::int32_t& value){
        return Vec4i(x + value, y + value, z + value, w + value);
    }

    Vec4i operator-(const std::int32_t& value){
        return Vec4i(x - value, y - value, z - value, w - value);
    }

    Vec4i operator*(const std::int32_t& value){
        return Vec4i(x * value, y * value, z * value, w * value);
    }

    Vec4i operator/(const std::int32_t& value){
        return Vec4i(x / value, y / value, z / value, w / value);
    }

    // Vec4i += std::int32_t
    Vec4i operator+=(const std::int32_t& value){
        x += value;
        y += value;
        z += value;
        w += value;
        return *this;
    }

    Vec4i operator-=(const std::int32_t& value){
        x -= value;
        y -= value;
        z -= value;
        w -= value;
        return *this;
    }

    Vec4i operator*=(const std::int32_t& value){
        x *= value;
        y *= value;
        z *= value;
        w *= value;
        return *this;
    }

    Vec4i operator/=(const std::int32_t& value){
        x /= value;
        y /= value;
        z /= value;
        w /= value;
        return *this;
    }


    friend std::ostream& operator<<(std::ostream& os, const Vec4i& vec){
        os << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w;
        return os;
    }
};
}
