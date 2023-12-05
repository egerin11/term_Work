//
// Created by egerin on 12/5/23.
//

#include "header/other_image.h"

std::vector<std::vector<Pixel>> OtherImage::get_pixels() const {
    return m_pixels;
}

void OtherImage::set_pixels(const std::vector<std::vector<Pixel>> &pixels) {
m_pixels=pixels;
}

int OtherImage::get_width() const {
    return m_width;
}

int OtherImage::get_height() const {
    return m_height;
}

void OtherImage::set_width(const int &new_width) {
m_width=new_width;
}

void OtherImage::set_height(const int &new_height) {
m_height=new_height;
}
