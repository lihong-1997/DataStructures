#include<stdio.h>
#include<limits.h>

int MinSubsequenceSum(const int arr[], int N)
{
    int sum = 0, temp_min = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum > 0) sum = 0;
        if (sum < temp_min) temp_min = sum;
    }
    return temp_min;
}

int MaxSubsequenceMul(const int arr[], int N)
{
    int maxMulti = 0;
    
    for (int i = 0; i < N; i++)
    {
        int mul = 1;
        for (int j = i; j < N; j++)
        {
            mul *= arr[j];
            if(mul > maxMulti) maxMulti = mul;
        }
    }
    return maxMulti;
}

int MinPoSubsequenceSum(const int arr[], int N) //O(N^2)
{
    int minPoSum = INT_MAX;
    
    for (int i = 0; i < N; i++)
    {
        int sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            if(sum > 0 && sum < minPoSum) minPoSum = sum;
        }
    }
    return minPoSum;
}

typedef struct node{
	int value; //求和的值
	int rank; //第几轮求和
}nodes;

int quickSort(nodes a[],int low,int high){

	nodes pivotkey = a[low];
	while(low < high){
		while(low < high && a[high].value >= pivotkey.value) --high;
		a[low] = a[high];
		while(low < high && a[low].value <= pivotkey.value) ++low;
		a[high] = a[low];
	} 
	a[low] = pivotkey;
	return low;
} 
 
void Qsort(nodes a[],int low,int high){
	if(low < high){
		int temp = quickSort(a, low, high);
		Qsort(a, low, temp);
		Qsort(a, temp + 1, high); 
	}
} 

int fasterMinPoSubsequenceSum(const int arr[], int N) //O(NlogN)
{
    nodes b[N];

	int sum = 0;
	for(int i = 0;i < N;i++){
		sum += arr[i];
		b[i].value = sum;
		b[i].rank = i;
	}
	
	Qsort(b, 0, N-1);

    int min = INT_MAX;

	for(int i = 1;i < N;i++)
    {
		if(b[i].rank > b[i-1].rank)
        {
			int temp = b[i].value - b[i-1].value;
			if(temp > 0 && temp < min)
                min = temp;
            else if (temp == 0)
            {
                for(int k = i-2;k>=0;k--)
                {
                    if(b[i].rank > b[k].rank)
                    {
                        temp = b[i].value - b[k].value;
                        if(temp > 0 && temp < min) min = temp;
                        break;
                    }
                }
            }
		}
	}

    return min;
}

int main(){

    // int arr[8] = {-4,-1,12,-2,-1,3,6,-2}; //求和出现两相等数挨着，导致bug
    // int arr2[6] = {-2,11,-4,13,-5,-2};
    // int arr3[6] = {-8,-3,-1,-4,1,20};

    // int min = fasterMinPoSubsequenceSum(arr3, 6);
    // int min2 = MinPoSubsequenceSum(arr3, 6);

    // printf("%d,%d", min, min2);

    int arr4[5] = {-4,6,-1,-2,1};
    int max = MaxSubsequenceMul(arr4, 5);
    printf("%d", max);
}