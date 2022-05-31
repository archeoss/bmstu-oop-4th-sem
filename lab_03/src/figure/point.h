//
// Created by thebi on 16.05.2022.
//

#ifndef BMSTU_OOP_4TH_SEM_POINT_H
#define BMSTU_OOP_4TH_SEM_POINT_H

#include <memory>
#include <cmath>
#include <iostream>

class Point
{
public:
	Point();
	Point(float x, float y, float z);
	Point(const Point &point);
	Point& operator=(const Point &point);
	Point(const Point &&point) noexcept;
    Point& operator=(Point &&point) noexcept;

    float getX() const;
    float getY() const;
    float getZ() const;

    void setX(float x);
    void setY(float z);
    void setZ(float y);

    void move(float dx = 0, float dy = 0 , float dz = 0);
    void scale(float kx = 1, float ky = 1 , float kz = 1);
    void rotate(float ox = 0, float oy = 0 , float oz = 0);

    Point operator+(const Point &point);
    Point operator-(const Point &point);
    Point& operator+=(const Point &point);
    Point& operator-=(const Point &point);

    Point operator*(const Point &point);
    Point operator/(const Point &point);
    Point& operator*=(const Point &point);
    Point& operator/=(const Point &point);


	~Point() = default;
private:
    void rotate_xpoint(float ox);
    void rotate_ypoint(float oy);
    void rotate_zpoint(float oz);
    float x, y, z;
};


#endif //BMSTU_OOP_4TH_SEM_POINT_H
