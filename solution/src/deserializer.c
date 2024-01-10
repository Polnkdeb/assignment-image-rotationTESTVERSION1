//
// Created by Полина Калугина on 05.01.2024.
//
#include <stdlib.h>

#include "deserializer.h"

enum read_status from_bmp(FILE* in, struct image* img) {
    // Чтение заголовка BMP файла

    struct bmp_header header;
    if (fread(&header, sizeof(struct bmp_header), 1, in) != 1) {
        return READ_INVALID_HEADER;
    }

    // Проверка сигнатуры BMP файла

    if (header.bfType != BMP_TYPE) {
        return READ_INVALID_SIGNATURE;
    }

    // Проверка битности BMP файла

    if (header.biBitCount != BMP_BITS) {
        return READ_INVALID_BITS;
    }

    // Определение размеров изображения

    img->width = header.biWidth;
    img->height = header.biHeight;

    //Выделение памяти для хранения пикселей изображения

    img->data = malloc(sizeof(struct pixel) * img->width * img->height);
    if (img->data == NULL) {
        return READ_MEMORY_ERROR;
    }

    // Чтение пикселей изображения

    const uint8_t padding = cal_padding(img->width);

    for (uint32_t i = 0; i < img->height; i++) {

        if (fread(img->data + i * img->width, sizeof(struct pixel),
                img->width,in) != img->width || fseek(in, padding, SEEK_CUR))  {
                free_img(*img);
                return READ_INVALID_BITS;
            }
    }

    return READ_OK;
}

