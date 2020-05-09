/* 
 * mono_point.hpp
 * Use for MonoSearchNode::move as vector<MonoPoint>.
 * Monoli::m_method should be able to use MonoPoint.
 */
#ifndef _MONO_POINT_HPP_
#define _MONO_POINT_HPP_


#include <iostream>
#include <string>

class MonoPoint {
public:
    unsigned char x;
    unsigned char y;
    MonoPoint() : x(0), y(0) { }
    MonoPoint(unsigned char y, unsigned char x) : x(x), y(y) { }
    MonoPoint(const MonoPoint& mp) : x(mp.x), y(mp.y) { }
    std::string string() const;
};

std::ostream& operator<<(std::ostream& stream, const MonoPoint& value);

#endif