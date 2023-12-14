#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

template<class it>
void printContainer(it begin, it end) {
    while (begin != end) {
        std::cout << *(begin++) << ' ';
    }
    std::cout << '\n';
}

bool inOriginalOrder(const std::vector<int> &deck) {
    for (int i = 0; i < deck.size(); i++) {
        if (deck[i] != i) {
            return false;
        }
    }
    return true;
}

void shuffle(std::vector<int> &deck, bool in) {
    int length = deck.size();
    std::deque<int> half1(deck.begin(), deck.begin() + length / 2);
    std::deque<int> half2(deck.begin() + length / 2, deck.end());
    // printContainer(half1.begin(), half1.end());
    // printContainer(half2.begin(), half2.end());

    if (in) {
        std::swap(half1, half2);
    } else if ((length % 2) == 1) {
        half1.push_back(half2.front());
        half2.pop_front();
    }

    int n = std::min(half1.size(), half2.size());
    int i = 0;
    for (; i < n; i++) {
        deck[2 * i] = half1[i];
        deck[2 * i + 1] = half2[i];
    }

    while (i < half1.size()) {
        deck[2 * i] = half1[i];
        i += 1;
    }

    while (i < half2.size()) {
        deck[2 * i] = half2[i];
        i += 1;
    }

}

int main() {
    /*
        even --> both split decks are same amount
        odd -->
            out-shuffle --> first half has 1 more card than second half
            in-shuffle --> first half has 1 less card than second half
    */

    int N;

    std::string S;
    
    std::cin >> N >> S;

    if (N == 1) {
        std::cout << 1 << '\n';
        return 0;
    }

    std::vector<int> deck(N);
    for (int i = 0; i < N; i++) {
        deck[i] = i;
    }

    int numShuffles = 1;
    
    while(shuffle(deck, S == "in"), !inOriginalOrder(deck)) {
        // for (auto c : deck) {
        //     std::cout << c << ' ';
        // }
        // std::cout << '\n';
        numShuffles += 1;
    }

    std::cout << numShuffles << '\n';

    return 0;
}