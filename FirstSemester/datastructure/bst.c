#include <stdio.h>
#include <stdlib.h>
struct node *q[20];
int count = 0, f = 0, r = -1;
struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *createnode(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node *insert(struct node *root, int data)
{
    count++;
    if (root == NULL)
        return createnode(data);
    else if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
}

void inorder(struct node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(struct node *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t", root->data);
}

void levelorder(struct node *root)
{
    struct node *temp = root;
    if (!temp)
    {
        printf("Empty\n");
        return;
    }
    q[++r] = temp;
    while (r < count)
    {
        if (q[f])
        {
            temp = q[f++];
            printf("%d\t", temp->data);
            printf("\n");
            if (temp->left)
                q[++r] = temp->left;
            if (temp->right)
                q[++r] = temp->right;
        }
        else
            break;
    }
}
void main()
{
    int ch, val;
    struct node *root = NULL;
    printf("Enter the value\n");
    scanf("%d", &val);
    root = insert(root, val);
    printf("Root is %d\n", root->data);
    do
    {
        printf("\n1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Level Order\n6.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter value\n");
            scanf("%d", &val);
            insert(root, val);
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            preorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            levelorder(root);
            break;
        default:
            exit(0);
        }
    } while (1);
}
