/*
  Maak een HTTP response status codes lookup programma m.b.v. een switch statement.
    Print voor 200 "OK"
    Print voor 304 "Not Modified"
    Print voor 401 "Unauthorized"
    Print voor 404 "Page not found"
    Print voor 500 "Internal Server Error"
    Print voor 503 "Service Unavailable"
    Print voor 504 "Gateway Timeout"
    Print in voor alle andere gevallen "Goto https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/" + status code
*/

#include <stdio.h>

int main( void )
{
    int code;
    printf( "Geef een HTTP response status codes in : " );
    (void)scanf( "%d", &code );
    //--
    switch(code){
        case 200:
            printf("OK");
            break;

        case 304:
            printf("Not Modified");
            break;

        case 401:
            printf("Unauthorized");
            break;

        case 404:
            printf("Page not found");
            break;

        case 500:
            printf("Internal Server Error");
            break;

        case 503:
            printf("Service Unavailable");
            break;

        case 504:
            printf("Gateway Timeout");
            break;

        default:
            printf("Goto https://developer.mozilla.org/en-US/docs/Web/HTTP/Status/%d",code );
            break;
    }
    //--

    return 0;
}
