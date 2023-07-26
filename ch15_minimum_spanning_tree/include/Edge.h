#include <iostream>

struct Edge {
    int a;
    int b;
    int weight;

    Edge(int a, int b, int weight) : a(a), b(b), weight(weight) {}

    bool operator==(const Edge &other) const {
        return ( (a == other.a && b == other.b) || (a == other.b && b == other.a) ) && weight == other.weight;
    }

    bool operator<(const Edge &other) const {
        return weight < other.weight;
    }

    bool operator>(const Edge &other) const {
        return weight > other.weight;
    }

    // Overload << operator to print Edge
    friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
        os << "Edge(" << e.a << ", " << e.b << ", " << e.weight << ")";
        return os;
    }
};

