#include<stdio.h>

#define SIZE 100

int stack[SIZE];
int stackTop = -1;

void push(int ele){
    if(stackTop == SIZE -1){
        printf("Stack overflow\n");
        return;
    }
    stack[++stackTop] = ele;
}

void pop(){
    if(stackTop==-1){
        printf("Stack Empty\n");
        return;
    }
    printf("%d\n", stack[stackTop--]);
    // return stack[stackTop--];
}

void displayStack(){
    for(int i = 0 ; i <= stackTop ; i++){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    int res;
    int ele;
    int isTrue = 1;

    while(isTrue){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Stop\n");

        scanf("%d",&res);

        switch(res){
            case 1:
                printf("Enter element: ");
                scanf("%d",&ele);    
                push(ele);
                break;
            case 2: 
                pop();
                break;
            case 3:
                displayStack();
                break;
            case 4:
                isTrue=0;
                break;    
        }
    }
    return 0;
}
