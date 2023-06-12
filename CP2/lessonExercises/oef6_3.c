#include <stdio.h>
#include <stdlib.h>
#include "bitmap.h"

int main() {
    const char* input_filename = "input.bmp";
    const char* output_filename = "output.bmp";

    // BMP-afbeelding inlezen
    BMPImage* image = BMP_LoadFromFile(input_filename);
    if (image == NULL) {
        printf("Kon het bestand niet openen: %s\n", input_filename);
        return 1;
    }

    // Afbeelding 90 graden draaien
    BMPImage* rotated_image = BMP_Create(image->header.height, image->header.width);
    for (int i = 0; i < image->header.height; i++) {
        for (int j = 0; j < image->header.width; j++) {
            Pixel* pixel = BMP_GetPixel(image, j, i);
            BMP_SetPixel(rotated_image, i, image->header.width - 1 - j, *pixel);
        }
    }

    // BMP-afbeelding schrijven
    if (!BMP_WriteToFile(rotated_image, output_filename)) {
        printf("Kon het bestand niet schrijven: %s\n", output_filename);
        return 1;
    }

    printf("Afbeelding is succesvol gedraaid en opgeslagen als: %s\n", output_filename);

    // Geheugen vrijgeven
    BMP_FreeImage(image);
    BMP_FreeImage(rotated_image);

    return 0;
}
