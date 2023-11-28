
#ifndef TERM_WORK_IMAGE_H
#define TERM_WORK_IMAGE_H

#include <vector>
#include "pixel.h"
class Pixel;

class Image {
public:
     Image()=default;
    virtual ~Image() = default;
    virtual std::vector<std::vector<Pixel>> get_pixels() const = 0;

    virtual void set_pixels(const std::vector<std::vector<Pixel>> &pixels) = 0;
    void get_pixel(int x,int y,Pixel& pixel);
    void set_pixel(int x,int y,unsigned char red,unsigned char g,unsigned char b);
   virtual int get_width() const = 0;


    virtual int get_height() const = 0;

    virtual void set_width(const int &new_width) = 0;

    virtual void set_height(const int &new_height) = 0;

protected:
    int m_width;
    int m_height;
    std::vector<std::vector<Pixel>> m_pixels;
};




#endif //TERM_WORK_IMAGE_H
