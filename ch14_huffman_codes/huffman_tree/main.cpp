#include "HuffmanCodes.h"
#include <string>

int main() {
    std::string symbols = "ABCDEF";

    HuffmanCodes codes {
        {'A', 0.5},
        {'B', 0.2},
        {'C', 0.1},
        {'D', 0.1},
        {'E', 0.05},
        {'F', 0.05}
    };

    /*
        o
       / \  
      A   o
        /   \
       B     o
           /   \ 
          o     o
         / \   / \
        C   D E   F
    */

    codes.PrintHuffmanTable();

    

    return 0;
}
