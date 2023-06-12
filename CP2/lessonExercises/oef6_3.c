#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint16_t type;
    uint32_t size;
    uint16_t reserved1;
    uint16_t reserved2;
    uint32_t offset;
} BMPHeader;

typedef struct {
    uint32_t size;
    int32_t width;
    int32_t height;
    uint16_t planes;
    uint16_t bits_per_pixel;
    uint32_t compression;
    uint32_t image_size;
    int32_t x_pixels_per_meter;
    int32_t y_pixels_per_meter;
    uint32_t total_colors;
    uint32_t important_colors;
} BMPInfoHeader;

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;
#pragma pack(pop)

void rotateImage(Pixel* image, int width, int height) {
    Pixel* temp = (Pixel*)malloc(width * height * sizeof(Pixel));
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            temp[i * width + j] = image[(height - i - 1) * width + j];
        }
    }
    for (int i = 0; i < width * height; i++) {
        image[i] = temp[i];
    }
    free(temp);
}

int main() {
    const char* input_filename = "input.bmp";
    const char* output_filename = "output.bmp";

    FILE* input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        printf("Kon het bestand niet openen: %s\n", input_filename);
        return 1;
    }

    BMPHeader header;
    BMPInfoHeader info_header;

    // BMP-headers inlezen
    fread(&header, sizeof(BMPHeader), 1, input_file);
    fread(&info_header, sizeof(BMPInfoHeader), 1, input_file);

    // Afbeelding breedte en hoogte
    int width = info_header.width;
    int height = info_header.height;

    // RGB-pixels inlezen
    Pixel* pixels = (Pixel*)malloc(width * height * sizeof(Pixel));
    fread(pixels, sizeof(Pixel), width * height, input_file);

    fclose(input_file);

    // Afbeelding 90 graden draaien
    rotateImage(pixels, width, height);
    int temp = width;
    width = height;
    height = temp;

    FILE* output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        printf("Kon het bestand niet schrijven: %s\n", output_filename);
        return 1;
    }

    // BMP-headers schrijven
    fwrite(&header, sizeof(BMPHeader), 1, output_file);
    fwrite(&info_header, sizeof(BMPInfoHeader), 1, output_file);

    // RGB-pixels schrijven
    fwrite(pixels, sizeof(Pixel), width * height, output_file);

    fclose(output_file);

    printf("Afbeelding is succesvol gedraaid en opgeslagen als: %s\n", output_filename);

    free(pixels);

    return 0;
}
