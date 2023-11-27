
#ifndef TERM_WORK_PIXEL_H
#define TERM_WORK_PIXEL_H

#include "../../data_model/convert.h"

#pragma pack(push, 1)

class Pixel {
    friend class BMPImageProcess;
    friend class PPMImage;
    friend class Convert;

    friend class Image;


private:
    unsigned char m_blue;
    unsigned char m_green;
    unsigned char m_red;
public:
    Pixel() : m_blue(0), m_green(0), m_red(0) {}

    Pixel(unsigned char blue, unsigned char green, unsigned char red)
            : m_blue(blue), m_green(green), m_red(red) {}


    Pixel operator/(double value) const {
        Pixel result;
        result.m_red = m_red / (unsigned char) value;
        result.m_green = m_green / (unsigned char) value;
        result.m_blue = m_blue / (unsigned char) value;
        return result;
    }

    Pixel &operator+=(const Pixel &other) {
        m_red += other.m_red;
        m_green += other.m_green;
        m_blue += other.m_blue;
        return *this;
    }

    Pixel operator*(double value) const {
        return {static_cast<unsigned char>(m_blue * value),
                static_cast<unsigned char>(m_green * value),
                static_cast<unsigned char>(m_red * value)};
    }

    Pixel operator+(const Pixel &other) const {
        return {static_cast<unsigned char>(m_blue + other.m_blue),
                static_cast<unsigned char>(m_green + other.m_green),
                static_cast<unsigned char>(m_red + other.m_red)};
    }

};

#pragma pack(pop)

#endif //TERM_WORK_PIXEL_H
