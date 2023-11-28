
#include "header/bmp_image.h"



int BMPImage::get_width() const {
    return m_width;
}

int BMPImage::get_height() const {
    return m_height;
}

void BMPImage::set_width(const int &new_width) {
    m_width=new_width;
}

void BMPImage::set_height(const int &new_height) {
    m_height=new_height;
}

std::vector<std::vector<Pixel>> BMPImage::get_pixels() const {
    return m_pixels;
}

void BMPImage::set_pixels(const std::vector<std::vector<Pixel>> &pixels) {
    m_pixels=pixels;
}
