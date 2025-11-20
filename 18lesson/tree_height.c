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
Data tree_max_height(struct Node * tree, Data max_height, Data counter);

int main()
{
    struct Node * tree = NULL;
    Data* test = malloc(N*sizeof(Data));
    size_t size_of_test = N*sizeof(Data); 

    test[0] = 1; //чтобы не ноль точно

    for(int i = 0; ; i++)
    {
        if((int)(size_of_test/sizeof(Data)) - i <= 1)
        {
            size_of_test += N;
            test = realloc(test, size_of_test);
        }

        scanf("%d", &test[i]);

        if(!test[i])
        {
            break;
        }
    }

    for(int i = 0; test[i] != 0; i++)
    {
        tree = tree_add(tree, test[i]);
    }

    tree_print(tree);
    printf("\n");

    int height_counter = 0;
    int max_height = 0;

    printf("%d\n", tree_max_height(tree, max_height, height_counter));

    tree = tree_destroy(tree);
    free(test);
       
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

Data tree_max_height(struct Node * tree, Data max_height, Data counter)
{
    if(tree == NULL)
    {
        return 0;
    }

    if(tree->left)
    {
        max_height = tree_max_height(tree->left, max_height, counter + 1);
    }

    if(tree->right)
    {
        max_height = tree_max_height(tree->right, max_height, counter + 1);
    } 

    if(!tree->left && !tree->right)
    {
        counter++;
        if(counter > max_height)
        {
            max_height = counter;   
        }  
    }
    
    return max_height;
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