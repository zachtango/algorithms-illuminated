/*
    Problem 16.1 (S) Consider the input path graph
        5 - 3 - 1 - 7 - 2 - 4 - 6
        where vertices are labeled with their weights. What are the final array
        entries of the WIS algorithm from Section 16.2, and which vertices
        belong to the MWIS?
        array: [0, 5, 5, 6, 12, 12, 16, 18]
        vertices: [5, , 7, 6]

    Problem 16.2 (H) Which of the following statements hold? (Choose
    all that apply.)
        d. If a vertex v does not belong to an MWIS of Gi - 1 or Gi, it does
            not belong to any MWIS of Gi+1, Gi+2,...,Gn either.

    Problem 16.3 (H) This problem outlines an approach to solving
    the WIS problem in graphs more complicated than paths. Consider
    an arbitrary undirected graph G = (V,E) with nonnegative vertex
    weights, and an arbitrary vertex v in V with weight wv. Obtain H
    from G by removing v and its incident edges from G. Obtain K
    from H by removing v’s neighbors and their incident edges:
        Let WG, WH, and WK denote the total weight of an MWIS in G, H,
        and K, respectively, and consider the formula
            WG = max{WH, WK + wv}.
            
        Which of the following statements are true? (Choose all that apply.)
        d) The formula is always correct in arbitrary graphs.
        e) The formula leads to a linear-time algorithm for the WIS problem in trees.
        f) The formula leads to a linear-time algorithm for the WIS problem in arbitrary graphs.

    Problem 16.4 (S) Consider an instance of the knapsack problem
    with five items:
        Item    Value   Size
        1       1       1
        2       2       3
        3       3       2
        4       4       5
        5       5       4
    and knapsack capacity C = 9. What are the final array entries of the
    Knapsack algorithm from Section 16.5, and which items belong to the
    optimal solution? 
              1  2  3  4  5  6  7  8  9
          1 [ 1, 1, 1, 1, 1, 1, 1, 1, 1 ]
          2 [ 1, 1, 2, 3, 3, 3, 3, 3, 3 ]
          3 [ 1, 3, 4, 4, 5, 6, 6, 6, 6 ]
          4 [ 1, 3, 4, 4, 5, 6, 7, 8, 8 ]
          5 [ 1, 3, 4, 5, 6, 8, 9, 9, 10 ]

*/