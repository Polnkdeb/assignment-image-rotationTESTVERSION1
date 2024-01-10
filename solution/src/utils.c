//
// Created by Полина Калугина on 10.01.2024.
//
#include <stdlib.h>

#include "utils.h"

#define IMG_ALIGN 4

uint32_t cal_padding(uint32_t width)
{
    return (IMG_ALIGN - (width * sizeof(struct pixel)) % IMG_ALIGN) % IMG_ALIGN;
}

void free_img(struct image img){
    if(img.data != NULL)
        free(img.data);
}
