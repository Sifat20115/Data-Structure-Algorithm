#include <stdio.h>
#include <string.h>
int main() {
    char str[1000];
    int freq[26] = {0};
    int i, len;
    printf("");
    scanf("%s", str);
    len = strlen(str);
    for(i = 0; i < len; i++) {
        freq[str[i] - 'a']++;
    }
    printf("\n");
    for(i = 0; i < 26; i++) {
        printf("%c - %d\n", i + 'a', freq[i]);
    }

    return 0;
}
