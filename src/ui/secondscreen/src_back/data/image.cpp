#include "header/image.h"


void Image::get_pixel(int x, int y, Pixel &pixel) {
    if (x < m_width && y < m_height) {
        pixel = m_pixels[x][y];

    }
}

void Image::set_pixel(int x, int y, unsigned char red, unsigned char green, unsigned char blue) {
    if (x < m_width && y < m_height) {
        m_pixels[x][y].m_red = red;
        m_pixels[x][y].m_green = green;
        m_pixels[x][y].m_blue = blue;
    }

}


