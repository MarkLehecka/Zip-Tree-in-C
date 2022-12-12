#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{

    int item;
    int key;
    int rank;
    struct node *left;
    struct node *right;
} Node;

int randomRank()
{

    int count = 0;
    int coin = 0;

    while (coin != 1)
    {
        coin = rand() / (RAND_MAX / 3);
        count++;
    }

    return count;
}

Node *createNode(int x, int y)
{

    Node *xNode = malloc(sizeof(*xNode));
    xNode->key = x;
    xNode->item = y;
    xNode->rank = randomRank();
    xNode->right = NULL;
    xNode->left = NULL;

    return xNode;
}

Node *insert(Node *x, Node *root)
{

    if (root == NULL)
    {

        return x;
    }

    if (x->key < root->key)
    {

        if (insert(x, root->left) == x)
        {
            if (x->rank < root->rank)
            {
                root->left = x;
            }
            else
            {
                root->left = x->right;
                x->right = root;
                return x;
            }
        }
    }
    else
    {

        if (insert(x, root->right) == x)
        {
            if (x->rank <= root->rank)
            {
                root->right = x;
            }
            else
            {
                root->right = x->left;
                x->left = root;
                return x;
            }
        }
    }
    return root;
}

Node *zip(Node *x, Node *y)
{

    if (x == NULL)
    {
        return y;
    }

    if (y == NULL)
    {
        return x;
    }

    if (x->rank < y->rank)
    {
        y->left = zip(x, y->left);
        return y;
    }
    else
    {
        x->right = zip(x->right, y);
        return x;
    }
}

Node *delete(Node *x, Node *root)
{

    if (x->key == root->key)
    {
        return zip(root->left, root->right);
    }

    if (x->key < root->key)
    {

        if (x->key == root->left->key)
        {

            root->left = zip(root->left->left, root->left->right);
        }
        else
        {
            delete (x, root->left);
        }
    }
    else
    {

        if (x->key == root->right->key)
        {

            root->right = zip(root->right->left, root->right->right);
        }
        else
        {
            delete (x, root->right);
        }
    }

    return root;
}

void search(int x, Node *root)
{

    if (root == NULL)
    {
        return;
    }

    if (x == root->key)
    {
        printf("Node Found\n");
        printf("Item at Node: %d\n", root->item);
    }

    search(x, root->left);
    search(x, root->right);
}

void inorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    inorderTraversal(root->left);
    printf(" %d  |  %d \n", root->key, root->rank);
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf(" %d  |  %d \n", root->key, root->rank);
}

void preorderTraversal(Node *root)
{

    if (root == NULL)
    {
        return;
    }

    printf(" %d  |  %d \n", root->key, root->rank);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void freeTree(Node *node)
{

    if (node == NULL)
    {
        return;
    }

    freeTree(node->left);
    freeTree(node->right);

    free(node);
}

int main(void)
{

    srand(time(0));

    Node *root = createNode(0, 200);
    Node *newNode = NULL;

    for (int i = 1; i < 10; i++)
    {
        newNode = createNode(i, (i * randomRank()));
        root = insert(newNode, root);
    }

    printf("Pre-order Traversal\n");
    printf("Key | Rank\n");
    preorderTraversal(root);

    printf("In-order Traversal\n");
    printf("Key | Rank\n");
    inorderTraversal(root);

    printf("Post-order Traversal\n");
    printf("Key | Rank\n");
    postorderTraversal(root);

    search(0, root);

    freeTree(root);

    return 0;
}
