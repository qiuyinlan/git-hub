#include <stdio.h>
#define LOW 1            // 初始下限
#define HIGH 100         // 初始上限

int main(void)
{
    char response;
    int guess;
    int low = LOW;
    int high = HIGH;

    guess = (low + high) / 2;
    printf("Pick an integer from %d to %d. I will try to guess ",
            LOW, HIGH);
    printf("it.\nRespond with a y if my guess is right, with an s if it\n");
    printf("is small and with a b if it is big.\n");
    printf("Uh...is your number %d?\n", guess);

    while (1) {
        response = getchar();  // 读取用户输入

        // 如果遇到 EOF，结束程序
        if (response == EOF) {
            printf("\nEnd of input. Exiting the program.\n");
            break;
        }

        // 如果猜对了
        if (response == 'y') {
            printf("I knew I could do it!\n");
            break; // 猜对了，退出循环
        }
        
        // 根据用户的响应调整猜测范围
        if (response == 's') {
            low = guess;
            guess = (guess + high) / 2;
        } else if (response == 'b') {
            high = guess;
            guess = (guess + low) / 2;
        } else {
            printf("Sorry, I understand only y, s and b.\n");
        }

        // 提示用户下一次猜测
        printf("Well, then, is it %d?\n", guess);
        
        // 跳过剩余的输入行，直到遇到换行符
        while (getchar() != '\n')
            continue;

        // 防止猜测超过上限
        if (guess == HIGH - 1)
            guess++;
    }
    
    return 0;
}
