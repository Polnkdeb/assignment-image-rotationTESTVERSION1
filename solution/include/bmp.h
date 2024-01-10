//
// Created by Полина Калугина on 05.01.2024.
//
#include  <inttypes.h>
#include <stdio.h>
#include  <stdint.h>

#include "image.h"

#define BMP_TYPE 0x4d42
#define BMP_SIZE 40
#define BMP_BITS 24
#define PLANE_NUMBER 1
#define COMPRESSION 0

#ifndef ASSIGNMENT_IMAGE_ROTATION2_BMP_H
#define ASSIGNMENT_IMAGE_ROTATION2_BMP_H

#pragma pack(push, 1)
struct bmp_header
{
    uint16_t bfType;
    uint32_t  bfileSize;
    uint32_t bfReserved;
    uint32_t bOffBits;
    uint32_t biSize;
    uint32_t biWidth;
    uint32_t  biHeight;
    uint16_t  biPlanes;
    uint16_t biBitCount;
    uint32_t biCompression;
    uint32_t biSizeImage;
    uint32_t biXPelsPerMeter;
    uint32_t biYPelsPerMeter;
    uint32_t biClrUsed;
    uint32_t  biClrImportant;
};
#pragma pack(pop)

#endif //ASSIGNMENT_IMAGE_ROTATION2_BMP_H

