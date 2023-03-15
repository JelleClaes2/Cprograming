/*
  Schrijf een programma dat een geheel bedrag in euro inleest, bijvoorbeeld: 8631 en dan afdrukt wat het kleinste aantal biljetten en munten zijn.
  Bijvoorbeeld:
  17x500
  0x200
  1x100
  0x50
  1x20
  1x10
  0x5
  0x2
  1x1
*/
#include <stdio.h>
#include <stdint.h>

int main( void )
{
    uint64_t bedrag = 0;
    uint64_t vijfhonderd = 0;
    uint8_t tweehonderd = 0;
    uint8_t honderd = 0;
    uint8_t vijftig = 0;
    uint8_t twintig = 0;
    uint8_t tien = 0;
    uint8_t vijf = 0;
    uint8_t twee = 0;
    uint8_t een = 0;
    uint16_t restBedrag = 0;

    printf( "Geef een bedrag in Euro: " );
    (void)scanf( "%ld", &bedrag );

    // Bereken het aantal 500 biljetten
    vijfhonderd = bedrag / 500;
    restBedrag = bedrag % 500;
    printf( "%ldx500\n", vijfhonderd );

    // Bereken het aantal 200 biljetten
    tweehonderd = restBedrag / 200;
    restBedrag = restBedrag % 200;
    printf( "%hhdx200\n", tweehonderd );

    // Bereken het aantal 100 biljetten
    honderd = restBedrag / 100;
    restBedrag = restBedrag % 100;
    printf( "%hhdx100\n", honderd );

    // Bereken het aantal 50 biljetten
    vijftig = restBedrag / 50;
    restBedrag = restBedrag % 50;
    printf( "%hhdx50\n", vijftig );

    // Bereken het aantal 20 biljetten
    twintig = restBedrag / 20;
    restBedrag = restBedrag % 20;
    printf( "%hhdx20\n", twintig );

    // Bereken het aantal 10 biljetten
    tien = restBedrag / 10;
    restBedrag = restBedrag % 10;
    printf( "%hhdx10\n", tien );

    // Bereken het aantal 5 biljetten
    vijf = restBedrag / 5;
    restBedrag = restBedrag % 5;
    printf( "%hhdx5\n", vijf );

    // Bereken het aantal 2 munten
    twee = restBedrag / 2;
    printf( "%hhdx2\n", twee );

    // Bereken het aantal 1 munten
    een = restBedrag % 1;
    printf( "%hhdx1", een );

    return 0;
}
