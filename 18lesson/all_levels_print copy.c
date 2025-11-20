#include <stdio.h>
#include <stdlib.h>
#define N 10

typedef int Data;

struct Node
{
    Data val;
    struct Node* left;
    struct Node* right;
};

void tree_print(struct Node * tree);
struct Node * tree_destroy(struct Node * tree);
struct Node * tree_add(struct Node * tree, Data val);
Data tree_max_height(struct Node * tree);
int max(Data x1, Data x2);
void level_print(struct Node * tree, int counter, int level)
{
    if(!tree)
    {
        return;
    }

    if(counter != level)
    {
        level_print(tree->left, counter + 1, level);
        level_print(tree->right, counter + 1, level);
    }

    if(counter == level)
    {
        printf("%d ", tree->val);
    }

    return;
}

int main()
{
    struct Node * tree = NULL;

    int data = 0;

    while(1)
    {
        scanf("%d", &data);
        if(!data)
        {
            break;
        }

        tree = tree_add(tree, data);
    }

    int level = tree_max_height(tree);

    tree_print(tree);
    printf("\n");
    printf("%d\n", level);
    for(int i = 0; i <= level; i++)
    {
        int counter = 0;
        level_print(tree, counter, i);
    }
    printf("\n");

    tree = tree_destroy(tree);
       
    return 0;
}


struct Node * tree_add(struct Node * tree, Data x)
{
    if(tree == NULL)
    {
        struct Node* p = malloc(sizeof(struct Node));
        p->val = x;
        p->left = p->right = NULL;

        return p;
    }

    if(tree->val > x)
    {
        tree->left = tree_add(tree->left, x);
    }

    if(tree->val < x)
    {
        tree->right = tree_add(tree->right, x);
    }

    return tree;
}

struct Node * tree_destroy(struct Node * tree)
{
    if(tree == NULL)
    {
        return NULL;
    }

    tree_destroy(tree->left);
    tree_destroy(tree->right);
    free(tree);

    return NULL;
}


void tree_print(struct Node * tree)
{
    if(tree == NULL)
    {
        return;
    }

    tree_print(tree->left);
    printf("%d ", tree->val);
    tree_print(tree->right);
}

int max(Data x1, Data x2)
{
    return x1 > x2 ? x1 : x2;
}

Data tree_max_height(struct Node * tree)
{
    if(tree == NULL)
    {
        return 0;
    }

    int left  = tree_max_height(tree->left);
    int right = tree_max_height(tree->right);

    return max(left, right) + 1;
}