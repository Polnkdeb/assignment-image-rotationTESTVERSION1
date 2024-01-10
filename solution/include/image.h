//
// Created by Полина Калугина on 05.01.2024.
//

#include <stdint.h>

#ifndef ASSIGNMENT_IMAGE_ROTATION2_IMAGE_H
#define ASSIGNMENT_IMAGE_ROTATION2_IMAGE_H

struct image {
    uint32_t width, height;
    struct pixel* data;
};

struct pixel { uint8_t b, g, r; };

#endif //ASSIGNMENT_IMAGE_ROTATION2_IMAGE_H


