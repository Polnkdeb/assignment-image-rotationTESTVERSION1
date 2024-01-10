//
// Created by Полина Калугина on 05.01.2024.
//
#include <stdlib.h>

#include "rotate.h"

struct image rotate(struct image const source) {
    struct image transformed_img = {0};
    transformed_img.width = source.height;
    transformed_img.height = source.width;
    transformed_img.data = malloc(sizeof(struct pixel) * transformed_img.width * transformed_img.height);

    for (uint32_t i = 0; i < transformed_img.height; i++) {
        for (uint32_t j = 0; j < transformed_img.width; j++) {
            transformed_img.data[i * transformed_img.width + j] = source.data[(source.height - j - 1) * source.width + i];
        }
    }

    return transformed_img;
}
