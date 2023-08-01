#include <iostream>
using std::cout;
#include <string>
using std::string;
#include <algorithm>
using std::min;

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

int main() {
    testSimilarity();

    return 0;
}


