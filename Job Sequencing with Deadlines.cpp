#include <iostream>
#include <algorithm>
using namespace std;

struct Job {

    char id;
    int deadline,profit;
};

bool compare(Job a,Job b) {

    return a.profit>b.profit;
}

int main() {

    int n;

    cin>>n;

    Job job[n];

    for(int i=0;i<n;i++) {

        cin>>job[i].id
            >>job[i].deadline
            >>job[i].profit;
    }

    sort(job,job+n,compare);

    int slot[n];

    for(int i=0;i<n;i++)
        slot[i]=-1;

    int totalProfit=0;

    for(int i=0;i<n;i++) {

        for(int j=job[i].deadline-1;
            j>=0;
            j--) {

            if(slot[j]==-1) {

                slot[j]=i;

                totalProfit+=
                job[i].profit;

                break;
            }
        }
    }

    cout<<"Selected Jobs: ";

    for(int i=0;i<n;i++) {

        if(slot[i]!=-1)
            cout<<job[slot[i]].id
                <<" ";
    }

    cout<<"\nTotal Profit = "
        <<totalProfit;

    return 0;
}