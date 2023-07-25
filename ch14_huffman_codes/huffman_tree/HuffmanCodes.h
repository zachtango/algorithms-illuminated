#include <cmath>
#include <initializer_list>
#include <stdexcept>
#include <queue>
#include <functional>
#include <string>
#include <map>
#include <iostream>

namespace Huffman {

struct Symbol {
    char c;
    double frequency;

    Symbol(char c, double frequency) : c(c), frequency(frequency) {}
};

class HuffmanCodes {
private:
    struct Node {
        char c;
        double frequency;
        bool isLeaf;
        
        Node *left;
        Node *right;

        Node(char c, double frequency, bool isLeaf) :
            c(c), frequency(frequency), isLeaf(isLeaf), left(nullptr), right(nullptr) {}

        Node(char c, double frequency, bool isLeaf, Node *left, Node *right) :
            c(c), frequency(frequency), isLeaf(isLeaf), left(left), right(right) {}
        
    };

    // Symbol to bit representation
    std::map<char, std::string> table;

    void BuildHuffmanTable(Node *node, std::string &code) {
        if (node->isLeaf) {
            table[node->c] = code;
            return;
        }
        
        code.push_back('0');
        BuildHuffmanTable(node->left, code);
        code.pop_back();

        code.push_back('1');
        BuildHuffmanTable(node->right, code);
        code.pop_back();
    }

    template <typename Container>
    Node *BuildHuffmanTree(const Container &symbols) {
        // Build Alphabet Tree with Heap O(nlogn)
        std::priority_queue<Node *, std::vector<Node *>, std::function<bool(Node *, Node*)>> pq(
            [](Node *a, Node *b) {
                return a->frequency > b->frequency;
            }
        );

        for (auto &symbol : symbols) {
            Node *node = new Node(symbol.c, symbol.frequency, true);
            pq.push(node);
        }

        while (pq.size() > 1) {
            // Get 2 largest trees
            Node *a = pq.top();
            pq.pop();
            Node *b = pq.top();
            pq.pop();
            
            // Combine 2 largest trees
            Node *c = new Node(
                'o', a->frequency + b->frequency, false, a, b
            );

            // Add tree back to heap
            pq.push(c);
        }

        return pq.top();
    }

    void FreeHuffmanTree(Node *node) {
        if (node->isLeaf) {
            delete node;
            return;
        }

        FreeHuffmanTree(node->left);
        FreeHuffmanTree(node->right);
        delete node;
    }

public:
    template <typename Container>
    HuffmanCodes(const Container &symbols) {
        // Symbols' frequencies must add up to 1
        double totalFrequency = 0;

        for (auto &symbol : symbols) {
            totalFrequency += symbol.frequency;
        }

        if ( std::abs(totalFrequency - 1) > 0.0001 ) {
            throw std::runtime_error("Symbols don't add up to 1 frequency");
        }

        if (symbols.size() == 1) {
            table[(*symbols.begin()).c] = "0";
            return;
        }
        
        // Allocate nodes on heap
        Node *tree = BuildHuffmanTree(symbols);

        // Stores codes in table
        std::string code = "";
        BuildHuffmanTable(tree, code);

        // Free tree
        FreeHuffmanTree(tree);
    }

    void PrintHuffmanTable() {
        std::cout << "Huffman Table\n";
        for (auto &p : table) {
            std::cout << (int) p.first << ' ' << p.second << '\n';
        }
    }

    std::map<char, std::string> GetHuffmanTable() {
        return table;
    }

};

}