
#include <stddef.h>
#include <stdio.h>
#include <stdalign.h>
#include <stdbit.h>

struct ModernC {
    int value;
    char array[10];
    char index;
};

int main() {
    size_t res=10;
    printf("%u\n", stdc_bit_width(res));
    printf("%u\n", stdc_has_single_bit(res));
    printf("%u\n", stdc_count_ones(res));
    printf("%zu\n", stdc_bit_floor(res));
    printf("%zu\n", offsetof(struct ModernC, value));
    printf("%zu\n", offsetof(struct ModernC, array));
    printf("%zu\n", alignof(struct ModernC));
    return 0;
}