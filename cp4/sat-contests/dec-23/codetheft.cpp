#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

constexpr const int MAX_LINES {10000};
const std::string END = "***END***";

void trim(std::string &s) {
    std::string newS;
    
    for (char c : s) {
        if (c == ' ' && (newS.empty() || newS.back() == ' ')) {
            continue;
        }
        newS.push_back(c);
    }

    while (!newS.empty() && newS.back() == ' ') {
        newS.pop_back();
    }

    s = newS;
}

int nextId {0};
std::unordered_map<std::string, int> sId;

std::vector<int> processFragment() {
    std::vector<int> ids;
    std::string line;
    while (std::getline(std::cin, line) && line != END) {
        trim(line);
        if (!line.empty()) {
            if (!sId.count(line)) {
                sId[line] = nextId;
                nextId += 1;
            }
            ids.push_back(sId[line]);
        }
    }
    return ids;
}

int lcs(const std::vector<int> &A, const std::vector<int> &B) {
    int n = A.size();
    int m = B.size();
    int ans = 0;

    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i] == B[j]) {
                dp[i][j] = 1;
                if (i > 0 && j > 0) {
                    dp[i][j] += dp[i - 1][j - 1];
                }
                ans = std::max(ans, dp[i][j]);
            } else {
                dp[i][j] = 0;
            }
        }
    }

    return ans;
}

int main() {
    std::string line;
    std::getline(std::cin, line);
    int n = std::stoi(line);
    

    std::vector<std::pair<std::string, std::vector<int>>> fragments(n);
    for (auto &[name, lines] : fragments) {
        std::getline(std::cin, name);
        lines = processFragment();
    }

    std::vector<int> repo = processFragment();
    
    std::map<int, std::vector<int>> m;
    for (int i = 0; i < n; i++) {
        m[lcs(repo, fragments[i].second)].push_back(i);
    }
    
    m[0].clear();
    
    std::cout << m.rbegin()->first;
    for (int i : m.rbegin()->second) {
        std::cout << ' ' << fragments[i].first;
    }
    std::cout << '\n';

    return 0;
}
