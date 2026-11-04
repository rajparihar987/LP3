
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;
using namespace chrono;

const int N = 300;

int A[N][N], B[N][N], C[N][N];

// Normal Matrix Multiplication
void normalMultiplication() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            C[i][j] = 0;

            for (int k = 0; k < N; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Calculate one row using one thread
void multiplyRow(int row) {
    for (int j = 0; j < N; j++) {
        C[row][j] = 0;

        for (int k = 0; k < N; k++) {
            C[row][j] += A[row][k] * B[k][j];
        }
    }
}

// Multithreaded Matrix Multiplication
void parallelMultiplication() {
    vector<thread> threads;

    for (int i = 0; i < N; i++) {
        threads.emplace_back(multiplyRow, i);
    }

    for (auto &t : threads) {
        t.join();
    }
}

int main() {
    mt19937 rng(42);

    // Generate random matrices
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rng() % 10;
            B[i][j] = rng() % 10;
        }
    }

    // Normal multiplication
    auto start = high_resolution_clock::now();

    normalMultiplication();

    auto end = high_resolution_clock::now();

    double normalTime =
        duration<double, milli>(end - start).count();

    // Save result for verification
    int result[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            result[i][j] = C[i][j];

    // Parallel multiplication
    start = high_resolution_clock::now();

    parallelMultiplication();

    end = high_resolution_clock::now();

    double parallelTime =
        duration<double, milli>(end - start).count();

    // Verify both results
    bool correct = true;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (result[i][j] != C[i][j])
                correct = false;
        }
    }

    cout << fixed << setprecision(3);

    cout << "Normal Multiplication Time: "
         << normalTime << " ms\n";

    cout << "Parallel Multiplication Time: "
         << parallelTime << " ms\n";

    cout << "Speedup: "
         << normalTime / parallelTime << "x\n";

    cout << "Results Match: "
         << (correct ? "YES" : "NO") << "\n";

    cout << "\nResult Matrix (first 5x5):\n";

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
