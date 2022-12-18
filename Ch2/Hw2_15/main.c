#include<stdio.h>
#include<stdlib.h>

int main(void){
    int main = 2;
    printf("I use the main as a variable and its value is: %d", main);
    system("pause");
    return 0;
}

/*
只要是函數都是識別字，都是可以命名跟撞名的
main()就像是一個大函數的宣告，其內容包含在區塊中{}
程式執行的時候就會呼叫main函數
*/