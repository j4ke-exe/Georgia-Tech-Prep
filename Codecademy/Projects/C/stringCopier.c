#include <stdio.h>
#include <string.h>
#include <stddef.h>

void copy_safe(char* dst, const char* src, size_t dst_size) {
    if (dst == NULL || src == NULL || dst_size == 0) {
        return;
    }
    size_t i = 0;

    while (src[i] != '\0' && i < (dst_size - 1)) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

int main() {
    char srcString[] = "We promptly judged antique ivory buckles for the next prize!";
    char smallDstString[20];
    char largeDstString[sizeof(srcString)];

    printf("Source string: \"%s\" (length %zu)\n\n", srcString, strlen(srcString));

    // --- Test Case 1: Destination buffer is too small ---
    printf("Calling copy_safe with dst size = %zu\n", sizeof(smallDstString));

    copy_safe(smallDstString, srcString, sizeof(smallDstString));

    printf("Small Destination (truncated): \"%s\"\n", smallDstString);
    printf("Length of small Dst: %zu\n\n", strlen(smallDstString));

    // --- Test Case 2: Destination buffer is large enough ---
    printf("Calling copy_safe with dst size = %zu\n", sizeof(largeDstString));

    copy_safe(largeDstString, srcString, sizeof(largeDstString));

    printf("Large Destination (full copy): \"%s\"\n", largeDstString);
    printf("Length of large Dst: %zu\n\n", strlen(largeDstString));

    return 0; 
}
