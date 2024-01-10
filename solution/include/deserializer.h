//
// Created by Полина Калугина on 05.01.2024.
//
#include <stdio.h>

#include "bmp.h"
#include "image.h"
#include "utils.h"

#ifndef ASSIGNMENT_IMAGE_ROTATION2_DESERIALIZER_H
#define ASSIGNMENT_IMAGE_ROTATION2_DESERIALIZER_H

enum read_status  {
    READ_OK = 0,
    READ_INVALID_SIGNATURE,
    READ_INVALID_BITS,
    READ_INVALID_HEADER,
    READ_MEMORY_ERROR
};

enum read_status from_bmp( FILE* in, struct image* img );

#endif //ASSIGNMENT_IMAGE_ROTATION2_DESERIALIZER_H


