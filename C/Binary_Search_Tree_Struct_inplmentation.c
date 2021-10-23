#include <stdio.h>
#include <stdlib.h>

/*The structure for the Node of a BST*/
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};

/*Define a custom datatype of type struct BST */
typedef struct BST NODE;
NODE *node;

/*Add a node to the tree*/
NODE* newNode(int item)
{
    NODE *temp = (NODE *)malloc(sizeof(NODE));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
NODE* insert(NODE *node, int data)
{

    if (node == NULL)
        return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data >= node->data)
        node->right = insert (node->right, data);
    return node;
}


int getLevelUtil(NODE *node,
                 int data, int level)
{
    if (node == NULL)
        return 0;

    if (node->data == data)
        return level;

    int downlevel = getLevelUtil(node->left,
                                 data, level+1);
    if (downlevel != 0)
        return downlevel;

    downlevel = getLevelUtil(node->right,
                             data, level+1);
    return downlevel;
}

/* Returns level of given data value */
int getLevel(struct node *node, int data)
{
    return getLevelUtil(node,data,1);
}


/*Search for a node in the BST*/
NODE* search(NODE* node,int data)
{
    if(node==NULL)
    {
        printf("\n The end of the BST has been reached \n");
    }
    else if(data<(node->data))
    {
        node->left=search(node->left,data);

    }
    else if(data>(node->data))
    {
        node->right=search(node->right ,data);

    }
    else
    {
        printf("\n Element %d is found \n",node->data);
        int level=getLevel(node,data);
        printf("\n the level of the element is %d \n",getLevelUtil(node,data,level));
        if(node->left!=NULL)
            node->left=search(node->left,data);
        if(node->right!==NULL)
            node->right=search(node->right ,data);
        return node;
    }
}

/*For traversal of the BST*/
void inorder(NODE *node)
{
    if(node!=NULL)
    {
        inorder(node->left);
        printf("%d \t",node->data);
        inorder(node->right);
    }
}

void preorder(NODE *node)
{

    if(node != NULL)
    {
        printf("%d\t", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(NODE *node)
{

    if(node != NULL)
    {
        postorder(node->left);
        postorder(node->right);
        printf("%d\t", node->data);
    }
}
NODE* findMin(NODE *node)

{

    if(node==NULL)
    {
        return NULL;
    }

    if(node->left)

        return findMin(node->left);

    else

        return node;
}

NODE* del(NODE *node, int data)
{

    NODE *temp;

    if(node == NULL)
    {
        printf("\nElement not found \n");
    }

    else if(data < node->data)
    {
        node->left = del(node->left, data);
    }

    else if(data > node->data)

    {
        node->right = del(node->right, data);
    }
    /* Here we will replace with minimum element in the right sub tree */

    else
    {
        if(node->right && node->left)
        {
            temp = findMin(node->right);

            node -> data = temp->data;

            node -> right = del(node->right,temp->data);
        }
        else
        {
            temp = node;
            if(node->left == NULL)
                node = node->right;
            else if(node->right == NULL)
                node = node->left;

            free(temp);
        }
    }

    return node;
}

void main()
{

    int data, choice;
    NODE *root=NULL;
    int flag=1;
    while (flag==1)
    {

    printf("\n1.Insertion in Binary Search Tree");
    printf("\n2.Search Element in Binary Search Tree");
    printf("\n3.Delete Element in Binary Search Tree");
    printf("\n4.Display the BST");
    printf("\n5.Exit\n");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:

            printf("\nEnter the value\n");
            scanf("%d", &data);
            root=insert(root, data);
            break;


        case 2:
            if(root==NULL)
            {
                printf("The BST is not yet initalized or is empty ");
                break;
            }
            else
                {
                printf("\nEnter the element to search: ");
                scanf("%d", &data);
                root=search(root, data);
                break;
                }
        case 3:
            if(root==NULL)
                {
                printf("The BST is not yet initalized or is empty ");
                break;
                }
            else
                {
                printf("\nEnter the element to delete: ");
                scanf("%d", &data);
                root=del(root, data);
                break;
                }

        case 4:
            if(root==NULL)
            {
                printf("The BST is not yet initalized or is empty ");
                break;
            }
            else
                {
                printf("\nInorder Traversal: \n");
                inorder(root);
                printf("\nPreorder Traversal: \n");
                preorder(root);
                printf("\nPostorder Traversal: \n");
                postorder(root);
                break;
                }

        case 5:
            exit(0);

        default:
            printf("\nWrong option \n");
            break;

        }

    }

}
