#include <stdio.h>
int main(){
    int a = 5;
    int b = 20;
    int c;

    if( a && b ){
        printf("Line 1 - 条件为真\n");
    }

    if( a || b ){
        printf("Line 2 - 条件为真\n");
    }

    a = 0;
    b = 10;
    if( a && b ){
        printf("Line 3 - 条件为真\n");
    }else{
        printf("Line 3 - 条件不为真\n");
    }

    if( !( a && b ) ){
        printf("Line 4 - 条件为真\n");
    }

}
