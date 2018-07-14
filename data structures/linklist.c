#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int ele;
    LIST *next;
} LIST;

LIST *start = NULL;

LIST *createNode(int ele);

void append(int ele){
    LIST *newNode = createNode(ele);
    
    if(start == NULL){
        start = newNode;
        return;
    }

    LIST *node = start;

    while(node->next != NULL){
        node=node->next;
    }

    node->next = newNode;
}

void remove(int ele){
    if(start == NULL){
        printf("LL Empty\n");
        return;
    }

    LIST *node = start;

    if(node->ele == ele){
        start = start -> next;
        return;
    }

    LIST *temp;

    while(node != NULL){
        if(node->next->ele == ele){
            printf("%d removed!\n",node->next->ele);
            temp = node->next->next;
            node->next = temp;
            return;
        }
        node = node -> next;
    }

    printf("Value to be deleted DNE in List\n");
    return;
}

void displayList(){
    LIST *node = start;

    while(node!=NULL){
        printf("%d ",node->ele);
        node = node -> next;
    }

    printf("\n");
}

void insertAt(int ele, int index){
    LIST *newNode = createNode(ele);
    
    if(start == NULL){
        printf("LL empty\n");
        return;
    }

    int currIndex = -1;

    LIST *node = start;
    LIST *temp;

    while(node -> next != NULL){
        if(++currIndex==index){
            temp = node->next;
            node -> next = newNode;
            newNode -> next = temp;
            return;
        }
    }
    printf("List does not contain the index!\n");
    return;
}

int main(int argc, char const *argv[])
{
    int res;
    int ele;
    int isTrue = 1;

    while(isTrue){
        printf("1. Insert\n");
        printf("2. Remove element\n");
        printf("3. Insert AT\n");
        printf("4. Display\n");
        printf("5. Stop\n");

        scanf("%d",&res);

        switch(res){
            case 1:
                append(acceptInteger("Element"));
                break;
            case 2: 
                remove(acceptInteger("Element"));
                break;
            case 3:
                insertAt(acceptInteger("Element"),acceptInteger("Index"));
                break;
            case 4:
                displayStack();
                break;
            case 5:
                isTrue=0;
                break;    
        }
    }
    return 0;
}

LIST *createNode(int ele){
    LIST *node = (LIST*)malloc(sizeof(LIST));
    node -> ele = ele;
    node -> next = NULL;
}

int acceptInteger(char *name){
    int ele;
    
    printf("Enter %s: ",name);
    scanf("%d",&ele);

    return ele;
}