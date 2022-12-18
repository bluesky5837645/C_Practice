#include<stdio.h>
#include<stdlib.h>

int main(){
    int num1, num2, num3;
    num1 = 6;
    num2 = 7;
    num3 = 24;
    printf("Number1 add number2 and number3 is: %d", num1 + num2 + num3);

    system("pause");
    return 0;

}
/*
如果變數沒有初始化，則變數裡面的值則為是記憶體內部殘存的值
可以試看看以下的code:
int main(){
    int num1, num2, num3;
    printf("Number1 add number2 and number3 is: %d", num1 + num2 + num3);

    system("pause");
    return 0;

}
可以發現結果會很神奇
*/