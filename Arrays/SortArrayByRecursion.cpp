#include<bits/stdc++.h>
using namespace std;

void insert(vector<int>& v, int x) {
    if(v.size() == 0 || v[v.size()-1] <= x) {
        v.push_back(x);
        return;
    }
    int temp = v[v.size()-1];
    v.pop_back();
    insert(v, x);
    v.push_back(temp);
}

void sort(vector<int>& v) {
    if(v.size() == 1)
        return;
    int temp = v[v.size()-1];
    v.pop_back();
    sort(v);
    insert(v, temp);
}

void printArray(vector<int>& v) {
    for(auto i : v)
        cout << i << " ";
    cout << endl;
}
int main() {
    vector<int> v = {20, 10, 4, 50, 100};
    cout << "Before Sort\n";
    printArray(v);
    sort(v);
    cout << "After Sort\n";
    printArray(v);
    return 0;
}

// https://www.youtube.com/watch?v=AZ4jEY_JAVc&list=PL_z_8CaSLPWeT1ffjiImo0sYTcnLzo-wY&index=6&ab_channel=AdityaVerma
