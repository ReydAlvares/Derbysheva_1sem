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
Data tree_balanced(struct Node * tree, Data * height);
int max(Data x1, Data x2);

int main()
{
    struct Node * tree = NULL;
    Data data;

    for(int i = 0; ; i++)
    {
        scanf("%d", &data);

        if(data == 0)
            break;
        tree = tree_add(tree, data);
    }

    tree_print(tree);
    printf("\n");

    int height_counter = 0;

    printf("%s\n", tree_balanced(tree, &height_counter) ? "YES" : "NO");

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

int max(Data x1, Data x2)
{
    return x1 > x2 ? x1 : x2;
}

Data tree_balanced(struct Node * tree, Data * height)
{
    /* return 1 - balanced, 0 - not balanced
    *height - высота поддерева, от текущего узла и ниже
    */
    if(tree == NULL)
    {
        *height = 0;
        return 1;
    }
    int left_height, right_height;

    int left_balanced = tree_balanced(tree->left, &left_height);
    int right_balanced = tree_balanced(tree->right, &right_height);
    *height = max(left_height, right_height) + 1;

    int res = abs(left_height - right_height) < 2 && left_balanced && right_balanced;
    return res;
}

/*Data tree_balance(struct Node * tree, Data counter)
{
    Data max_left = 0;
    Data max_right = 0;

    counter++;

    if(tree == NULL)
    {
        return 0;
    }

    if(!tree->left && !tree->right)
    {
        return counter;
    }

    if(tree->left)
    {
        max_left = tree_balance(tree->left, counter);
    }

    if(tree->right)
    {
        max_right = tree_balance(tree->right, counter);
    }
    else
    {
        max_right = counter;
    }
    
    return max_right > max_left? max_right - max_left: max_left - max_right;
}*/

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