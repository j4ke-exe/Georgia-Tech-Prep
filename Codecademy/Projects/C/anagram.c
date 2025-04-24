#include<stdio.h>
#include<string.h>

int main() {
    int counter1[] = {0, 0, 0, 0};
    int counter2[] = {0, 0, 0, 0};
    char s1[] = "dbb cccccaacb cdbababdcdcdab dcdad";
    char s2[] = "bbbcc bdddccccad cdbbaaacaccdabdd";
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int flag = 1; // Initialize flag assuming an anagram (based on final print logic)

    for (int i = 0; i < len1; i++) {
        if (s1[i] == ' ') {
            continue;
        } else if (s1[i] == 'a') {
            counter1[0]++;
        } else if (s1[i] == 'b') {
            counter1[1]++;
        } else if (s1[i] == 'c') {
            counter1[2]++;
        } else if (s1[i] == 'd') {
            counter1[3]++;
        }
    }

    for (int i = 0; i < len2; i++) {
        if (s2[i] == ' ') {
            continue;
        } else if (s2[i] == 'a') {
            counter2[0]++;
        } else if (s2[i] == 'b') {
            counter2[1]++;
        } else if (s2[i] == 'c') {
            counter2[2]++;
        } else if (s2[i] == 'd') {
            counter2[3]++;
        }
    }

    for (int i = 0; i < 4; i++) {
        if (counter1[i] != counter2[i]) {
            flag = 0; // Found mismatch, set flag to indicate "Not Anagram!"
        } else {
            flag = 1;  // Found match, set flag to indicate "Anagram!"
        }
    }

    if (flag == 1) { // flag is 1 if no mismatch was found
        printf("Anagram!");
    } else { // flag is 0 if a mismatch was found
        printf("Not Anagram!");
    }
    printf("\n");

    return 0;
}
