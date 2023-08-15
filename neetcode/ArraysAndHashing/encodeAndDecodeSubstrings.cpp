#include <string>
#include <vector>

using namespace std;

/*
    Design an algorithm to encode a list of strings to a string. The encoded string is then sent over the network and is decoded back to the original list of strings.

    Machine 1 (sender) has the function:

    string encode(vector<string> strs) {
        // ... your code
        return encoded_string;
    }

    Machine 2 (receiver) has the function:

    vector<string> decode(string s) {
        //... your code
        return strs;
    }

    So Machine 1 does:

    string encoded_string = encode(strs);

    and Machine 2 does:

    vector<string> strs2 = decode(encoded_string);

    strs2 in Machine 2 should be the same as strs in Machine 1.

    Implement the encode and decode methods.

    You are not allowed to solve the problem using any serialize methods (such as eval).
*/

class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        /*
            Encoding is x chars + | + string
            '8|myString'
        */
        string s;
        for (const auto &str : strs) {
            s += to_string(str.size());
            s += '|';
            s += str;
        }
        return s;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> strs;
        
        int i = 0, l = 0;
        int n = s.size();

        while (i < n) {

            while (s[i] != '|') {
                i += 1;
            }
            i += 1;
            
            int size = stoi(s.substr(l, i - l));
            
            strs.push_back(s.substr(i, size));

            i += size;
            l = i;
        }

        return strs;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));