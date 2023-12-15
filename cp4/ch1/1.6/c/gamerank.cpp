#include <iostream>


int main() {
    /*
        player win --> gains star
        player rank 6 - 25 before the game, and third or more consecutive win --> additional star
        when have all stars for next rank and gains additional star, ranks up and has one star on new rank

        rank 1 - 20 loses gain --> loses star
        if zero stars on a rank and loses a star, loses rank and have all stars -1 on rank below
        can never drop below rank 20 (losing game with no stars at rank 20 has no effect)

        25 - 21: 2 stars
        20 - 16: 3 stars
        15 - 11: 4 stars
        10 - 1: 5 stars

        track stars and rank and simulate
    */

    int stars = 0;
    int rank = 25;
    int streak = 0;

    char result;
    while (std::cin >> result) {
        if (result == 'W') {
            streak += 1;
            stars += 1;
            if (rank >= 6 && rank <= 25 && streak >= 3) {
                stars += 1;
            }
            if (rank >= 21 && rank <= 25 && stars >= 3) {
                stars -= 2;
                rank -= 1;
            } else if (rank >= 16 && rank <= 20 && stars >= 4) {
                stars -= 3;
                rank -= 1;
            } else if (rank >= 11 && rank <= 15 && stars >= 5) {
                stars -= 4;
                rank -= 1;
            } else if (rank >= 1 && rank <= 10 && stars >= 6) {
                stars -= 5;
                rank -= 1;
            }
        } else {
            streak = 0;
            if (rank >= 1 && rank <= 20 && !(rank == 20 && stars == 0)) {
                stars -= 1;
                if (stars == -1) {
                    rank += 1;
                    if (rank >= 1 && rank <= 10) {
                        stars = 4;
                    } else if (rank >= 11 && rank <= 15) {
                        stars = 3;
                    } else if (rank >= 16 && rank <= 20) {
                        stars = 2;
                    }
                }
            }
        }
        // std::cout << "rank: " << rank << '\n' << "stars: " << stars << '\n' << "streak: " << streak << '\n';
    }

    if (rank == 0) {
        std::cout << "Legend" << '\n';
    } else {
        std::cout << rank << '\n';
    }

    
    return 0;
}