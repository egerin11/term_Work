
#include "BMPImageProcess.h"
#include <fstream>

std::vector<std::vector<Pixel>> BMPImageProcess::read_data_of_pixels(std::ifstream &file) const {
    int bytesPP = m_bmpImageHeader.m_bpp / 8;
    int row_size = m_bmpImageHeader.m_width * bytesPP;
    int row_padding = (4 - (row_size % 4)) % 4;
    int pixel_offset = static_cast<int>(m_bmpFileHeader.m_offset) + row_padding;
    file.seekg(pixel_offset, std::ios::beg);
    std::vector<std::vector<Pixel>> image_pixels(m_bmpImageHeader.m_height,
                                                 std::vector<Pixel>(m_bmpImageHeader.m_width));
    auto *buffer = new unsigned char[bytesPP];
    for (int i = 0; i < m_bmpImageHeader.m_height; i++) {
        for (int j = 0; j < m_bmpImageHeader.m_width; j++) {
            file.read(reinterpret_cast<char *>(buffer), bytesPP);
            image_pixels[i][j].m_blue = buffer[0];
            image_pixels[i][j].m_green = buffer[1];
            image_pixels[i][j].m_red = buffer[2];
        }
    }
    delete[] buffer;
    return image_pixels;
}

void BMPImageProcess::read_image(const std::string &file_name) {
    std::ifstream file(file_name, std::ios::binary);
    if (!file.is_open()) {
        std::cerr << "unable to open file " << std::endl;
        file.close();
        return;
    }
    file.read(reinterpret_cast<char *>(&m_bmpFileHeader), sizeof(BMPFileHeader));
    if (m_bmpFileHeader.m_magic[0] != 'B' || m_bmpFileHeader.m_magic[1] != 'M') {
        std::cerr << "invalid file format" << std::endl;
        file.close();
        return;
    }
    file.read(reinterpret_cast<char *>(&m_bmpImageHeader), sizeof(BMPImageHeader));

    m_pixels = read_data_of_pixels(file);

    if (file.fail()) {
        std::cerr << "Unable to read image data" << std::endl;
        file.close();
        return;
    }
    file.close();
}

std::vector<std::vector<Pixel>> BMPImageProcess::get_pixels() const {
    return m_pixels;
}

int BMPImageProcess::get_width() const {
    return m_bmpImageHeader.m_width;
}

int BMPImageProcess::get_height() const {
    return m_bmpImageHeader.m_height;
}








