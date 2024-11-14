#pragma once

#include "abstract_painter.hpp"
#include <vector>
#include <string>

class Painter : public AbstractPainter {
public:
    virtual void DrawImage(Point topLeft, Point bottomRight, std::vector<std::vector<char>>& image) override;
    virtual void WriteText(Point position, const std::string& text) override;
};
