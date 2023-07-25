#include "HuffmanCodes.h"
#include <fstream>
#include <iostream>
#include <array>
#include <map>
#include <string>


class BitWriter {
private:
    std::ofstream &fout;
    int currentBit;
    unsigned char bitBuffer;

    void WriteBit(bool bit) {
        if (bit) {
            bitBuffer |= (1 << currentBit);
        }

        currentBit += 1;

        if (currentBit == 8) {
            fout << bitBuffer;
            currentBit = 0;
            bitBuffer = 0;
        }
    }

public:
    BitWriter(std::ofstream &fout) :
        fout(fout), currentBit(0), bitBuffer(0) {}
    
    void WriteBitString(const std::string &bits) {
        for (auto &b : bits) {
            if (b == '1') {
                WriteBit(1);
            } else {
                WriteBit(0);
            }
        }
    }

    void FlushBits() {
        while (currentBit) {
            WriteBit(0);
        }
    }
};


int main() {

    std::ifstream fin("input_file.txt", std::ios::binary);
    if (!fin.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    // Count of ASCII characters
    std::array<int, 256> charCount = {0};

    // Read the file byte by byte and update the frequency table
    char byte;
    int totalChars = 0;
    while (fin.read(&byte, sizeof(byte))) {
        charCount[ (unsigned char) byte ] += 1;
        totalChars += 1;
    }

    std::vector<Huffman::Symbol> symbols;
    // Frequency of ASCII characters
    for (int i = 0; i < 256; i++) {
        if (charCount[i] > 0) {
            Huffman::Symbol symbol = Huffman::Symbol(
                i,
                (double) charCount[i] / (double) totalChars
            );

            symbols.push_back(symbol);
        }
    }
    
    // Create Huffman Codes from ASCII characters of file
    Huffman::HuffmanCodes codes = Huffman::HuffmanCodes(symbols);

    codes.PrintHuffmanTable();

    std::map<char, std::string> table = codes.GetHuffmanTable();

    std::ofstream fout("compressed.bin", std::ios::binary);
    BitWriter bitWriter = BitWriter(fout);

    fin.clear();
    fin.seekg(0, std::ios::beg);
    
    while (fin.read(&byte, sizeof(byte))) {
        bitWriter.WriteBitString(table[byte]);
    }
    bitWriter.FlushBits();

    fin.close();
    fout.close();

    return 0;
}