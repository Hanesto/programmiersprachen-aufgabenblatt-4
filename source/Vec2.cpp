#include <iostream>
#include "Vec2.hpp"

Vec2& Vec2::operator += (Vec2 const& v)
{
    x += v.x;
    y += v.y;
    return *this;
}

Vec2& Vec2::operator -= (Vec2 const& v)
{
    x -= v.x;
    y -= v.y;
    return *this;
}

Vec2& Vec2::operator *= (float s)
{
    x = x*s;
    y = y*s;
    return *this;
}

Vec2& Vec2::operator /= (float s)
{
    x = x/s;
    y = y/s;
    return *this;
}

Vec2 operator +(Vec2 const& u, Vec2 const& v)
{
    Vec2 answer;

    answer.x = u.x + v.x;
    answer.y = u.y + v.y;

    return answer;
}

Vec2 operator -(Vec2 const& u, Vec2 const& v)
{
    Vec2 answer;

    answer.x = u.x - v.x;
    answer.y = u.y - v.y;

    return answer;
}

Vec2 operator *(Vec2 const& u, float s)
{
    Vec2 answer;

    answer.x = u.x * s;
    answer.y = u.y * s;

    return answer;
}

Vec2 operator /(Vec2 const& u, float s)
{
    Vec2 answer;

    answer.x = u.x / s;
    answer.y = u.y / s;

    return answer;
}
