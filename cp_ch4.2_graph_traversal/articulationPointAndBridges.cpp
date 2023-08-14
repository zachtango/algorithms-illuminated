#include <iostream>
using std::cout;
using std::cin;

/*
    Given road map (undirected graph) with sabotage costs associated
        with all intersections and roads, sabotage either a single
        intersection or a single road such that the road network breaks down
        in the least cost way
    Reduces to finding least cost articulation point or least cost bridge

    Graph without any articulation point is a Biconnected graph

    Usually defined for undirected graphs and are more challenging for directed graphs

    Can use DFS variant (rather than naive algorithm) to find in O(V + E)

    2 More attributes: dfsNum and dfsLow
    - dfsNum stores iteration counter when vertex u is visited for first time
    R is the set of vertices in the DFS spanning subtree rooted at u
    - dfsLow stores lowest dfsNum in R or the lowest dfsNum of a vertex not in R
        reachable by a back edge from a vertex in R
    
    We are at vertex u with v as its neighbor
    (Special case is u is the root, then this isn't applicable)
        - if root has more than one child, it's an articulation point
    - dfsLow(v) >= dfsNum(u)
    - u is an articulation vertex because dfsLow(v) not smaller
        than dfsNum(u) implies no back edge from vertex in subtree rooted at v,
        which implies there is no back edge from a vertex in subtree rooted at v
            that can reach another vertex w w/ a lower dfsNum(w) than dfsNum(u)
    - dfsLow(v) > dfsNum(u)
        then edge (u, v) is a bridge


*/





