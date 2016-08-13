#include <stdio.h>

void console(double number);

int main(){

    double number1 = 0.0;
    double number2 = 0.0;
    char operation = 0;

    while(1){
        printf("请输入表达式\n");
        scanf("%lf%c%lf", &number1, &operation, &number2);

        switch(operation){
            case '+':
                console(number1 + number2);
                break;
            case '-':
                console(number1 - number2);
                break;
            case '*':
                console(number1 * number2);
                break;
            case '/':
                if(number2 == 0)
                    printf("除数不能为0\n");
                else
                    console(number1 / number2);
                break;
            case '%':
                if((long)number2 == 0)
                    printf("除数不能为0\n");
                else
                    console((long)number1 % (long)number2);
                break;

            default:
                printf("未识别的计算符!\n");


        }

    }


    return 0;
}

void console(double number){
    printf("%lf\n", number);
}
