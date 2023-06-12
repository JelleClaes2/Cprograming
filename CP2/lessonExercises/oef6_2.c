#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} Pixel;

void split_bmp_channels(const char* file_name) {
    FILE* file = fopen(file_name, "rb");
    if (file == NULL) {
        printf("Kan het bestand niet openen.\n");
        return;
    }

    // Lees de BMP header
    unsigned char bmp_header[54];
    fread(bmp_header, sizeof(unsigned char), 54, file);

    // Bepaal de breedte en hoogte van de afbeelding
    int width = *(int*)&bmp_header[18];
    int height = *(int*)&bmp_header[22];

    // Bepaal de grootte van de pixelgegevens
    int pixel_data_size = width * height * sizeof(Pixel);

    // Lees de pixelgegevens
    Pixel* pixels = (Pixel*)malloc(pixel_data_size);
    fread(pixels, sizeof(Pixel), width * height, file);

    // Maak nieuwe afbeeldingen voor elk kleurkanaal
    Pixel* red_pixels = (Pixel*)malloc(pixel_data_size);
    Pixel* green_pixels = (Pixel*)malloc(pixel_data_size);
    Pixel* blue_pixels = (Pixel*)malloc(pixel_data_size);

    // Split de kanalen
    for (int i = 0; i < width * height; i++) {
        red_pixels[i].red = pixels[i].red;
        green_pixels[i].green = pixels[i].green;
        blue_pixels[i].blue = pixels[i].blue;
    }

    // Sla de nieuwe afbeeldingen op
    FILE* red_file = fopen("fileName_red.BMP", "wb");
    FILE* green_file = fopen("fileName_green.BMP", "wb");
    FILE* blue_file = fopen("fileName_blue.BMP", "wb");

    // Schrijf de BMP header naar elk bestand
    fwrite(bmp_header, sizeof(unsigned char), 54, red_file);
    fwrite(bmp_header, sizeof(unsigned char), 54, green_file);
    fwrite(bmp_header, sizeof(unsigned char), 54, blue_file);

    // Schrijf de pixelgegevens naar elk bestand
    fwrite(red_pixels, sizeof(Pixel), width * height, red_file);
    fwrite(green_pixels, sizeof(Pixel), width * height, green_file);
    fwrite(blue_pixels, sizeof(Pixel), width * height, blue_file);

    // Sluit de bestanden
    fclose(file);
    fclose(red_file);
    fclose(green_file);
    fclose(blue_file);

    // Geef het geheugen vrij
    free(pixels);
    free(red_pixels);
    free(green_pixels);
    free(blue_pixels);

    printf("De afbeelding is opgesplitst in de rode, groene en blauwe kanalen.\n");
}

int main() {
    const char* file_name = "afbeelding.bmp";
    split_bmp_channels(file_name);
    return 0;
}
