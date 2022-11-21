#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 255
#define MIN 33
#define LEN 10

int main()
{
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int i;
    int randal;
    printf("\nPassword:");

    for(i = 0; i < LEN;i++)
    {
        do
        {
           randal = rand() % MAX;
        }
        while(randal < MIN);

        printf("%c",randal);
    }
    return 0;
}