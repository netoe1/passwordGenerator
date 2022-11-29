#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define MAX 255
#define MIN 33
#define LEN 10

void generateFile(const char *buf);
int main()
{
	
	static char buf[LEN];
    setlocale(LC_ALL,"");
    srand(time(NULL));

    int i;
    int randal;

    for(i = 0; i < LEN;i++)
    {
        do
        {
           randal = rand() % MAX;
        }
        while(randal < MIN);

       	buf[i] = randal;
    }
	
	generateFile(buf);
	
    return 0;
}

void generateFile(const char *buf)
{
	FILE *file;
	
	file = fopen("password.txt","w");
	
	fprintf(file,"%s",buf);
	fclose(file);
}