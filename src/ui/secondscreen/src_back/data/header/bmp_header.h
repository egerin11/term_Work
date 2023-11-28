

#ifndef TERM_WORK_BMP_HEADER_H
#define TERM_WORK_BMP_HEADER_H

#pragma pack(push,1)

typedef struct  {
    char m_magic[2];
    unsigned int m_size;
    unsigned int m_reserved;
    unsigned int m_offset;
}BMPFileHeader;

typedef struct  {

    unsigned int m_header_size;
    int m_width;
    int m_height;
    unsigned short m_planes;
    unsigned short m_bpp;
    unsigned int m_compression;
    unsigned int m_image_size;
    int m_x_ppm;
    int m_y_ppm;
    unsigned int m_colors;
    unsigned int m_important_colors;
}BMPImageHeader;
#pragma pack(pop)


#endif //TERM_WORK_BMP_HEADER_H
