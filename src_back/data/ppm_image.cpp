
#include "header/ppm_image.h"
#include <fstream>

void PPMImage::read_image(const std::string &file_name) {

    std::ifstream input_file(file_name, std::ios::binary);
    if (!input_file.is_open()) {
        std::cout << "error: Could not open input file" << std::endl;
        return;
    }

    input_file >> m_magic >> m_width >> m_height >> m_max_color >> std::noskipws >> m_last_line;

    if (m_magic != "P6") {
        std::cout << "error: Invalid PPM file format" << std::endl;
        input_file.close();
        return;
    }

    Pixel pixel;
    std::vector<std::vector<Pixel>> pixels(m_height, std::vector<Pixel>(m_width));
    for (int i = 0; i < m_height; i++) {
        for (int j = 0; j < m_width; j++) {
            input_file >> pixel.m_red >> pixel.m_green >> pixel.m_blue;

            pixels[i][j] = pixel;
        }
    }
    m_pixels=pixels;
    input_file.close();
}

int PPMImage::get_width() const {
    return m_width;
}

std::vector<std::vector<Pixel>> PPMImage::get_pixels() const {
    return m_pixels;
}

void PPMImage::set_pixels(const std::vector<std::vector<Pixel>> &pixels) {
    m_pixels = pixels;
}

int PPMImage::get_height() const {
    return m_height;
}

void PPMImage::set_width(const int &new_width) {
    m_width = new_width;

}

void PPMImage::set_height(const int &new_height) {
    m_height = new_height;
}
