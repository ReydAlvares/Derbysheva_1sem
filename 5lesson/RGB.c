#include <stdio.h>

typedef struct
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Color;

Color getColor();
unsigned long long convertToHTML(Color a);
Color convertToRGB(unsigned long long a);
void printRGB(Color a);
void printHTML(Color a);
int main(){
    Color z, z2;
    unsigned long long html;

    z = getColor();
    printRGB(z);

    html = convertToHTML(z);
    printf("%llu\n", html);
    printHTML(z);

    z2 = convertToRGB(html);
    printRGB(z2);

    return 0;
}

Color getColor()
{
    Color t;
    scanf("%hhu %hhu %hhu", &t.red, &t.green, &t.blue);

    return t;
}

unsigned long long convertToHTML(Color a)
{
    return (a.red*256*256) + (a.green*256) + a.blue;
}

Color convertToRGB(unsigned long long a)
{
    Color t;
    t.blue = a%256;
    t.green = a/256%256;
    t.red = a/256/256%256;
    return t;
}

void printRGB(Color a)
{
    printf("%hhu %hhu %hhu\n", a.red, a.green, a.blue);
}

void printHTML(Color a)
{
    printf("%2.X %X %X\n", a.red, a.green, a.blue); 
}