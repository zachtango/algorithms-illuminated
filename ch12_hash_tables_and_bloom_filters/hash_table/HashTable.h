#include <list>
#include <exception>

/*
    h(k) = (a * k + b) mod n
    
    Separate Chaining
*/
template <typename T>
class HashTable {
private:
    struct Node {
        int k;
        T val;
        Node(int k, T &val) : k(k), val(val) {}
    };

    int a, b, n;
    int size;
    std::list<Node> *A;

    int _Hash(int k) {
        return (a * k + b) % n;
    }

    void _Reallocate() {
        int newN = n * 2;

        std::list<Node> *newA = new std::list<Node>[newN];

        for (int i = 0; i < n; i++) {
            for (auto &e : A[i]) {
                newA[_Hash(e.k)].push_front(e);
            }
        }

        delete[] A;

        A = newA;
        n = newN;
    }

public:

    HashTable() :
        a(5), b(7), n(51), size(0), A(new std::list<Node>[51]) {}
    
    void Insert(int k, T obj) {
        auto &bucket = A[_Hash(k)];
        bucket.push_front(Node(k, obj));

        size += 1;

        double load = (double) size / (double) n;
        
        if (load > 0.7) {
            _Reallocate();
        }
    }

    void Delete(int k) {
        auto &bucket = A[_Hash(k)];
        auto it = bucket.begin();

        while (it != bucket.end()) {
            if (it->k == k) {
                bucket.erase(it);
                break;
            }
            it++;
        }

        size -= 1;
    }

    T &Search(int k) {
        auto &bucket = A[_Hash(k)];
        auto it = bucket.begin();

        while (it != bucket.end()) {
            if (it->k == k) {
                return it->val;
            }
            it++;
        }

        throw std::runtime_error("Key does not exist in hash map");
    }

};

