#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

bool isVowel(char c) {
    switch (c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
    }

    return false;
}

int main() {

    // 1. Inputting strings
    std::string T;
    std::string line;

    std::string lastLine;
    while (std::getline(std::cin, line)) {
        if (line.substr(0, 7) == ".......") {
            std::string s;
            while (std::getline(std::cin, s)) {
                lastLine = s;
            }
            break;
        }

        T += line + ' ';
    }

    if (T.size()) {
        T.pop_back();
    }

    std::string P {"book"};
    // 2. Finding substrings
    auto found = T.find(P);
    if (found == std::string::npos) {
        std::cout << -1 << '\n';
    } else {
        while (found != std::string::npos) {
            std::cout << found << ' ';
            found = T.find(P, found + P.size());
        }
        std::cout << '\n';
    }

    // 3. Simple analysis
    int numVowels = 0, numCons = 0, numDigits = 0;
    for (auto &c : T) {
        c = std::tolower(c);
        if (isVowel(c)) {
            numVowels += 1;
        } else if (std::isalpha(c)) {
            numCons += 1;
        } else if (std::isdigit(c)) {
            numDigits += 1;
        }
    }

    std::cout << "T: " << T << '\n'
            << "Vowels: " << numVowels << '\n'
            << "Consenants: " << numCons << '\n'
            << "Digits: " << numDigits << '\n';

    // 4. Tokenization with '.' and ' ' as delimiters
    std::stringstream ss1(T);
    std::string token;
    std::vector<std::string> tokens;
    while (std::getline(ss1, token, ' ')) {
        std::stringstream ss2(token);
        while (std::getline(ss2, token, '.')) {
            tokens.push_back(token);
        }
    }

    std::sort(tokens.begin(), tokens.end());

    std::cout << "Sorted tokens: ";
    for (const auto &token : tokens) {
        std::cout << token << ' ';
    }
    std::cout << '\n';

    // 5. Frequency of words
    std::unordered_map<std::string, int> wordFreq;
    std::vector<std::string> maxWords;
    int maxWordCount = 0;
    for (const auto &token : tokens) {
        wordFreq[token] += 1;

        if (wordFreq[token] > maxWordCount) {
            maxWords.clear();
            maxWords.push_back(token);
            maxWordCount = wordFreq[token];
        } else if (wordFreq[token] == maxWordCount) {
            maxWords.push_back(token);
        }
    }
    
    std::cout << "Max Words: ";
    for (const auto &word : maxWords) {
        std::cout << word << ' ';
    }
    std::cout << '\n';
    std::cout << "Count: " << maxWordCount << '\n';

    // 6. Last line, reading into string without knowing length in advance using std::string
    std::cout << "Last line: " << lastLine << '\n';

    return 0;
}