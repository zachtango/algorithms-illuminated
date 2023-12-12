#include <iostream>
#include <vector>
#include <set>

void instr1() {
    std::cout << 7 << '\n';
}

void instr2(int N, std::vector<int> &A) {
    if (A[0] > A[1]) {
        std::cout << "Bigger" << '\n';
    } else if (A[0] == A[1]) {
        std::cout << "Equal" << '\n';
    } else {
        std::cout << "Smaller" << '\n';
    }
}

void instr3(int N, std::vector<int> &A) {
    if ((A[1] > A[0] && A[0] > A[2]) || (A[2] > A[0] && A[0] > A[1])) {
        std::cout << A[0] << '\n';
    } else if ((A[2] > A[1] && A[1] > A[0]) || (A[0] > A[1] && A[1] > A[2])) {
        std::cout << A[1] << '\n';
    } else {
        std::cout << A[2] << '\n';
    }
}

void instr4(int N, std::vector<int> &A) {
    long long sum = 0;
    for (const auto &a : A) {
        sum += a;
    }
    std::cout << sum << '\n';
}

void instr5(int N, std::vector<int> &A) {
    long long sum = 0;
    for (const auto &a : A) {
        if ((a % 2) == 0) {
            sum += a;
        }
    }
    std::cout << sum << '\n';
}

void instr6(int N, std::vector<int> &A) {
    for (auto &a : A) {
        a %= 26;
        a += 'a';
        std::cout << (static_cast<char>(a));
    }

    std::cout << '\n';
}

void instr7(int N, const std::vector<int> &A) {
    int i = 0;
    std::set<int> visited;
    while (true) {
        i = A[i];
        if (i < 0 || i >= N) {
            std::cout << "Out" << '\n';
            break;
        } else if (i == N - 1) {
            std::cout << "Done" << '\n';
            break;
        } else if (visited.count(i)) {
            std::cout << "Cyclic" << '\n';
            break;
        }
        visited.insert(i);
    }
}

int main() {
    /*
        N t
        A has N integers
        t indicates action

        t = 1 print 7
        t = 2 print bigger if A[0] > A[1]
    */

    int N, t;

    std::cin >> N >> t;

    std::vector<int> A(N);

    for (int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    switch(t) {
        case 1:
            instr1();
            break;
        case 2:
            instr2(N, A);
            break;
        case 3:
            instr3(N, A);
            break;
        case 4:
            instr4(N, A);
            break;
        case 5:
            instr5(N, A);
            break;
        case 6:
            instr6(N, A);
            break;
        case 7:
            instr7(N, A);
            break;
    }

    return 0;
}