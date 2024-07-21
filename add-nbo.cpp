#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t change(uint32_t n) {
	return ((n & 0xFF000000) >> 24) |
		((n & 0x00FF0000) >> 8) |
		((n & 0x0000FF00) << 8) |
		((n& 0x000000FF) << 24);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Error\n");
        return 0;
    }

    FILE* file1 = fopen(argv[1], "rb");
    FILE* file2 = fopen(argv[2], "rb");

    uint32_t value1 = 0;
    uint32_t value2 = 0;

    size_t read1 = fread(&value1, sizeof(uint32_t), 1, file1);
    size_t read2 = fread(&value2, sizeof(uint32_t), 1, file2);

    fclose(file1);
    fclose(file2);

    value1 = change(value1);
    value2 = change(value2);

    int32_t sum = value1 + value2;

    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value1, value1, value2, value2, sum, sum);

    return 0;
}