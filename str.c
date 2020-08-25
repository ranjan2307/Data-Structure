#include <stdio.h>
struct stru
{
    char str[20];
    int number;
    float fltnumber;
};

void putstruct1(struct stru s1)
{

    printf("\nChar array : %s ", s1.str);
    printf("\nInt  : %d", s1.number);
    printf("\nFloat : %f", s1.fltnumber);
}

void putstruct2(struct stru *s1)
{
    printf("\nChar array : %s ", s1->str);
    printf("\nInt  : %d", s1->number);
    printf("\nFloat : %f\n", s1->fltnumber);
}

int main()
{
    struct stru str1;
    printf("---Pass by value---\n");
    printf("Enter a string-");
    scanf("%s", str1.str);
    printf("Enter an Integer-");
    scanf("%d", &str1.number);
    printf("Enter a decimal-");
    scanf("%f", &str1.fltnumber);

    putstruct1(str1);
    printf("\n--\n");
    printf("---Pass by reference---\n");
    printf("Enter a string-");
    scanf("%s", str1.str);
    printf("Enter an Integer-");
    scanf("%d", &str1.number);
    printf("Enter a decimal-");
    scanf("%f", &str1.fltnumber);

    putstruct2(&str1);

    return 0;
}
