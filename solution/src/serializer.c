//
// Created by Полина Калугина on 05.01.2024.
//

#include "serializer.h"


enum write_status to_bmp(FILE* out, struct image const* img) {
    // Создание и заполнение заголовка BMP файла
    uint8_t padding = cal_padding(img->width);
    struct bmp_header header = {0};
    header.bfType = BMP_TYPE;
    header.bfileSize = ((sizeof(struct pixel) * img->width + padding) * img->height + sizeof (struct bmp_header));
    header.bfReserved = 0;
    header.bOffBits = sizeof(struct bmp_header);
    header.biSize = BMP_SIZE;
    header.biWidth = img->width;
    header.biHeight = img->height;
    header.biPlanes = PLANE_NUMBER;
    header.biBitCount = BMP_BITS;
    header.biCompression = COMPRESSION;
    header.biXPelsPerMeter = 0;
    header.biYPelsPerMeter = 0;
    header.biClrUsed = 0;
    header.biClrImportant = 0;

    // Запись заголовка в файл
    if (fwrite(&header, sizeof(struct bmp_header), 1, out) != 1) {
        return WRITE_ERROR;
    }

    // Запись пикселей изображения в файл

    const uint32_t trash = 0;
    for(uint32_t i = 0; i < img->height; i++){
        if(fwrite(img->data + i * img->width, sizeof(struct pixel), img->width, out)!= img->width||
           fwrite(&trash,1,padding, out)!=padding) return WRITE_ERROR;
    }
    return WRITE_OK;
}
