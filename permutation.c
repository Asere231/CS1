#include <stdio.h>
#include <string.h>

// This permutation does not utilize a swap function
void permute(char *s, int l, int r) {
    if (l == r) {
        printf("%s\n", s);
    } else {
        for (int i = l; i <= r; i++) {
            // Swap characters
            char temp = s[l];
            s[l] = s[i];
            s[i] = temp;
            
            permute(s, l + 1, r); // Recurse
            
            // Restore original order
            temp = s[l];
            s[l] = s[i];
            s[i] = temp;
        }
    }
}

int main() {
    char string[] = "abc";
    int length = strlen(string);
    permute(string, 0, length - 1);
    return 0;
}
