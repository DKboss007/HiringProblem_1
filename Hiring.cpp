#include<iostream>
#include<stdlib.h>
//#include<random>
#include<ctime>

using namespace std;

void getWeight(int *wt, int n)
{
    for(int i=0; i<n; i++)
        cin>>*wt++;
    cout<<endl;
}

void getPermutation(int *p, int n)
{
    for(int i=0; i<n; i++)
    {
        int j = 0;
        *(p+i) = rand()% n + 1;
        srand(time(NULL));
        while(j<i)
        {
            if(*(p+j++)==*(p+i))
            {
                j=0;
                *(p+i) = rand()%n +1;
            }
        }
    }
}

void printPermutation(int *p, int n)
{
    cout<<"Permutation Selected :";
    for(int i=0; i<n; i++)
    {
        cout<<*(p+i)<<" ";
    }
    cout<<endl;
}

void getCandidate(int *wt, int *p, int n, int reqWt)
{
    for(int i=0; i<n; i++)
    {
        if(*(wt+*(p+i)-1)==reqWt)
        {
            cout<<"Candidate "<<*(p+i)<<" is Selected\n";
            return;
        }
        cout<<"Candidate "<<*(p+i)<<" is NOT Selected\n";
    }
    cout<<"No Candidate is Selected!\n";
}

int main()
{
    int n;
    cout<<"Enter Number of Candidates :";
    cin>>n;
    int weight[n];
    cout<<"Enter Weight for Candidates\n";
    getWeight(&weight[0], n);
    int reqWt;
    cout<<"Enter the Required Weight :";
    cin>>reqWt;
    int arr[n];
    getPermutation(&arr[0], n);
    printPermutation(&arr[0], n);
    getCandidate(&weight[0], &arr[0], n, reqWt);
    return 0;
}
