//
// Created by thebi on 16.05.2022.
//

#include "point.h"

Point::Point()
{
    x = 0;
    y = 0;
    z = 0;
}

Point::Point(const float x, const float y, const float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

Point::Point(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;
}

Point::Point(const Point &&point) noexcept : Point(point)
{
    point.~Point();
}


Point &Point::operator=(const Point &point)
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;

    return *this;
}

Point &Point::operator=(Point &&point) noexcept
{
    this->x = point.x;
    this->y = point.y;
    this->z = point.z;

    point.~Point();

    return *this;
}

Point Point::operator+(const Point &point)
{
    auto sum = Point(point);
    sum += *this;

    return sum;
}

Point &Point::operator+=(const Point &point)
{
    this->x += point.x;
    this->y += point.y;
    this->z += point.z;

    return *this;
}

Point Point::operator-(const Point &point)
{
    auto sub = Point(*this);
    sub -= point;

    return sub;
}

Point &Point::operator-=(const Point &point)
{
    this->x -= point.x;
    this->y -= point.y;
    this->z -= point.z;

    return *this;
}

void Point::move(const float dx, const float dy, const float dz)
{
    this->x += dx;
    this->y += dy;
    this->z += dz;
}

void Point::scale(const float kx, const float ky, const float kz)
{
    this->x = this->x * kx;
    this->y = this->y * ky;
    this->z = this->z * kz;
}

void Point::rotate(const float ox, const float oy, const float oz)
{
    rotate_xpoint(ox);
    rotate_ypoint(oy);
    rotate_zpoint(oz);
}

void Point::rotate_xpoint(const float ox)
{
    double
        radians = static_cast<float>(ox * M_PI / 180);
    float
        cos_r = static_cast<float>(cos(radians)),
        sin_r = static_cast<float>(sin(radians)),
        yt = this->y,
        zt = this->z;

    this->y = yt * cos_r - zt * sin_r;
    this->z = zt * cos_r + yt * sin_r;
}


void Point::rotate_ypoint(const float oy)
{
    double
        radians = static_cast<float>(oy * M_PI / 180);
    float
        cos_r = static_cast<float>(cos(radians)),
        sin_r = static_cast<float>(sin(radians)),
        xt = this->x,
        zt = this->z;

    this->x = xt * cos_r + zt * sin_r;
    this->z = zt * cos_r - xt * sin_r;
}


void Point::rotate_zpoint(const float oz)
{
    double
        radians = static_cast<float>(oz * M_PI / 180);
    float
        cos_r = static_cast<float>(cos(radians)),
        sin_r = static_cast<float>(sin(radians)),
        xt = this->x,
        yt = this->y;

    this->x = xt * cos_r - yt * sin_r;
    this->y = yt * cos_r + xt * sin_r;
}

float Point::getX() const
{
    return this->x;
}

float Point::getY() const
{
    return this->y;
}

float Point::getZ() const
{
    return this->z;
}

void Point::setX(const float newX)
{
    this->x = newX;
}

void Point::setY(const float newY)
{
    this->y = newY;
}

void Point::setZ(const float newZ)
{
    this->z = newZ;
}

Point Point::operator*(const Point &point)
{
    auto sub = Point(*this);
    sub *= point;

    return sub;
}

Point &Point::operator*=(const Point &point)
{
    this->x *= point.x;
    this->y *= point.y;
    this->z *= point.z;

    return *this;
}


Point Point::operator/(const Point &point)
{
    auto sub = Point(*this);
    sub /= point;

    return sub;
}

Point &Point::operator/=(const Point &point)
{
    this->x /= point.x;
    this->y /= point.y;
    this->z /= point.z;

    return *this;
}
