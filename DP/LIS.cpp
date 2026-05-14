// LIS -> O(n log n)
// store[i] = minimum ending value of LIS of length (i+1)
// lower_bound finds first element >= current element

int LIS(vector<int> &v) {

    vector<int> store;

    for(auto x : v) {

        if(store.empty() || store.back() < x)
            store.push_back(x);

        else {
            int idx = lower_bound(store.begin(), store.end(), x) - store.begin();
            store[idx] = x;
        }
    }

    return store.size();
}
