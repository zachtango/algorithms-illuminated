#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::min;
using std::reverse;

const int GAP_PENALTY = 1;
const int MISMATCH_PENALTY = 1;

int similarity(string a, string b) {
    int n = a.size(),
        m = b.size();

    int A[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        A[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        A[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = min(
                A[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
                min(
                    A[i - 1][j] + 1,
                    A[i][j - 1] + 1
                )
            );
        }
    }

    return A[n][m];
}

/*
    hello
    hola

    0 1 2 3 4 5
    1 0 1 2 3 4
    2 1 1 2 3 3 
    3 2 2 1 2 3
    4 3 3 2 2 3

    i = 4, j = 5
    x = 2 + 1
    y = 3 + 1
    z = 2 + 1
    newA = o
    newB = -

    i = 4, j = 4
    x = 1 + 1
    y = 2 + 1
    z = 2 + 1
    newA = ol
    newB = -a

    i = 3, j = 3



*/
vector<string> reconstruction(string a, string b) {
    int n = a.size(),
        m = b.size();
    
    int A[n + 1][m + 1];

    for (int i = 0; i <= n; i++) {
        A[i][0] = i;
    }
    for (int j = 0; j <= m; j++) {
        A[0][j] = j;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = min(
                A[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
                min(
                    A[i - 1][j] + 1,
                    A[i][j - 1] + 1
                )
            );
        }
    }
    
    string newA, newB;

    int i = n,
        j = m;

    while (i > 0 && j > 0) {
        // case 1
        int x = A[i - 1][j - 1] + (a[i - 1] != b[j - 1]),
        // case 2
            y = A[i - 1][j] + 1,
        // case 3
            z = A[i][j - 1] + 1;
        
        if (x < y && x < z) {
            newA.push_back(a[i - 1]);
            newB.push_back(b[j - 1]);
            i -= 1;
            j -= 1;
        } else if (y < z) {
            newA.push_back(a[i - 1]);
            newB.push_back('-');
            i -= 1;
        } else {
            newA.push_back('-');
            newB.push_back(b[j - 1]);
            j -= 1;
        }
    }

    reverse(newA.begin(), newA.end());
    reverse(newB.begin(), newB.end());

    if (i > 0) {
        newA = a.substr(0, i) + newA;
        newB = string(i, '-') + newB;
    } else if(j > 0) {
        newA = string(j, '-') + newA;
        newB = b.substr(0, j) + newB;
    }

    return {
        newA,
        newB
    };
}

void testSimilarity() {
    struct TestCase {
        string a;
        string b;
        int expected;
    };

    TestCase testCases[] = {
        { "kitten", "sitting", 3 },
        { "flaw", "lawn", 2 },
        { "hello", "hola", 3 },
        { "abcdefg", "abcdefg", 0 },
        { "abc", "def", 3 },
        { "a", "b", 1 },
        { "apple", "orange", 5 },
        { "abcdef", "", 6 },
        { "", "xyz", 3 },
        { "", "", 0 }
    };

    for (const auto& testCase : testCases) {
        int result = similarity(testCase.a, testCase.b);
        cout << "Test Case: " << testCase.a << " | " << testCase.b
             << " | Result: " << result << " | Expected: " << testCase.expected;
        if (result == testCase.expected) {
            cout << " | Test Passed\n";
        } else {
            cout << " | Test Failed\n";
        }
    }
}

void testReconstruction() {
    struct TestCase {
        string a;
        string b;
        vector<string> expected;
    };

    TestCase testCases[] = {
        { "kitten", "sitting", { "kitten-", "sitting" } },
        { "flaw", "lawn", { "flaw-", "-lawn" } },
        { "hello", "hola", { "hello", "hola-" } },
        { "abcdefg", "abcdefg", { "abcdefg", "abcdefg" } },
        { "abc", "def", { "abc", "def" } },
        { "a", "b", { "a", "b" } },
        { "apple", "orange", { "appl-e", "orange" } },
        { "abcdef", "", { "abcdef", "------" } },
        { "", "xyz", { "---", "xyz" } },
        { "", "", { "", "" } }
    };

    for (const auto& testCase : testCases) {
        vector<string> result = reconstruction(testCase.a, testCase.b);
        cout << "Test Case: " << testCase.a << " | " << testCase.b << '\n';
        cout << "Reconstructed A: " << result[0] << " | Expected A: " << testCase.expected[0] << '\n';
        cout << "Reconstructed B: " << result[1] << " | Expected B: " << testCase.expected[1] << '\n';

        if (result[0] == testCase.expected[0] && result[1] == testCase.expected[1]) {
            cout << "Test Passed\n";
        } else {
            cout << "Test Failed\n";
        }
        cout << "------------------------\n";
    }
}


int main() {
    testSimilarity();
    testReconstruction();

    return 0;
}


