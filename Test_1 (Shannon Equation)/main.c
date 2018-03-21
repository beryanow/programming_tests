#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double implementation(char *str) {

    double table[256];
    for (int i = 0; i < 256; i++) {
        table[i] = 0;
    }

    long int len = strlen(str);
    for (int i = 0; i < len; i++) {
        table[(int)str[i]]++;
    }

    double sum = 0;
    for (int i = 0; i < 256; i++) {
        if (table[i] > 0) {
            double temp_res = table[i] / len;
            sum += (temp_res) * (log(temp_res) / log(2.0));
        }
    }

    if (sum == 0) return sum;
    return -sum * len;
}

int main(int argc, char *argv[]) {

    if (argc == 1) {

        FILE *infile = fopen("test.txt", "rb");
        FILE *outfile = fopen("out.txt", "wb");

        if ((infile == NULL) || (outfile == NULL)) {
            printf("There is no \"test.txt\" file\n");
            return 0;
        }

        fseek(infile, 0, SEEK_END);
        long int file_size = ftell(infile);
        rewind(infile);

        char *main_string;
        main_string = (char *)calloc(sizeof(char), file_size + 1);
        fread(main_string, sizeof(char), file_size, infile);

        fprintf(outfile, "%f", implementation(main_string));

    }
    else
        printf("%f", implementation(argv[1]));

    return 0;
}