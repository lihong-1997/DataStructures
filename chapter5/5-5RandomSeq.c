#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomSequence(int N) {
    int* numbers = (int*) malloc(N * sizeof(int)); // 动态分配内存保存整数列表
    if (numbers == NULL) {
        printf("内存分配失败\n");
        return;
    }

    // 初始化整数列表
    for (int i = 0; i < N; i++) {
        numbers[i] = i + 1;
    }

    // 使用时间作为随机数生成器的种子，确保每次运行生成的序列都不同
    srand(time(0));

    // 生成随机序列
    for (int i = 0; i < N; i++) {
        int randomIndex = rand() % (N - i); // 生成0到N-i-1之间的随机索引
        int randomNumber = numbers[randomIndex]; // 从整数列表中取得随机数
        printf("%d ", randomNumber); // 输出随机数
        // 将随机数交换到列表末尾，并将列表长度减一
        numbers[randomIndex] = numbers[N - i - 1];
        numbers[N - i - 1] = randomNumber;
    }

    printf("\n");

    free(numbers); // 释放动态分配的内存
}

int main() {
    int N = 10; // 生成1到N之间的随机序列
    generateRandomSequence(N);
    return 0;
}
