#include <stdio.h>

int main() {
    int score;

    while (1) {
        printf("Enter NFL score (enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        if (score < 2) {
            break;
        }

        findCombinations(score);
    }

    return 0;
}

void findCombinations(int score) {
}