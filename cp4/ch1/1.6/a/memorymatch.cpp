#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <vector>

void removeCard(int c, std::unordered_set<int> &cards) {
    if (cards.count(c)) {
        cards.erase(c);
    }
}

int removeMatchingCards(std::unordered_set<int> &cards, const std::vector<std::string> &cardToWord) {
    std::vector<int> cardsCopy(cards.begin(), cards.end());
    int removed = 0;
    for (int i = 0; i < cardsCopy.size(); i++) {
        for (int j = i + 1; j < cardsCopy.size(); j++) {
            if (cardToWord[cardsCopy[i]] == cardToWord[cardsCopy[j]]) {
                cards.erase(cardsCopy[i]);
                cards.erase(cardsCopy[j]);
                removed += 2;
                break;
            }
        }
    }

    return removed;
}

int main() {
    /*
        initially, all cards are unknown, so the cardsKnown set is empty

        1. For each turn
            a. if p1 = p2, remove c1 and c2 from cardsKnown set
            b. else add c1 and c2 to cardsKnown set
        2. Here we will have a cardsKnown set, but it could still possibly have matching pairs
        3. Remove matching pairs from cardsKnown set
        4. Now we have no cardsKnown set with no matching pairs
            a. if the cardsKnown set is >= number of unknown cards, we can pick an unknown card first and then match it with a cardsKnown
            b. else, we can't do anything with cardsKnown set
    */

    std::unordered_set<int> cardsKnown;

    int n, k;

    std::cin >> n >> k;

    int numCards = n;
    std::vector<std::string> cardToWord(n + 1);
    
    for (int i = 0; i < k; i++) {
        int c1, c2;
        std::string p1, p2;

        std::cin >> c1 >> c2 >> p1 >> p2;

        if (p1 == p2) {
            numCards -= 2;
            removeCard(c1, cardsKnown);
            removeCard(c2, cardsKnown);
        } else {
            cardToWord[c1] = p1;
            cardToWord[c2] = p2;
            cardsKnown.insert(c1);
            cardsKnown.insert(c2);
        }
    }

    int numCardsRemoved = removeMatchingCards(cardsKnown, cardToWord);
    numCards -= numCardsRemoved;

    if (cardsKnown.size() == (numCards / 2)) {
        numCardsRemoved += numCards;
    } else if (numCards == 2) {
        numCardsRemoved += 2;
    }

    std::cout << (numCardsRemoved / 2) << '\n';

    return 0;
}
