#include <stdio.h>

int fibonaci(int i){
    if(i < 2 && i >= 0){
        return i;
    }
    return fibonaci(i - 1) + fibonaci(i - 2);
}

int main(){
    int i;
    for(i = 0; i < 10; i++){
        printf("%d\t", fibonaci(i));
    }
    return 0;
}
