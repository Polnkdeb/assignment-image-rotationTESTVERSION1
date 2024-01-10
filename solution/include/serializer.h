//
// Created by Полина Калугина on 05.01.2024.
//

#include <stdio.h>

#include "bmp.h"
#include "image.h"
#include "utils.h"

#ifndef ASSIGNMENT_IMAGE_ROTATION2_SERIALIZER_H
#define ASSIGNMENT_IMAGE_ROTATION2_SERIALIZER_H

enum  write_status  {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status to_bmp( FILE* out, struct image const* img );

#endif //ASSIGNMENT_IMAGE_ROTATION2_SERIALIZER_H



