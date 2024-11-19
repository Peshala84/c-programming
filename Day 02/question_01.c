#include<stdio.h>

int main(){
    int a=1, b=2, c=3, d=4;
    float A;

    A = (float)(a+b)/(c+d);
    printf("\n a) %.2f", A);

    A = (float)a + (float)b/(c+d);
    printf("\n b) %.2f", A);

    A = (float)(a+b)/c+d;
    printf("\n c) %.2f", A);

    A = (float)a*b/c*d;
    printf("\n d) %.2f", A);

    return 0;  
}
