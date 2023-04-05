/*
* 利用数组A[M]，如果i在树里，则A[i]=1,else A[i]=0
* 重复调用RandomInteger产生整数r,直到A[r]=0;
* a.if 树上有了N个元素，则还有M-N可以选，产生的概率为(M-N)/M
* thus,time is M/(M-N)
* b. time is M/N
* c. total time = a+a/(a-1),when a = 2,取最小。及一次插入一次删除的时间开销
*/