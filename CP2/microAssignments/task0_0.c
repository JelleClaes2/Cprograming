// Fix me !

#include <stdio.h>
#include <stdint.h>
#include <ctype.h>

#pragma pack(1)
struct Person
{
    char name[500];
    int age;
    struct
    {
        uint8_t day : 5;
        uint8_t month : 4;
        uint16_t year : 15;
    } birthdate;
    enum
    {
        UNKNOWN = 'X',
        MALE = 'M',
        FEMALE = 'F'
    } gender;
    struct
    {
        int zipcode;
        char city[100];
    } address;
};

struct Person inputPerson( int i );
void printPerson( struct Person );


int main( void )
{
    struct Person p[64];
    int number = 0;
    printf("Enter the Number of persons : ");
    (void) scanf("%d", &number);
    getchar(); //clear the buffer
    for( int i = 1; i <= number; i++ )
    {
        p[i] = inputPerson(i);
    }
    for( int i = 1; i <= number; i++ )
    {
        printPerson( p[i] );
    }
    return 0;
}

struct Person inputPerson( int i )
{
    struct Person p;
    printf( "Enter the Name of person %d : ", i );
    (void) fgets( p.name, sizeof(p.name), stdin );
    printf( "Enter the Day of Birth of person %d : ", i );
    uint8_t day;
    (void) scanf( "%hhu", &day );
    p.birthdate.day = day;
    printf( "Enter the Month of Birth of person %d : ", i );
    uint8_t month;
    (void) scanf( "%hhu", &month );
    p.birthdate.month = month;
    printf( "Enter the Year of Birth of person %d : ", i );
    uint16_t year;
    (void) scanf( "%hu", &year );
    p.birthdate.year = year;
    p.age = 2023 - year;
    getchar(); //clear the buffer
    printf( "Enter the Gender of person %d : ", i );
    char gender;
    (void) scanf( "%c", &gender );
    gender = toupper( gender );
    p.gender = gender == MALE ? MALE : gender == FEMALE ? FEMALE : UNKNOWN;
    getchar(); //clear the buffer
    printf( "Enter the Zip Code of person %d : ", i );
    (void) scanf( "%d", &p.address.zipcode );
    getchar(); //clear the buffer
    printf( "Enter the City of person %d : ", i );
    (void) fgets( p.address.city, sizeof(p.address.city), stdin );
    return p;
}

void printPerson( struct Person Person )
{
    printf( "Name : %s", Person.name );
    printf( "DOB : %d/%d/%d (%d year)\n", Person.birthdate.day, Person.birthdate.month, Person.birthdate.year, Person.age );
    printf( "Gender : %c\n", Person.gender );
    printf( "City : %d %s", Person.address.zipcode, Person.address.city );
}
