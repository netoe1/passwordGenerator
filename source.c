#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>


#define __SZPASS 10
char buf01[__SZPASS];
const char *__DATALL =
{"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890!@#$%¨&*()"};

void generateFile();

int main(){
	srand(time(NULL));
	
	
	int i;
	
	for(i = 0;i < sizeof(__DATALL);i++){
		buf01[i] = __DATALL[rand() % sizeof(__DATALL) - 1];
	}	
	generateFile();
}

void generateFile(){
	FILE *file;
	file = fopen("password.txt","w");
	fprintf(file,"%s",buf01);
	fclose(file);
}