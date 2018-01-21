#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Wrong command format\n");
        exit(0);
    }

    char seperator;

    if(!strcmp(argv[1],"-s")){
        seperator = ' ';
    }else if(!strcmp(argv[1],"-c"))
        seperator = ',';

        srand((unsigned)time(NULL));

    for(int i = 0 ; i < atoi(argv[2])-1 ; i++){
            printf("%d%c", rand()%1000, seperator);
    }

    printf("%d", rand()%1000);
}
