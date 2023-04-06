#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomSequence(int N) {
    int* numbers = (int*) malloc(N * sizeof(int)); // ��̬�����ڴ汣�������б�
    if (numbers == NULL) {
        printf("�ڴ����ʧ��\n");
        return;
    }

    // ��ʼ�������б�
    for (int i = 0; i < N; i++) {
        numbers[i] = i + 1;
    }

    // ʹ��ʱ����Ϊ����������������ӣ�ȷ��ÿ���������ɵ����ж���ͬ
    srand(time(0));

    // �����������
    for (int i = 0; i < N; i++) {
        int randomIndex = rand() % (N - i); // ����0��N-i-1֮����������
        int randomNumber = numbers[randomIndex]; // �������б���ȡ�������
        printf("%d ", randomNumber); // ��������
        // ��������������б�ĩβ�������б��ȼ�һ
        numbers[randomIndex] = numbers[N - i - 1];
        numbers[N - i - 1] = randomNumber;
    }

    printf("\n");

    free(numbers); // �ͷŶ�̬������ڴ�
}

int main() {
    int N = 10; // ����1��N֮����������
    generateRandomSequence(N);
    return 0;
}
