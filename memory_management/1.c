#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char name[100];
    char *description;

    strcpy(name, "Zara Ali");

    description = malloc(200 * sizeof(char));

    if(description == NULL){
        fprintf(stderr, "Error - unable to allocate required memory\n");
    }else{
        strcpy(description, "Zara ali a DPS student in class 10th");
    }

    printf("Name = %s\n", name);
    printf("description: %s\n", description);

}