#include "Phonenumber.h"

// gcc main.c Phonenumber.c -o main -lm -lbsd

int main()
{
    char TXT[] = "phone.txt";
    FILE* fp;
	char line[100];
	fp = fopen(TXT, "r");
    fgets(line, 100, fp);

    int N;
    N = line[0] - '0';
    HashTable H;
    H = InitializeTable(4 * N);

    for (int i = 0; i < 2 * N;i++)
    {
        fscanf(fp, "%s", line);
        Insert(line, H);
    }
    ScanAndOutput(H);

    return 0;
}