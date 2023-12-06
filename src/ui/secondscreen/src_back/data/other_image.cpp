//
// Created by egerin on 12/5/23.
//

#include <QImageReader>
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

std::vector<std::vector<Pixel>> OtherImage::read(const QString &file_path) {
    std::vector<std::vector<Pixel>> pixels;

    QImageReader image_reader(file_path);
    QImage q_image = image_reader.read();
    pixels.resize(q_image.height(), std::vector<Pixel>(q_image.width()));
    for (int y = 0; y < q_image.height(); ++y) {
        for (int x = 0; x < q_image.width(); ++x) {
            QRgb pixel_color = q_image.pixel(x, y);

            Pixel pixel;
            pixel.m_red = qRed(pixel_color);
            pixel.m_green = qGreen(pixel_color);
            pixel.m_blue = qBlue(pixel_color);
            pixels[y][x] = pixel;
        }
    }
    set_height(q_image.height());
    set_width(q_image.width());
    return pixels;
}
