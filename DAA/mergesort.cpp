
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

// Merge two sorted subarrays
void merge(vector<int>& a, int l, int m, int r) {
    vector<int> temp;

    int i = l;
    int j = m + 1;

    while (i <= m && j <= r) {
        if (a[i] <= a[j])
            temp.push_back(a[i++]);
        else
            temp.push_back(a[j++]);
    }

    while (i <= m)
        temp.push_back(a[i++]);

    while (j <= r)
        temp.push_back(a[j++]);

    for (int k = 0; k < (int)temp.size(); k++) {
        a[l + k] = temp[k];
    }
}

// Normal Merge Sort
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);

    merge(a, l, m, r);
}

// Multithreaded Merge Sort
void parallelMergeSort(vector<int>& a,
                       int l, int r, int depth) {
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

    if (depth > 0) {

        thread t1(parallelMergeSort, ref(a),
                  l, m, depth - 1);

        thread t2(parallelMergeSort, ref(a),
                  m + 1, r, depth - 1);

        t1.join();
        t2.join();
    }
    else {
        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
    }

    merge(a, l, m, r);
}

// Compare both algorithms
void testCase(string name, vector<int> original) {

    vector<int> a = original;
    vector<int> b = original;

    // Normal Merge Sort
    auto start = high_resolution_clock::now();

    mergeSort(a, 0, (int)a.size() - 1);

    auto end = high_resolution_clock::now();

    double normalTime =
        duration<double, milli>(end - start).count();

    // Parallel Merge Sort
    start = high_resolution_clock::now();

    int depth = 3;

    parallelMergeSort(b, 0, (int)b.size() - 1, depth);

    end = high_resolution_clock::now();

    double parallelTime =
        duration<double, milli>(end - start).count();

    cout << "\n" << name << "\n";

    cout << "Normal Merge Sort: "
         << normalTime << " ms\n";

    cout << "Parallel Merge Sort: "
         << parallelTime << " ms\n";

    if (parallelTime > 0) {
        cout << "Speedup: "
             << normalTime / parallelTime << "x\n";
    }

    cout << "Both Results Correct: "
         << (a == b ? "YES" : "NO") << "\n";
}

int main() {

    int n = 100000;

    vector<int> best(n);
    vector<int> worst(n);
    vector<int> average(n);

    // Best Case: Already sorted
    for (int i = 0; i < n; i++) {
        best[i] = i;
    }

    // Worst Case: Reverse sorted
    for (int i = 0; i < n; i++) {
        worst[i] = n - i;
    }

    // Average Case: Random elements
    mt19937 rng(42);

    for (int i = 0; i < n; i++) {
        average[i] = rng() % 100000;
    }

    cout << fixed << setprecision(3);

    testCase("BEST CASE", best);
    testCase("WORST CASE", worst);
    testCase("AVERAGE CASE", average);

    return 0;
}
