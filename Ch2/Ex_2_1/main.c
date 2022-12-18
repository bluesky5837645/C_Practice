#include<stdio.h>
#include<stdlib.h>   // c才要.h


int main(void){
    int num;   // 也可以寫成 int num = 1;
    num = 1;
    printf("I have %d cats\n", num); // \是反斜線
    printf("I have %d cats too\n", num);  // f是format的意思
    system("pause");  // 呼叫pause指令，但這個在linux裡面並沒有相關指令，所以不能work
    return 0;
}

/*
printf("I have %d cats\n", num);也可以打成
printf("I have %d cats\n",
num);
並不會影響最終結果，因為空白鍵對編譯不會產生影響(當然包含在字串裡面就會影響了)
甚至int num;
num = 1;
可以打成
int num
=1;
一切的語句都是從分號開始分號結束
*/