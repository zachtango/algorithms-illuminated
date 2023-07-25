


/*
    These questions are NOT GPT generated, they were provided at the end of the chapter

    Problem 14.1 (S) Consider the following symbol frequencies for a five-symbol alphabet:
        Symbol  Frequency
        A       .32 00
        B       .25 01
        C       .20 10
        D       .18 110
        E       .05 111

         o
       /   \
      o     o
     / \   / \ 
    A   B C   o
             / \
            D   E

    What is the average encoding length of an optimal prefix-free code?
        a. 2.23
    
    Problem 14.2 (S) Consider the following symbol frequencies for a
    five-symbol alphabet:
        Symbol  Frequency
        A       .16 110
        B       .08 1110
        C       .35 0
        D       .07 1111
        E       .34 10

            o
           / \
          C   o
             / \
            E   o
               / \
              A   o
                 / \
                B   D

    What is the average encoding length of an optimal prefix-free code?
        a. 2.11

    Problem 14.3 (H) What is the maximum number of bits that Huffman’s greedy algorithm might use to encode a single symbol? (As
    usual, n = |sigma| denotes the alphabet size.)
        c. n - 1
    
    Problem 14.4 (H) Which of the following statements about Huffman’s greedy algorithm are true? Assume that the symbol frequencies
    sum to 1. (Choose all that apply.)
        b. A letter with frequency at least 0.5 will never be encoded with
        two or more bits.
    
    Challenge Problems
        Problem 14.5 (S) Give an implementation of Huffman’s greedy
        algorithm that uses a single invocation of a sorting subroutine, followed
        by a linear amount of additional work.

    Programming Problems
        Problem 14.6 Implement in your favorite programming language
        the Huffman algorithm from Section 14.3 for the optimal prefix-free
        code problem. How much faster is the heap-based implementation (outlined in footnote 8)
        than the straightforward quadratic-time implementation?
        How much faster is the implementation in Problem 14.5 than
        the heap-based implementation? (See www.algorithmsilluminated.
        org for test cases and challenge data sets.)
*/