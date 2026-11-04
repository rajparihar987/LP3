
#include <bits/stdc++.h>
using namespace std;

// Naive String Matching
void naiveSearch(string text, string pattern) {

    int n = text.size();
    int m = pattern.size();

    cout << "\nNaive String Matching:\n";

    if (m == 0 || m > n) {
        cout << "No valid match\n";
        return;
    }

    for (int i = 0; i <= n - m; i++) {

        int j;

        for (j = 0; j < m; j++) {

            if (text[i + j] != pattern[j])
                break;
        }

        if (j == m) {
            cout << "Pattern found at index "
                 << i << "\n";
        }
    }
}

// Rabin-Karp Algorithm
void rabinKarp(string text, string pattern) {

    int d = 256;
    int q = 101;

    int n = text.size();
    int m = pattern.size();

    cout << "\nRabin-Karp String Matching:\n";

    if (m == 0 || m > n) {
        cout << "No valid match\n";
        return;
    }

    int p = 0;
    int t = 0;
    int h = 1;

    // Calculate h = d^(m-1) % q
    for (int i = 0; i < m - 1; i++) {
        h = (h * d) % q;
    }

    // Calculate initial pattern and text hashes
    for (int i = 0; i < m; i++) {

        p = (d * p + pattern[i]) % q;

        t = (d * t + text[i]) % q;
    }

    // Slide the pattern over the text
    for (int i = 0; i <= n - m; i++) {

        // If hashes match, verify characters
        if (p == t) {

            int j;

            for (j = 0; j < m; j++) {

                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m) {
                cout << "Pattern found at index "
                     << i << "\n";
            }
        }

        // Calculate hash of next window
        if (i < n - m) {

            t = (d * (t - text[i] * h)
                 + text[i + m]) % q;

            if (t < 0)
                t += q;
        }
    }
}

int main() {

    string text, pattern;

    cout << "Enter Text: ";
    getline(cin, text);

    cout << "Enter Pattern: ";
    getline(cin, pattern);

    cout << "\nText: " << text;
    cout << "\nPattern: " << pattern << "\n";

    naiveSearch(text, pattern);

    rabinKarp(text, pattern);

    return 0;
}
