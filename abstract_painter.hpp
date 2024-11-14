#pragma once

#include "point.hpp"

// interfata pentru desenarea obiectelor.
struct AbstractPainter {
    virtual void DrawImage(const Point& topLeft, const Point& bottomRight, const std::vector<std::vector<char>>& image) = 0;
    virtual void WriteText(const Point& position, const std::string& text) = 0;
};
