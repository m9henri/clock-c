#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char choose_mode(void);
void timer_options();

int main(void)
{
    switch (choose_mode())
    {
        case 't':
            timer_options();
            break;
        case 's':
            break;
    }
}

char choose_mode()
{
    char mode;

    printf("What mode do you want to choose?\n");
    printf(" - Timer (t)\n");
    printf(" - Stopwatch (s) (doesnt work)\n> ");

    scanf(" %c", &mode);

    return mode;
}

void stopwatch()
{

}

void timer(unsigned int ms)
{
    printf("%u", ms);
}

void timer_options()
{
    char unit;
    unsigned short input; // memory management 🤑
    unsigned int timems = 0;
    char inputchar;
    char whilebuffer = 'a';

    system("clear");
    while('a' == whilebuffer)
    {
        printf("What unit of time do you choose? (s,m,h)\n");
        scanf(" %c", &unit);
        printf("How much of these units do you want to add? ");
        scanf("%hu", &input);

        // calculating time to wait
        if('s' == unit) { timems += (input * 1000); }
        if('m' == unit) { timems += (input * 60000); }
        if('h' == unit) { timems += (input * 3600000); }

        printf("Do you want to add another unit? (y/n) ");
        scanf(" %c", &inputchar);

        if('n' == inputchar) { whilebuffer = 'b'; }
    }

    // Continue to timer after while loop has been broken
    timer(timems);
}
