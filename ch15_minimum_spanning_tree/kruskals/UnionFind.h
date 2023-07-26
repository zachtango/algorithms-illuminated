#include <stdexcept>

class UnionFind {
private:
    int *parent;
    int *size;
    int n;

public:
    UnionFind(int n) : parent(new int[n]), size(new int[n]), n(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 0;
        }
    }

    int Find(int i) {
        if (i >= n) {
            throw std::runtime_error("i out of range");
        }

        while (parent[i] != i) {
            i = parent[i];
        }

        return i;
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        
        if (size[x] >= size[y]) {
            parent[y] = x;
            size[x] += size[y];
        } else {
            parent[x] = y;
            size[y] += size[x];
        }
    }
};

