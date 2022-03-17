//
//  main.hpp
//  Main Header File
//
//  Created by Darius Miclaus (mdarius13)
//
//  Copyright (c) 2021 Miclaus Industries Corporation B.V. Advanced Software Technologies Research Group.
//
//  Permission is hereby granted, free of charge, 
//  to any person obtaining a copy of this software and associated documentation files (the "Software"), 
//  to deal in the Software without restriction, including without limitation the rights to use, copy, 
//  modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit 
//  persons to whom the Software is furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall 
//  be included in all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
//  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES 
//  OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
//  IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, 
//  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, 
//  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE 
//  OR OTHER DEALINGS IN THE SOFTWARE.
//

#include <cstdlib> 
#include <cstdio> 
#include <cmath> 
#include <fstream> 
#include <vector> 
#include <iostream> 
#include <cassert> 

#ifndef RAYTRACER_HPP
#define RAYTRACER_HPP
 
#if defined __APPLE__ || defined __linux__
// Compiled for macOS
#else 
// Windows doesn't define these values by default, macOS does
#define M_PI 3.141592653589793 
#define INFINITY 1e8 
#endif 

#define MAX_RAY_DEPTH 10

template<typename T> 
class Vec3 
{ 
public: 
    T x, y, z; 
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {} 
    Vec3(T xx) : x(xx), y(xx), z(xx) {} 
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {} 
    Vec3& normalize() 
    { 
        T nor2 = length2(); 
        if (nor2 > 0) { 
            T invNor = 1 / sqrt(nor2); 
            x *= invNor, y *= invNor, z *= invNor; 
        } 
        return *this; 
    } 
    Vec3<T> operator * (const T &f) const { return Vec3<T>(x * f, y * f, z * f); } 
    Vec3<T> operator * (const Vec3<T> &v) const { return Vec3<T>(x * v.x, y * v.y, z * v.z); } 
    T dot(const Vec3<T> &v) const { return x * v.x + y * v.y + z * v.z; } 
    Vec3<T> operator - (const Vec3<T> &v) const { return Vec3<T>(x - v.x, y - v.y, z - v.z); } 
    Vec3<T> operator + (const Vec3<T> &v) const { return Vec3<T>(x + v.x, y + v.y, z + v.z); } 
    Vec3<T>& operator += (const Vec3<T> &v) { x += v.x, y += v.y, z += v.z; return *this; } 
    Vec3<T>& operator *= (const Vec3<T> &v) { x *= v.x, y *= v.y, z *= v.z; return *this; } 
    Vec3<T> operator - () const { return Vec3<T>(-x, -y, -z); } 
    T length2() const { return x * x + y * y + z * z; } 
    T length() const { return sqrt(length2()); } 
    friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v) 
    { 
        os << "[" << v.x << " " << v.y << " " << v.z << "]"; 
        return os; 
    } 
}; 
 
typedef Vec3<float> Vec3f;

#endif /* RAYTRACER_HPP */
