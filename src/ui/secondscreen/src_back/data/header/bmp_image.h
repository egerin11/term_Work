
#ifndef TERM_WORK_BMP_IMAGE_H
#define TERM_WORK_BMP_IMAGE_H


#include "image.h"

class BMPImage : public Image {
public:
    BMPImage() :Image() {};

    std::vector<std::vector<Pixel>> get_pixels() const override;

    void set_pixels(const std::vector<std::vector<Pixel>> &pixels) override;

    int get_width() const override;

    int get_height() const override;

    void set_width(const int &new_width) override;

    void set_height(const int &new_height) override;


};


#endif //TERM_WORK_BMP_IMAGE_H
