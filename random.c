#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[]){
    if(argc<2){
        printf("Wrong command format\n");
        exit(0);
    }

    char seperator;

    if(argv[1]=='-s'){
        seperator = ' ';
    }else if(argv[1]=='-c')
        seperator = ',';

    for(int i = 0 ; i < argv[2] ; i++){

    }
}
