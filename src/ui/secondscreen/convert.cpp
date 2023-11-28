
#include <QString>
#include <QProcess>
#include "convert.h"
#include<QDebug>
#include <QTextCodec>
#include <fstream>

//void Convert::ascii(const Image *image, Ui::SecondScreen *ui) {
//    const std::string ASCII_LIST = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
//    std::vector<std::vector<Pixel>> pixels = image->get_pixels();
//    QString asciiArt;
//    for (int y = 0; y < image->get_height(); y++) {
//           for (int x = 0; x < image->get_width(); x++) {
//            int ascii_index = (int) map((float) pixels[y][x].m_red, 0, 255, 0, (float) ASCII_LIST.length() - 1);
//            char ascii_char = ASCII_LIST[ascii_index];
//            asciiArt.append(ascii_char);
//        }
//        asciiArt.append('\n');
//    }
//    ui->textBrowser->setText(asciiArt);
//}

void Convert::ascii(const Image *image,const std::string& outputFilePath) {
    const std::string ASCII_LIST = "$@B%8&WM#*oahkbdpqwmZO0QLCJUYXzcvunxrjft/|()1{}[]?-_+~<>i!lI;:,\"^`'. ";
    std::vector<std::vector<Pixel>> pixels = image->get_pixels();

    // Открываем файл для записи
    std::ofstream outputFile(outputFilePath);

    if (outputFile.is_open()) {
        for (int y = 0; y < image->get_height(); y++) {
            for (int x = 0; x < image->get_width(); x++) {
                int ascii_index = static_cast<int>(map(static_cast<float>(pixels[y][x].m_red), 0, 255, 0, static_cast<float>(ASCII_LIST.length()) - 1));
                char ascii_char = ASCII_LIST[ascii_index];

                outputFile << ascii_char;
            }
            outputFile << std::endl;
        }

        outputFile.close();
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


Pixel Convert::bilinear_interpolation(const Pixel &q11, const Pixel &q12, const Pixel &q21, const Pixel &q22, double x,
                                      double y) {
    Pixel r1 = q11 * (1 - x) + q12 * x;
    Pixel r2 = q21 * (1 - x) + q22 * x;
    return r1 * (1 - y) + r2 * y;
}

std::vector<std::vector<Pixel>> Convert::resized_image(Image *image, int new_height, int new_width) {
    std::vector<std::vector<Pixel>> resized_image(new_height, std::vector<Pixel>(new_width));
    std::vector<std::vector<Pixel>> pixel = image->get_pixels();
    int original_height = image->get_height();
    int original_width = image->get_width();
    double scale_x = (double) original_width / new_width;
    double scale_y = (double) original_height / new_height;

    for (int i = 0; i < new_height; i++) {
        for (int j = 0; j < new_width; j++) {
            double x = scale_x * j;
            double y = scale_y * i;

            int x_int = (int) x;
            int y_int = (int) y;

            double x_diff = x - x_int;
            double y_diff = y - y_int;

            if (x_int + 1 < original_width && y_int + 1 < original_height) {
                resized_image[i][j] = bilinear_interpolation(pixel[y_int][x_int], pixel[y_int][x_int + 1],
                                                             pixel[y_int + 1][x_int], pixel[y_int + 1][x_int + 1],
                                                             x_diff, y_diff);
            } else {
                resized_image[i][j] = pixel[y_int][x_int];
            }
        }
    }
    return resized_image;
}






