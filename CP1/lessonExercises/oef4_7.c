/*
    Volgende code zou PXL in grote letters verticaal printen, maar het gaat mis.
*/

#include <stdio.h>

int main( void )
{
	int i = 0;
	int j = 0;
	while( i++ < 2 )
	{
		while( j++ < 24 )
		{
			printf( "P" );
		}
		printf( "\n" );
    j=0;
	}
  i=0;
	while( i++ < 2 )
	{
		while( j++ < 8 )
		{
			printf( "P" );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( " " );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( "P" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;
	while( i++ < 2 )
	{
		while( j++ < 24 )
		{
			printf( "P" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;
	while( i++ < 6 )
	{
		while( j++ < 8 )
		{
			printf( "P" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;
	while( i++ < 4 )
	{
		printf( "\n" );
	}
  i=0;
	while( i++ < 4 )
	{
		while( j++ < 8 )
		{
			printf( "X" );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( " " );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( "X" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;
	while( i++ < 4 )
	{
		while( j++ < 8 )
		{
			printf( " " );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( "X" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;
	while( i++ < 4 )
	{
		while( j++ < 8 )
		{
			printf( "X" );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( " " );
		}
    j=0;
		while( j++ < 8 )
		{
			printf( "X" );
		}
    j=0;
		printf( "\n" );
	}
  i=0;

	while( i++ < 4 )
	{
		printf( "\n" );
	}
  i=0;
	while( i++ < 12 )
	{
		j=0;
    while( j++ < 8 )
		{
			printf( "L" );
		}
		printf( "\n" );
	}
  i=0;
	while( i++ < 2 )
	{
		j=0;
    while( j++ < 24 )
		{
			printf( "L" );
		}
		printf( "\n" );
	}
	return 0;
}
