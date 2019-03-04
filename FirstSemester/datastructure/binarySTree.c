#include <stdio.h>
#include <stdlib.h>

typedef struct BST
{
    int data;
    struct BST *left, *right;
} node;

node *root;

node *get_node(int);
node* insert(node *, int);
void inorder(node *);
void preorder(node *);
void postorder(node *);
void levelorder(node *);


void main()
{
    int choice;
    int key,val;
    node* root = NULL;
    printf("\nProgram For Binary Search Tree ");
    printf("Enter root value \n");
    scanf("%d",&val);
    root = insert(root,val);
    printf("\nRoot element is %d : ",root->data);
      
    while(1)
    {
        printf("\n1.Create");
        printf("\n2. Traverse in Inorder");
        printf("\n3. Traverse in Preorder");
        printf("\n4. Traverse in Postorder");
        printf("\n5-Traverse in level\n");
        printf("\n6. Exit\n");
        printf("\nEnter your choice :");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter elements \n");
            scanf("%d",&val);
            insert(root,val);                      
            break;

        case 2:
            printf("\nBST Traversal in INORDER \n");
            inorder(root);
            break;
        case 3:
            printf("\nBST Traversal in PREORDER \n");
            preorder(root);
            break;
        case 4:
            printf("\nBST Traversal in POSTORDER \n");
            postorder(root);
            break;
        case 5:
            printf("\n%d ", root->data);
            levelorder(root);
            break;
        case 6:
            exit (0);
           
        }
    } 
}

node *get_node(int data)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp ->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node*  insert(node *root, int data)
{
    if (root == NULL){
        root = get_node(data);
    }

    else if(data < root->data){
        root->left = insert(root->left,data);
    }
    else{
        root->right = insert(root->right,data);
    }
}

void levelorder(node *temp)
{
    if (temp == NULL)
        return;
    /* display node data */
    // printf("%d", temp->data);
    if (temp->left != NULL)
            printf(" %d ", temp->left->data);
    if (temp->right != NULL)
        printf(" %d ", temp->right->data);
    

    levelorder(temp->left);
    levelorder(temp->right);
}

void inorder(node *temp)
{
    if (temp != NULL)
    {
        inorder(temp->left);
        printf(" %d --->", temp->data);
        inorder(temp->right);
    }
}

void preorder(node *temp)
{

    if (temp != NULL)
    {
        printf(" %d --->", temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(node *temp)
{
    if (temp != NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf(" %d --->", temp->data);
    }
}

