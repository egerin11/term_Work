//
// Created by egerin on 11/14/23.
//

#ifndef TERM_WORK_PPM_IMAGE_H
#define TERM_WORK_PPM_IMAGE_H

#include "image.h"

class PPMImage : public Image {
public:
    PPMImage():Image(){}
    void read_image(const std::string &file_name);

    int get_width() const override;

    std::vector<std::vector<Pixel>> get_pixels() const override;

    void set_pixels(const std::vector<std::vector<Pixel>> &pixels) override;

    int get_height() const override;

    void set_width(const int &new_width) override;

    void set_height(const int &new_height) override;

private:
    int m_max_color;
    std::string m_magic;
    char m_last_line;


};


#endif //TERM_WORK_PPM_IMAGE_H
