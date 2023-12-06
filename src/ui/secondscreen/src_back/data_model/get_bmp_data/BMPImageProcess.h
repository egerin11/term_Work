//
// Created by egerin on 10/31/23.
//

#ifndef TERM_WORK_BMPIMAGEPROCESS_H
#define TERM_WORK_BMPIMAGEPROCESS_H


#include <vector>
#include "../../data/header/bmp_header.h"
#include "../../data/header/pixel.h"
#include <iostream>


class BMPImageProcess {
public:
    void read_image(const std::string &file_name);

    std::vector<std::vector<Pixel>> get_pixels() const;

    int get_width() const;

    int get_height() const;



private:
    std::vector<std::vector<Pixel>> read_data_of_pixels(std::ifstream &file) const;
    BMPFileHeader m_bmpFileHeader;
    BMPImageHeader m_bmpImageHeader;
    std::vector<std::vector<Pixel>> m_pixels;
};


#endif //TERM_WORK_BMPIMAGEPROCESS_H
