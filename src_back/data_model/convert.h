
#ifndef TERM_WORK_CONVERT_H
#define TERM_WORK_CONVERT_H


#include "../data/header/image.h"
#include <iostream>

class Image;

class Pixel;

class Convert {
public:
    static void ascii(const Image *image);

    static void grayscale(Image *image);


    static std::vector<std::vector<Pixel>> resized_image(Image *image, int new_height, int new_width);


private:
    static float map(float value, float start1, float stop1, float start2, float stop2);

    static Pixel
    bilinear_interpolation(const Pixel &q11, const Pixel &q12, const Pixel &q21, const Pixel &q22, double x, double y);

};

#endif //TERM_WORK_CONVERT_H
