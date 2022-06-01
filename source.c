#include <stdio.h>
#include "newLibraryV1.h"
#include <time.h>
#include <stdlib.h>
#include <locale.h>

/*
This is an open-source file. 
You can modify whatever you want inside, just don't forget to reference the NEWCORP team.

Use GCC to compile the program. Ex: gcc -o 'name' source.c

If you don't have our C string library, you can download it from github from one of our members.
https://github.com/weealDCTEF/stringLibrary

The string library is not 100% necessary. If you want, modifying it your way to resolve string operations might be feasible.
This library is a "facilitator".

(If you take the library out of the source code, obviously, the algorithm will fail).

For now, the repository is private.
In the future, it may be released to the public.

Good luck with use. 
NEWCORP COPYRIGHT &2022
*/


/*

    The string in C, 'data allowed[]', is responsible for showing the characters available for creating the password.
    You can edit this vector if you want to add new characters and/or remove them.

*/    


char data_allowed[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYLabcdefghijklmnopqrstuvwxyz1234567890"};



int returnPassLength()
{
    /*
        This function, as it says in its name, is responsible for returning the length of the password 
        that the user wants.

        Later in the code, this value will be assigned to a variable that will start the auxiliary vector.
    */
    int x;

    printf("\nLength:");
    scanf("%d",&x);

    return x;
}

int createTxtFile(char array[],const int pass_length){

    /*
        Using the library we all love, stdlib.h, C's standard library, we will use the createFileTxt() function, fopen(), fprintf() and fclose() for the correct execution.
        These functions are responsible for creating files, in this case, the file will have the extension '.txt'
    */

    FILE *file;
    file = fopen("passwordGenerated.txt","w");
    if(file != NULL){
        fprintf(file,"%s","Generated Password:");
        for(int i = 0; i < pass_length;i++){
            fprintf(file,"%c",array[i]);
        }
        fprintf(file,"%c","\n");

        fclose(file);
        return 0;
    }

        /*
        Very important detail!

        If you are using OS Linux, on most distributions, file creation may be hampered, because of system security method.
        If this happens, run the program as sudo.
        Ex: sudo ./programName

        */

        fclose(file);
        printf("\nError to create file.If you're in a Linux PC, please run as sudo!");
        return -1;
    
   
}

void generatePassword(char array[],const int pass_length,const int array_length){
    srand(time(NULL));

    /*In this function, rand() generates a random number, which is limited by the size of data_allowed[].
    After this happens, the array_aux[] will have the length of the user's password and will be assigned the value resulting from the random number of the array.
    */
    for(int i = 0; i < pass_length;i++){
        int aux = rand() % (array_length- 1);
        array[i] = data_allowed[aux];
    }
    createTxtFile(array,pass_length);
}

int main(){
    setlocale(LC_ALL,""); // Enable special characters.*Some devices won't work! <locale.h>

    int pass_length = returnPassLength(); // The length of the password that will be defined by the user.
    const int array_length = returnSizeArray(data_allowed); // The constant that will store the size of the vector. The function used for this purpose was made in stringLibrary.h.
    char array_aux[pass_length]; // The auxiliary array that will be used to create the password file.

    generatePassword(array_aux,pass_length,array_length); 

    return 0;
}