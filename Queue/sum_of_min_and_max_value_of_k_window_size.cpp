#include<iostream>
#include<queue>
using namespace std;

int solve(int *arr,int n,int k)
{
    deque<int> maxi(k);
    deque<int> mini(k);

    //find first k window size max and mini sum
    for(int i=0;i<k;i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){ //store in  order maxi element in queue
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){ //store in incresing order maxi element in queue
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    int ans = 0;


    //remaining items of array find sum
    for(int i=k;i<n;i++){

         ans += arr[maxi.front()] + arr[mini.front()];
        //removal one element and add next element

        while(!maxi.empty() && i - maxi.front() >= k){
            maxi.pop_front();
        }

       while(!mini.empty() && i - mini.front() >= k){
            mini.pop_front();
        }






          //addition
        while(!maxi.empty() && arr[maxi.back()] <= arr[i]){ //store in decresing order maxi element in queue
            maxi.pop_back();
        }

        while(!mini.empty() && arr[mini.back()] >= arr[i]){ //store in incresing order maxi element in queue
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
    }

    // last wali window

    ans += arr[maxi.front()] + arr[mini.front()];

    return ans;



}
int main(){


int arr[7] = {2,5,-1,7,-3,-1,-2};
int k = 4;

int ans = solve(arr,7,k);

cout<<ans;

return 0;
}
