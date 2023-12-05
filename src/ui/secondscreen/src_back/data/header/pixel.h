
#ifndef TERM_WORK_PIXEL_H
#define TERM_WORK_PIXEL_H

#include "../../../convert.h"

#pragma pack(push, 1)

struct Pixel {

    unsigned char m_blue;
    unsigned char m_green;
    unsigned char m_red;
    Pixel operator+(const Pixel& other) const {
        Pixel result;
        result.m_red = static_cast<unsigned char>( static_cast<int>(m_red) + static_cast<int>(other.m_red));
        result.m_green = static_cast<unsigned char>( static_cast<int>(m_green) + static_cast<int>(other.m_green));
        result.m_blue = static_cast<unsigned char>( static_cast<int>(m_blue) + static_cast<int>(other.m_blue));
        return result;
    }

    Pixel operator-(const Pixel& other) const {
        Pixel result;
        result.m_red = static_cast<unsigned char>(static_cast<int>(m_red) - static_cast<int>(other.m_red));
        result.m_green = static_cast<unsigned char>( static_cast<int>(m_green) - static_cast<int>(other.m_green));
        result.m_blue = static_cast<unsigned char>( static_cast<int>(m_blue) - static_cast<int>(other.m_blue));
        return result;
    }

    Pixel operator*(float scalar) const {
        Pixel result;
        result.m_red = static_cast<unsigned char>( static_cast<float >(m_red) * scalar);
        result.m_green = static_cast<unsigned char>( static_cast<float >(m_green) * scalar);
        result.m_blue = static_cast<unsigned char>(static_cast<float >(m_blue) * scalar);
        return result;
    }

    bool operator==(const Pixel& other) const {
        return m_red == other.m_red && m_green == other.m_green && m_blue == other.m_blue;
    }

    bool operator!=(const Pixel& other) const {
        return !(*this == other);
    }

};

#pragma pack(pop)

#endif //TERM_WORK_PIXEL_H
