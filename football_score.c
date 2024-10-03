#include <stdio.h>

void findCombinations(int score) {
    int td, fg, safety, td_with_fg, td_with_2pt;

    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);

    for (td = 0; td * 6 <= score; td++) {
        for (fg = 0; td * 6 + fg * 3 <= score; fg++) {
            for (safety = 0; td * 6 + fg * 3 + safety * 2 <= score; safety++) {
                int remaining = score - (td * 6 + fg * 3 + safety * 2);

                if (remaining % 7 == 0) {
                    td_with_fg = remaining / 7;
                    printf("%d TD, %d FG, %d Safety, %d TD + FG\n", td, fg, safety, td_with_fg);
                }
                if (remaining % 8 == 0) {
                    td_with_2pt = remaining / 8;
                    printf("%d TD, %d FG, %d Safety, %d TD + 2pt\n", td, fg, safety, td_with_2pt);
                }
            }
        }
    }
}

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
