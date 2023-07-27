

/*
    Problem 15.1 (H) Consider an undirected graph G = (V,E) in
    which every edge e in E has a distinct and nonnegative cost. Let T
    be an MST and P a shortest path from some vertex s to some other
    vertex t. Now suppose the cost of every edge e of G is increased by 1
    and becomes (c sub e) + 1. Call this new graph G'.

    Which of the following is true about G'?
        b. T must be an MST but P may not be a shortest s-t path.
    
    Problem 15.2 (H) Consider the following algorithm that attempts
    to compute an MST of a connected undirected graph G = (V,E)
    with distinct edge costs by running Kruskal’s algorithm “in reverse”:
        Kruskal (Reverse Version)
        1. T := E
        2. sort edges of E in decreasing order of cost
        3. for each e in E, in order do
            a. if T - {e} is connected then
                T := T - {e}
        4. return T

    Which of the following statements is true?
        d. The algorithm always outputs an MST.
    
    Problem 15.3 (H) Which of the following problems reduce, in a
    straightforward way, to the minimum spanning tree problem? (Choose
    all that apply.)
        a. The maximum-cost spanning tree problem.
            - reduces to MST problem with negative edge tree

        b. The minimum-product spanning tree problem.
            - reduces to MST problem

        c. The single-source shortest-path problem. In this problem, the
        input comprises a connected undirected graph G = (V,E), a
        nonnegative length le for each edge e in E, and a designated
        starting vertex s in V . The required output is, for every possible
        destination v in V, the minimum total length of a path from s
        to v.
            - does not reduce to MST problem

        d. Given a connected undirected graph G = (V,E) with positive
        edge costs, compute a minimum-cost set F subset E of edges such
        that the graph (V,E - F) is acyclic.
            - This reduces to computing the maximum-cost spanning tree T
            - F = E - T
            - And the maximum-cost spanning tree reduces to the MST problem

*/

