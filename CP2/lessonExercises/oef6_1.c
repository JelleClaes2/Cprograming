#include <stdio.h>
#include <stdlib.h>
#define BMPINPUT "test.bmp"
#define BMPOUTPUT "fileName_inverted.bmp"

int main(int argc, char const *argv[])
{
    FILE *inputBMP = fopen(BMPINPUT, "rb");
    unsigned char header[54] = {0};
    signed int hoogte = 0;
    signed int breedte = 0;
    unsigned char *pixels = NULL;
    int totaalAantalPixels = 0;

    if (inputBMP == NULL)
    {
        printf("%s\n", "ERROR: can't open the file");
        return -1;
    }

    fread(header, 1, 54, inputBMP);
    breedte = header[21] << 24 | header[20] << 16 | header[19] << 8 | header[18];
    printf("De breedte van mijn afbeelding is = %d\n", breedte);
    hoogte = header[25] << 24 | header[24] << 16 | header[23] << 8 | header[22];
    printf("De hoogte van mijn afbeelding is = %d\n", hoogte);
    totaalAantalPixels = breedte * hoogte;

    // Inlezen van de pixels
    int bytesPerRow = ((breedte * 3 + 3) / 4) * 4; // Het aantal bytes per rij, moet een veelvoud van 4 zijn
    int padding = bytesPerRow - breedte * 3;        // De padding aan het einde van elke rij
    pixels = (unsigned char *)malloc(totaalAantalPixels * 3 * sizeof(unsigned char));
    fread(pixels, 1, totaalAantalPixels * 3, inputBMP);

    // Kleurkanalen omkeren
    for (int i = 0; i < totaalAantalPixels; i++)
    {
        unsigned char temp = pixels[i * 3];             // Blauw kanaal
        pixels[i * 3] = pixels[i * 3 + 2];              // Rood kanaal
        pixels[i * 3 + 2] = temp;                        // Blauw kanaal
    }

    // Nieuw BMP-bestand maken en de omgekeerde afbeelding schrijven
    FILE *outputBMP = fopen(BMPOUTPUT, "wb");
    fwrite(header, 1, 54, outputBMP);
    fwrite(pixels, 1, totaalAantalPixels * 3, outputBMP);

    fclose(inputBMP);
    fclose(outputBMP);
    free(pixels);

    return 0;
}
