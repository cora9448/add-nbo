#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#define MAX_OUTPUT_SIZE 10

int main(int argc, char **argv) {
    FILE *input1;
    FILE *input2;
    uint32_t output1, output2;
    char str1[MAX_OUTPUT_SIZE];  
    char str2[MAX_OUTPUT_SIZE];
    
    if ((input1 = fopen(argv[1], "rb")) == NULL) {
        exit(0);
    }
    
    if ((input2 = fopen(argv[2], "rb")) == NULL) {
        exit(0);
    }
    
    int  output1_len = 0;  
    int  output2_len = 0;
    int  typecasting1 = 0;
    int  typecasting2 = 0;
    uint32_t  sum1 = 0;
    uint32_t  sum2 = 0;
    uint32_t p1;
    uint32_t p2;
    
    
    while ((output1 = fgetc(input1)) != EOF) {
        output1_len += sprintf(str1 + output1_len, "%x", output1); 
    }
    
    while ((output2 = fgetc(input2)) != EOF) {
        output2_len += sprintf(str2 + output2_len, "%x", output2);
    }
    sscanf(str1,"%x",&sum1);
    sscanf(str2,"%x",&sum2);

    
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n",sum1,sum1,sum2,sum2,sum1+sum2,sum1+sum2);
    
    fclose(input1);
    fclose(input2);
    return 0;
}

