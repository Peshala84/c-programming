#include<stdio.h>

int main(){
    char C='B';
    int i=3,j=3,k=3;
    double x=0.0,y=2.3;

    printf("%s\n",(i&&j&&k)?"True":"False");
    printf("%s\n",(i||j||k)?"True":"False");
    printf("%s\n",(i&&j||k)?"True":"False");
    printf("%s\n",(i||j&&k)?"True":"False");
    printf("%s\n",(i&&j&&k||1)?"True":"False");
    printf("%s\n",(i&&j&&k||0)?"True":"False");
    printf("%s\n",(i&&j&&k||C)?"True":"False");
    printf("%s\n",(i&&j&&k||x)?"True":"False");
    printf("%s\n",(i&&j&&k||y)?"True":"False");
    printf("%s\n",(i&&j&&k&&1)?"True":"False");
    printf("%s\n",(i&&j&&k&&0)?"True":"False");
    printf("%s\n",(i&&j&&k&&C)?"True":"False");
}