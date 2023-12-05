
#include <QString>
#include <QProcess>
#include "convert.h"
#include<QDebug>
#include <QTextCodec>
#include <fstream>
#include <cmath>



void Convert::ascii(const Image *image,const std::string& file_path) {
    const std::string ASCII_LIST = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    std::vector<std::vector<Pixel>> pixels = image->get_pixels();

    std::ofstream output_file(file_path);

    if (output_file.is_open()) {
        for (int y = 0; y < image->get_height(); y++) {
            for (int x = 0; x < image->get_width(); x++) {
                int ascii_index = static_cast<int>(map(static_cast<float>(pixels[y][x].m_red), 0, 255, 0, static_cast<float>(ASCII_LIST.length()) - 1));
                char ascii_char = ASCII_LIST[ascii_index];

                output_file << ascii_char;
            }
            output_file << std::endl;
        }

        output_file.close();
    } else {
        std::cerr << "Unable to open the output file." << std::endl;
    }
}
    float Convert::map(float value, float start1, float stop1, float start2, float stop2) {
        return ((value - start1) / (stop1 - start1)) * (stop2 - start2) + start2;

    }

void Convert::grayscale(Image *image) {
    std::vector<std::vector<Pixel>> pixels = image->get_pixels();
    std::vector<std::vector<Pixel>> grayscale_pixels(image->get_height(), std::vector<Pixel>(image->get_width()));

    for (int i = 0; i < image->get_height(); i++) {
        for (int j = 0; j < image->get_width(); j++) {
            auto gray = (unsigned char) (0.3 * (int) pixels[i][j].m_red + 0.12 * (int) pixels[i][j].m_blue +
                                         0.58 * (int) pixels[i][j].m_green);
            grayscale_pixels[i][j].m_red = gray;
            grayscale_pixels[i][j].m_green = gray;
            grayscale_pixels[i][j].m_blue = gray;
        }
    }

    image->set_pixels(grayscale_pixels);
}




std::vector<std::vector<Pixel>> Convert::resized_image(Image *image, int new_height, int new_width) {
    std::vector<std::vector<Pixel>> resized_image(new_height, std::vector<Pixel>(new_width));
    std::vector<std::vector<Pixel>> pixel = image->get_pixels();

    int old_h = image->get_height();
    int old_w = image->get_width();
    image->set_height(new_height);
    image->set_width(new_width);
    float w_scale_factor = static_cast<float>(old_w) / static_cast<float>(new_width);
    float h_scale_factor = static_cast<float>(old_h) / static_cast<float>(new_height);

    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            float x = i * h_scale_factor;
            float y = j * w_scale_factor;

            int x_floor = static_cast<int>(floor(x));
            int x_ceil = std::min(old_h - 1, static_cast<int>(ceil(x)));
            int y_floor = static_cast<int>(floor(y));
            int y_ceil = std::min(old_w - 1, static_cast<int>(ceil(y)));

            if (x_ceil == x_floor && y_ceil == y_floor) {
                resized_image[i][j] = pixel[x_floor][y_floor];
            } else if (x_ceil == x_floor) {
                Pixel q1 = pixel[x_floor][y_ceil];
                Pixel q2 = pixel[x_floor][y_floor];
                Pixel q;
                q = q1* (y_ceil - y) + q2 * (y - y_floor);

                resized_image[i][j] = q;
            } else if (y_ceil == y_floor) {
                Pixel q1 = pixel[x_ceil][y_floor];
                Pixel q2 = pixel[x_floor][y_floor];
                Pixel q;
                q = q1 * (x_ceil - x) + q2 * (x - x_floor);

                resized_image[i][j] = q;
            } else {
                Pixel v1 = pixel[x_floor][y_floor];
                Pixel v2 = pixel[x_ceil][y_floor];
                Pixel v3 = pixel[x_floor][y_ceil];
                Pixel v4 = pixel[x_ceil][y_ceil];
                Pixel q1, q2, q;
                q1 = v1 * (x_ceil - x) + v2* (x - x_floor);

                q2 = v3 * (x_ceil - x) + v4 * (x - x_floor);

                q = q1 * (y_ceil - y) + q2 * (y - y_floor);

                resized_image[i][j] = q;
            }
        }
    }

    return resized_image;
}






