#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct node
{
    int value;
    int rank;
};

int MinPoSubsequenceSum(const vector<int> &v)
{
    vector<node> data(v.size());
    int sum = 0, MinSum = INT_MAX;
    for (int i = 0;i < v.size();i++)
    {
        sum += v[i];
        data[i].rank = i;
        data[i].value = sum;
    }
    sort(data.begin(), data.end(), 
        [](const node &i, const node &j){return i.value < j.value;});
    // auto loc = find_if(data.begin(), data.end(),       
	// 	[](const node& i) {return i.value > 0; });
	// if (loc != data.end())
    //     MinSum = loc->value;
    
    // for (const node& i : data)
    //     cout<<i.value<<" rank: "<<i.rank<<"  ";

    int temp, n=0;
    for (auto iter = data.begin()+1;iter != data.end();iter++) {   
		if (iter->rank > (iter-1)->rank)
        {
            temp = iter->value - (iter-1)->value;
            if (temp > 0 && temp < MinSum) MinSum = temp;
            else if (temp == 0){
                int rank = iter->rank, value = iter->value;
                auto index = find_if(data.rbegin()+n, data.rend(),  
                                    [=](const node &i){return (i.rank < rank)&&(value > i.value);});
                MinSum = min(value - index->value, MinSum);
            }
        }
        n++;
	}	
	return MinSum;
}

int main(){

    vector<int> v1 = {-4,-1,12,-2,-1,3,6,-2};
    vector<int> v2 = {-2,11,-4,13,-5,-2};
    vector<int> v3 = {-8,-3,-1,-4,1,20};
    
    int min,min2,min3;
    min = MinPoSubsequenceSum(v1);
    min2 = MinPoSubsequenceSum(v2);
    min3 = MinPoSubsequenceSum(v3);
    cout<<min<<endl<<min2<<endl<<min3;
}