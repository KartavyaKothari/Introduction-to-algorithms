#include<stdio.h>
#include<stdlib.h>
//Binary search Tree
//Complexities:
//Insertion =>
//Deletion =>
//Searching => O(n)

typedef struct node{
    int ele;
    struct node *left;
    struct node *right;
}NODE;

NODE *root = NULL;

NODE *createNewNode(int ele);
int acceptInteger(char *name);

NODE *getParent(NODE *child);
NODE *findSuccessor(NODE *node);
NODE *findPredecessor(NODE *node);
NODE *getMinimum();
NODE *getMaximum();
void preOrder(NODE *node);
void postOrder(NODE *node);
void inOrder(NODE *node);
void insertNode(int ele);
void deleteNode(int ele);
NODE *searchTree(int ele);

int main(int argc, char const *argv[])
{
    int res;
    printf("\n");
    return 0;
}

NODE *createNewNode(int ele){
    NODE *node = (NODE*)malloc(sizeof(NODE));
    node -> ele = ele;
    node -> left = NULL;
    node -> right = NULL;

    return node;
}

int acceptInteger(char *name){
    int ele;
    
    printf("Enter %s: ",name);
    scanf("%d",&ele);

    return ele;
}

NODE *getParent(NODE *child){
    if(child==root){
        printf("Parent DNE!\n");
        return NULL;
    }

    NODE *node = root;

    while(node!=NULL){
        if(node -> left -> ele == child -> ele || node -> right -> ele == child -> ele)
            return node;

        if(node -> ele <= child -> ele){ 
            if(node -> left != NULL) node = node -> left;
            else {printf("Child itself DNE!\n");return NULL;}
        }else{
            if(node -> right != NULL) node = node -> right;
            else {printf("Child itself DNE!\n");return NULL;}
        }
    }
    
    printf("Child itself DNE!\n");
    return NULL;
}

NODE *findSuccessor(NODE *node){
    //Left most node of right subtree
    if(node -> right != NULL){
        return getMinimum(node -> right);
    }else{
        NODE *parent = getParent(node);
        if(parent != NULL && parent -> left == node){
            return parent;
        }else{
            printf("No successor exists!\n");
            return NULL;
        }
    }
}

NODE *findPredecessor(NODE *node){
    //Left most node of right subtree
    if(node -> left != NULL){
        return getMaximum(node -> left);
    }else{
        NODE *parent = getParent(node);
        if(parent != NULL && parent -> right == node){
            return parent;
        }else{
            printf("No predecessor exists!\n");
            return NULL;
        }
    }
}

NODE *getMinimum(){
    NODE *node = root;
    if(node == NULL){
        printf("Tree Empty!\n");
        return NULL;
    }

    while(node -> left != NULL){
        node = node -> left;
    }

    return node;
}

NODE *getMaximum(){
    NODE *node = root;
    if(node == NULL){
        printf("Tree Empty!\n");
        return NULL;
    }

    while(node -> right != NULL){
        node = node -> right;
    }

    return node;
}

void preOrder(NODE *node){
    if(node != NULL){
        printf("%d ",node -> ele);
        preOrder(node->left);
        preOrder(node->right);
    }
}

void postOrder(NODE *node){
    if(node != NULL){
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ",node -> ele);
    }
}

void inOrder(NODE *node){
    if(node != NULL){
        inOrder(node->left);
        printf("%d ",node -> ele);
        inOrder(node->right);
    }
}

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

void deleteNode(int ele){
    NODE *node = searchTree(ele);
    if(node == NULL){
        printf("Element to be deleted DNE!\n");
        return;
    }

    NODE *parent = getParent(node);

    //Case 1: Leaf node
    if(node -> left == NULL && node ->right == NULL){
        if(node -> ele <= parent -> ele){
            parent -> left = NULL;  //Left child   
        }else {
            parent -> right = NULL; //Right child
        }
        return;
    }

    //Case 2: Having one child
    NODE *temp = NULL;

    if(node -> left == NULL){
        temp = node -> right;
    }else if(node -> right == NULL){
        temp = node -> left;
    }

    //Case 3: Having both children (Thats why china has one child poilicy)
    if(node -> left != NULL && node -> right != NULL){
        NODE *predecessor = findPredecessor(node);
        deleteNode(predecessor);
        node -> ele = predecessor -> ele;
        return;
    }

    printf("Something went wrong!\n");
    return;
}

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