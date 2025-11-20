#include <stdio.h>
#include <assert.h>

struct Card {
    char rank;    // достоинство
    char suit;    // масть
};

int check(struct Card * hand);
int main()
{
    struct Card hand1 [] = {{'Q', 's'}, {'A','h'}, {'9', 'd'}, {0, 0}};
    struct Card hand2 [] = {{'2', 's'}, {'A','h'}, {0, 0}};
    struct Card hand3 [] = {{'A', 's'}, {'T', 's'}, {'Q', 's'}, {0, 0}};
    assert(1 == check(hand1));
    assert(0 == check(hand2));
    assert(1 == check(hand3));

    return 0;
}

int check(struct Card * hand)
{
    for(int i = 0; hand[i].rank != 0; i++)
    {
        if(hand[i].rank == 'Q')
        {
            if(hand[i].suit == 's')
                return 1;
            continue;
        }
        continue;
    }

    return 0;
}