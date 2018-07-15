#include<stdio.h>

#define SIZE 2

//There is a tradeoff in queue. 
//We can either keep only n-1 elements in array of n
//Or if we want all n elements then we need to keep a counter for number of elements in the queue
//This is because of detection of underflow or overflow events
//For our case:
//Underflow => rear == front
//Overflow => (rear+1)%SIZE == front

int queue[SIZE];
int front = 0, rear = 0;

int acceptInteger(char *name);
void displayQueue(){
    if(rear==front){
        printf("Queue empty!\n");
        return;
    }
    
    int i = front;

    while(i!=rear){
        printf("%d ",queue[i]);
        i=(i+1)%SIZE;
    }
    // for(int i = front ; (i%SIZE) < rear ; i=(i+1)%SIZE){
    //     printf("%d ",queue[i]);
    // }
    putchar('\n');
}

void enQueue(int ele){
    if((rear+1)%SIZE == front){
        printf("Queue Overflow!\n");
        return;
    }

    queue[rear] = ele;
    rear = (rear+1)%SIZE;

    displayQueue();
}

void deQueue(){
    if(rear==front){
        printf("Queue empty!\n");
        return;
    }

    int temp = queue[front];
    front = (front + 1)%SIZE;
    printf("%d\n",temp);
    displayQueue();
}

int main(int argc, char const *argv[])
{
    int res;
    int ele;
    int isTrue = 1;

    while(isTrue){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Stop\n");

        scanf("%d",&res);

        switch(res){
            case 1: 
                enQueue(acceptInteger("Element"));
                break;
            case 2: 
                deQueue();
                break;
            case 3:
                displayQueue();
                break;
            case 4:
                isTrue=0;
                break;    
        }
    }
    return 0;
}

int acceptInteger(char *name){
    int ele;
    
    printf("Enter %s: ",name);
    scanf("%d",&ele);

    return ele;
}