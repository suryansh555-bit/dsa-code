#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    unordered_map<int, int> mp;
    int prefixSum = 0;
    int count = 0;

    for(int i = 0; i < n; i++) {
        prefixSum += arr[i];

        if(prefixSum == 0)
            count++;

        if(mp.find(prefixSum) != mp.end())
            count += mp[prefixSum];

        mp[prefixSum]++;
    }

    cout << count;

    return 0;
}