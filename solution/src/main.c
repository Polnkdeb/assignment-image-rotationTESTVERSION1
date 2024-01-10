

#include <stdio.h>

#include "deserializer.h"
#include "serializer.h"
#include "image.h"
#include "rotate.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <source-image> <transformed-image>\n", argv[0]);
        return 1;
    }

    FILE *in = fopen(argv[1], "rb");
    if (in == NULL) {
        printf("Error opening source image file\n");
        return 1;
    }

    FILE *out = fopen(argv[2], "wb");
    if (out == NULL) {
        printf("Error opening transformed image file\n");
        fclose(in);
        return 1;
    }

    struct image img = {0};
    enum read_status status = from_bmp(in, &img);
    if (status != READ_OK) {
        printf("Error reading source image: %d\n", status);
        fclose(in);
        fclose(out);
        free_img(img);
        return 1;
    }

    struct image transformed_img = rotate(img);

    enum write_status write_status = to_bmp(out, &transformed_img);
    if (write_status != WRITE_OK) {
        printf("Error writing transformed image: %d\n", write_status);
        fclose(in);
        fclose(out);
        free_img(img);
        free_img(transformed_img);
        return 1;
    }

    free_img(img);
    free_img(transformed_img);
    fclose(in);
    fclose(out);

    return 0;
}
