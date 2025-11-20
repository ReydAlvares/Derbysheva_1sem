#include <stdio.h>

struct Human
{
    int shift;
    int mask;
    char* words[4];
};

int main()
{
    struct Human personality[] = {{0, 1, {"fe", "ma"}},
                                  {1, 1, {"du", "cl"}},
                                  {2, 1, {"nh", "ha"}},
                                  {3, 1, {"sk", "tr"}},
                                  {4, 3, {"bn", "rd", "bw", "bk"}},
                                  {6, 3, {"bu", "ge", "gy", "da"}} 
                                 };
    unsigned x;
    scanf("%x", &x);
    
    for(int i = 0; i < 6; i++)
    {
        printf("%s ", personality[i].words[(x >> personality[i].shift) & personality[i].mask]);
    }
    printf("\n");
    
    return 0;
}

