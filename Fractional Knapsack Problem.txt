#include <iostream>
#include <algorithm>
using namespace std;

struct Item {

    int profit,weight;
};

bool compare(Item a,Item b) {

    double r1=(double)a.profit/a.weight;
    double r2=(double)b.profit/b.weight;

    return r1>r2;
}

int main() {

    int n;

    cin>>n;

    Item item[n];

    for(int i=0;i<n;i++) {

        cin>>item[i].profit
            >>item[i].weight;
    }

    int capacity;

    cin>>capacity;

    sort(item,item+n,compare);

    double totalProfit=0;

    for(int i=0;i<n;i++) {

        if(item[i].weight<=capacity) {

            totalProfit+=item[i].profit;

            capacity-=item[i].weight;
        }

        else {

            totalProfit+=
            item[i].profit*
            ((double)capacity/
            item[i].weight);

            break;
        }
    }

    cout<<"Maximum Profit = "
        <<totalProfit;

    return 0;
}