#include "searchtree.h"
#include <stdio.h>

// gcc 13deleteTest.c src/searchtree.c src/queue.c -Iinclude -o exe/main13

int main(int argc, char* argv){

    int nums[1000] = {0}; // initialize array to all zeros
    int count = 0;
    srand(time(NULL)); // seed random number generator with current time

    while (count < 1000) {
        int num = rand() % 10000 + 1; // generate random number between 1 and 1000

        // check if number has already been generated
        int found = 0;
        for (int i = 0; i < count; i++) {
            if (nums[i] == num) {
                found = 1;
                break;
            }
        }

        // if number hasn't been generated, add it to array and increment count
        if (!found) {
            nums[count] = num;
            count++;
        }
    }

    __clock_t start,finish;
    long long int time2; 
    int diff, IsBalance;


    // create search tree1
    SearchTree T1 = MakeEmpty(NULL);
	for (int i = 0; i < 1000; ++i)
	{
		T1 = Insert(nums[i], T1);
	}
    time2 = 0;
    // Tl delete test
    for (int i = 0; i < 200; i++)
    {
        int dValue = PreOrderFullNode(T1);
        start = clock();
        DeleteTl(dValue, T1);
        finish = clock();
        time2 += (finish - start);
    }
    printf("Tl max node delete cost:%lld\n", time2);
    diff = 0; //max height difference
    IsBalance = GetBalansability(T1, &diff); // tree is balanced?
    printf("%d %d\n", diff, IsBalance);

    /************create search tree2**********/
    SearchTree T2 = MakeEmpty(NULL);
	for (int i = 0; i < 1000; ++i)
	{
		T2 = Insert(nums[i], T2);
	}
    time2 = 0;
    // Tl delete test
    for (int i = 0; i < 200; i++)
    {
        int dValue = PreOrderFullNode(T2);
        srand((unsigned)time(NULL));
	    int seed = rand()%2;
        start = clock();
        DeleteRandom(dValue, T2, seed);
        finish = clock();
        time2 += (finish - start);
    }
    printf("Tl max node delete cost:%lld\n", time2);
    diff = 0; //max height difference
    IsBalance = GetBalansability(T2, &diff); // tree is balanced?
    printf("%d %d\n", diff, IsBalance);


        /************create search tree3**********/
    SearchTree T3 = MakeEmpty(NULL);
	for (int i = 0; i < 1000; ++i)
	{
		T3 = Insert(nums[i], T3);
	}
    time2 = 0;
    // Tl delete test
    int flag = 0;
    for (int i = 0; i < 200; i++)
    {
        int dValue = PreOrderFullNode(T3);
        flag = ~flag;
        start = clock();
        DeleteRandom(dValue, T3, flag);
        finish = clock();
        time2 += (finish - start);
    }
    printf("Tl max node delete cost:%lld\n", time2);
    diff = 0; //max height difference
    IsBalance = GetBalansability(T3, &diff); // tree is balanced?
    printf("%d %d\n", diff, IsBalance);
    
    return 0;
}