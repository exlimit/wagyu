#pragma once

#include <mapbox/geometry/point.hpp>

namespace mapbox { namespace geometry { namespace ring {

// fwd declare
template <typename T>
struct point;

template <typename T>
using point_ptr = point<T> *;

template <typename T>
using const_point_ptr = point<T> * const;

template <typename T>
struct point
{
    using coordinate_type = T;
    T x;
    T y;
    point_ptr<T> prev;
    point_ptr<T> next;
    
    point() :
        x(0), 
        y(0),
        prev(this),
        next(this) {}
    
    point(T x_, T y_) :
        x(x_),
        y(y_),
        prev(this),
        next(this) {}

    point(mapbox::geometry::point<T> const& pt) :
        x(pt.x),
        y(pt.y),
        prev(this),
        next(this) {}
    
    point(mapbox::geometry::point<T> const& pt,
          point_ptr<T> next_,
          point_ptr<T> prev_) :
        x(pt.x),
        y(pt.y),
        prev(prev_),
        next(next_) {}
};

template <typename T>
bool operator==(point<T> const& lhs, point<T> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
bool operator==(mapbox::geometry::point<T> const& lhs, point<T> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
bool operator==(point<T> const& lhs, mapbox::geometry::point<T> const& rhs)
{
    return lhs.x == rhs.x && lhs.y == rhs.y;
}

template <typename T>
bool operator!=(point<T> const& lhs, point<T> const& rhs)
{
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

template <typename T>
bool operator!=(mapbox::geometry::point<T> const& lhs, point<T> const& rhs)
{
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

template <typename T>
bool operator!=(point<T> const& lhs, mapbox::geometry::point<T> const& rhs)
{
    return lhs.x != rhs.x || lhs.y != rhs.y;
}

}}}
