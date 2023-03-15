#include <stdio.h>

enum schooljaar
{
    eerste_jaar=1,
    tweede_jaar=2,
    derde_jaar=3,
    geindividualiseerd=4
};

struct student
{
    int nummer;
    char richting[10];
    enum schooljaar jaar;
    char academieJaar[10];
};

int main()
{
    struct student joske_vermeulen;
    printf("Wat is uw studenten-nummer?\n");
    (void)scanf("%d",joske_vermeulen.nummer);

    printf("In welk jaar zit u?\n");
    (void)scanf("%d",joske_vermeulen.jaar);

    while (getchar()!='\n');

    printf("Welke richting doet u?\n");
    fgets(joske_vermeulen.richting, 10, stdin);

    printf("Welk school jaar is het?\n");
    fgets(joske_vermeulen.academieJaar,10,stdin);
}
