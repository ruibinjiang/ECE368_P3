#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
    char*infile = argv[1];
    int vCount;
    int eCount;
    int a;
    int b;

    FILE * fptr = fopen(infile, "r");
    fscanf(fptr, "%d", &vCount);
    fscanf(fptr, "%d", &eCount);

    int vertices[vCount];
    int temp = 0;
    char dump[1000];
    int i;
    for (i = 0; i < vCount; i++){
        fscanf(fptr, "%d", &temp);
        vertices[i] = temp;
        
        fgets(dump, 1000, fptr);
    }

    for(i = 0; i < vCount; i++){
        printf("%d:",vertices[i]);
        int j;
        rewind(fptr);
        for (j = 0; j < vCount + 1; j++){
            fgets(dump, 1000, fptr);
        }
        for (j = 0; j < eCount; j ++){
            fscanf(fptr, "%d", &a);
            fscanf(fptr, "%d", &b);
            if(a==vertices[i]){
                printf(" %d",b);
            }
            else if(b==vertices[i]){
                printf(" %d",a);
            }
        }
        printf("\n");
    }
}

