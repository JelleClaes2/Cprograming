/*
  Schrijf een programma dat de volledige ASCII tabel uit print (char dec hex octal).
  De even waarden in de linkse kolom. De oneven waarden in de rechtse kolom.

  De eerste 32 waarden en 127 hebben geen printbaar karakter, print hiervoor een “spatie”

char dec   hex | char dec   hex | char dec   hex | char dec   hex
-------------------------------------------------------------------
       0     0 |        1   0x1 |        2   0x2 |        3   0x3 |
       4   0x4 |        5   0x5 |        6   0x6 |        7   0x7 |
       8   0x8 |        9   0x9 |       10   0xa |       11   0xb |
      12   0xc |       13   0xd |       14   0xe |       15   0xf |
      16  0x10 |       17  0x11 |       18  0x12 |       19  0x13 |
      20  0x14 |       21  0x15 |       22  0x16 |       23  0x17 |
      24  0x18 |       25  0x19 |       26  0x1a |       27  0x1b |
      28  0x1c |       29  0x1d |       30  0x1e |       31  0x1f |
      32  0x20 |   !   33  0x21 |   "   34  0x22 |   #   35  0x23 |
  $   36  0x24 |   %   37  0x25 |   &   38  0x26 |   '   39  0x27 |
  (   40  0x28 |   )   41  0x29 |   *   42  0x2a |   +   43  0x2b |
  ,   44  0x2c |   -   45  0x2d |   .   46  0x2e |   /   47  0x2f |
  0   48  0x30 |   1   49  0x31 |   2   50  0x32 |   3   51  0x33 |
  4   52  0x34 |   5   53  0x35 |   6   54  0x36 |   7   55  0x37 |
  8   56  0x38 |   9   57  0x39 |   :   58  0x3a |   ;   59  0x3b |
  <   60  0x3c |   =   61  0x3d |   >   62  0x3e |   ?   63  0x3f |
  @   64  0x40 |   A   65  0x41 |   B   66  0x42 |   C   67  0x43 |
  etc
*/

#include <stdio.h>

int main( void )
{
	int counter = 0;
	// TODO : Print header
  for(int i=0;i<4;i++){
    printf("char dec   hex ");
    if (i!=3) {
      printf("| ");
    }
  }
  printf("\n");
  for(int i=0;i<=66;i++){
    printf("-");
  }
  printf("\n");
	// TODO : Print lijn
	while( counter <= 126 )
	{
    for(int i=0; i<4;i++){
      char c=(char)counter;
      if(counter<=32||counter == 127){
        c=' ';
      }
      printf("  %c  %3d  %#4x | ",c,counter,counter );
      counter++;
    }
    printf("\n");
		// TODO : Print 2 spaties, karakter, 2 spaties, 3 tekens decimaal, 2 spaties, 4 tekens hexadecimaal, spatie, vertikale lijn, spatie
		// TODO : Print dat 4 keer na elkaar op 1 lijn
	}
	return 0;
}
