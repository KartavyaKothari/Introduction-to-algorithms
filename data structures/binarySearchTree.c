#include<stdio.h>
#include<stdlib.h>
//Binary search Tree
//Complexities:
//Insertion =>
//Deletion =>
//Searching => O(n)

typedef struct{
    int ele;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;

NODE *createNewNode(int ele);

void insertNode(int ele){
    NODE *newNode = createNewNode(ele);
    
    if(root == NULL){
        printf("Tree empty!\n");
        return NULL;
    }
    
    NODE *node = root;

    while(1){
        if(node -> ele < ele){
            if(node -> right == NULL){
                node->right = newNode;
                return;
            }else node = node -> right;
        }else if(node -> left == NULL){
            node -> left = newNode;
            return;
        }else node = node -> left;
    }
}

// void deleteNode(int ele){
//     if(root == NULL){
//         printf("Tree empty!\n");
//         return NULL;
//     }

//     NODE *node = root;

//     while(node!=NULL){
//         if(node -> ele == ele){
//             if(node->left==NULL&&node->right==NULL)
//         }
//     }
// }

NODE *searchTree(int ele){
    if(root == NULL){
        printf("Tree empty!\n");
        return NULL;
    }

    NODE *node = root;

    if(node->ele == ele){
        return node;
    }else if(node->ele < ele){
        return searchTree(node = node->right);
    }else return searchTree(node = node->left);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}

NODE *createNewNode(int ele){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node -> ele = ele;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}