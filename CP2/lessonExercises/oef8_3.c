#include <stdio.h>
#include <stdbool.h>
#include <conio.h>

struct led {
    bool r, g, b;
};

void toggleLEDColor(struct led *led, bool r, bool g, bool b) {
    led->r = r;
    led->g = g;
    led->b = b;
}

void printLEDColor(struct led led) {
    if (led.r == true)
        printf("\x1b[48;5;196m ");  // Rood
    else if (led.g == true)
        printf("\x1b[48;5;46m  ");  // Groen
    else if (led.b == true)
        printf("\x1b[48;5;21m  ");  // Blauw
    else
        printf("\x1b[48;5;0m  ");   // Zwart

    printf("\n");  // Nieuwe regel toevoegen
}


int main() {
    struct led myLED = { false, false, false };

    char key;
    bool isRunning = true;

    while (isRunning) {
        if (kbhit()) {
            key = getch();
            switch (key) {
                case 'R':
                case 'r':
                    toggleLEDColor(&myLED, true, false, false);
                    break;
                case 'G':
                case 'g':
                    toggleLEDColor(&myLED, false, true, false);
                    break;
                case 'B':
                case 'b':
                    toggleLEDColor(&myLED, false, false, true);
                    break;
                case 'Q':
                case 'q':
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }

        printLEDColor(myLED);
    }

    return 0;
}
