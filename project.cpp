#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//merge sort function time complexity :o(nlog(n))
void merge(vector<pair<int,string>>&v,int  low, int mid,int  high)
{
    int i, j, k;
    i = low;
    k = 0;
    j = mid + 1;
    vector<pair<int,string>> temp(high-low+1);
    while (i <= mid && j <= high)
    {
        if ( v[i].first< v[j].first)
        {
            temp[k].first = v[i].first;
            temp[k].second = v[i].second;
            i++;
        }
        else
        {
            temp[k].first = v[j].first;
            temp[k].second = v[j].second;
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        temp[k].first = v[i].first;
        temp[k].second = v[i].second;
        k++;
        i++;
    }
    while (j <= high)
    {
        temp[k].first = v[j].first;
        temp[k].second = v[j].second;
        k++;
        j++;
    }
    for (i = low; i <= high; i++)
    {
        v[i].first =temp[i-low].first;
        v[i].second=temp[i-low].second;
    }
}
void mergeSort(vector<pair<int,string>>&v,int  begin, int  end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(v,begin, mid);
    mergeSort(v,mid+1, end);
    merge(v, begin, mid, end);
}

//binary search function time complexity: O(log(n))
float binary_search(vector<pair<int,string>>&v,int cost,int size)
{
    int l = 0, r = size, mid,ans=-1;
    while (l <= r) {
        mid = (l + r) / 2;
        if ( v[mid].first<=cost) {
            l= mid + 1;
        }
        else {
            ans=mid;
            r = mid-1;
        }
    }
    return ans;
}
//print function time complexity :o(n)
void print_ans(vector<pair<int,string>>&v,int mid)
{
    cout<<"you can buy from this brand :"<<endl;
    for(int j=0;j<mid;j++)    {
        cout<<j+1<<". "<<v[j].second<<"  "<<v[j].first<<endl;
    }
}
int main() {
    float cost, num;
    cout << "please enter your budget :" << endl;
    cin >> cost;
    cout << "please enter number of brands :" << endl;
    cin >> num;
    cout << "please enter tne name of brand and the cost of item :" << endl;
    vector<pair<int,string >> v(num);
    // loop time complexity o(n)
    for (int i = 0; i < num; i++) {
        cin >> v[i].second >>v[i].first;
    }
    mergeSort(v,0,num-1);
    float x= binary_search(v,cost,num);
    print_ans(v,x);
    return 0;
}