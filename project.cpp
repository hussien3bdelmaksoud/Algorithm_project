#include <iostream>
#include<bits/stdc++.h>
using namespace std;
// time complexity of code :o(n(log(n)))


// merge function time complexity :o(n)
void merge(vector<pair<float,string>>&v,int  begin, int mid,int  end)
{
    int indexOfLeftVector, i,indexOfRightVector, indexOfTempVector;
    indexOfLeftVector = begin;
    indexOfTempVector = 0;
    indexOfRightVector = mid + 1;
    vector<pair<float,string>> temp(end-begin+1);
    while (indexOfLeftVector <= mid && indexOfRightVector <= end)
    {
        if ( v[indexOfLeftVector].first< v[indexOfRightVector].first)
        {
            temp[indexOfTempVector].first = v[indexOfLeftVector].first;
            temp[indexOfTempVector].second = v[indexOfLeftVector].second;
            indexOfLeftVector++;
        }
        else
        {
            temp[indexOfTempVector].first = v[indexOfRightVector].first;
            temp[indexOfTempVector].second = v[indexOfRightVector].second;
            indexOfRightVector++;
        }
        indexOfTempVector++;
    }
    // Insert all the remaining values from i to mid into temp[].
    while (indexOfLeftVector <= mid)
    {
        temp[indexOfTempVector].first = v[indexOfLeftVector].first;
        temp[indexOfTempVector].second = v[indexOfLeftVector].second;
        indexOfTempVector++;
        indexOfLeftVector++;
    }

    // Insert all the remaining values from j to high into temp[].
    while (indexOfRightVector <= end)
    {
        temp[indexOfTempVector].first = v[indexOfRightVector].first;
        temp[indexOfTempVector].second = v[indexOfRightVector].second;
        indexOfTempVector++;
        indexOfRightVector++;
    }
    for (i = begin; i <= end; i++)
    {
        v[i].first =temp[i-begin].first;
        v[i].second=temp[i-begin].second;
    }
}
// merge sort time complexity :o(nlog(n))
void mergeSort(vector<pair<float,string>>&v,int  begin, int  end)
{
    if (begin >= end)
        return;
    auto mid = begin + (end - begin) / 2;
    mergeSort(v,begin, mid);
    mergeSort(v,mid+1, end);
    merge(v, begin, mid, end);
}
//binary search function time :  O(log(n))
int binary_search(vector<pair<float,string>>&items,float cost,int numbers)
{

    int l = 0, r = numbers, mid,ans=-1;
    while (l <= r) {
        mid = (l + r) / 2;
        if ( items[mid].first<=cost) {
            l= mid + 1;

        }
        else {
            ans=mid;
            r = mid-1;
        }
    }
    return ans;
}
// any loop in this code is :o(n)
// any cout in this code is :o(1)
int main() {
    int  num;
    float cost;
    cout<<"    WELCOM   \n";
    cout << "PLEASE ENTER YOUR BUDGET :" << endl;
    cin >> cost;
    cout << "PLEASE ENTER NUMBER OF BRANDS :" << endl;
    cin >> num;
    cout << "PLEASE ENTER THE NAME OF BRAND AND THE COST OF ITEMS :" << endl;
    vector<pair<float,string >> items(num);
    // for enter values
    for (int i = 0; i < num; i++) {
        cin >>  items[i].second >>items[i].first;
    }
    //to sort the vector
    mergeSort( items,0,num-1);// o(nlog(n))
    // to get the value of binary search function
    int value= binary_search( items,cost,num);// o(log(n))
    // print the answer
    if(value>0)
    {

        cout<<"YOU CAN BUY FROM THIS BRANDS  :"<<endl;
        for (int j = 0; j < value; j++) {
            cout <<j+1<<"- "<<items[j].second << " " << items[j].first << endl;

        }
    }
    else {
        cout<<"SORRY YOU CAN'T BUY ANY PRODUCT YOUR BUDGET IS VERY LOW "<<endl;
    }
    cout<<"THANK YOU FOR USING THIS APPLICATION\n";
    return 0;

}
