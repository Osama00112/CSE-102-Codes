#include <stdio.h>
#include <string.h>

void printBits(int x)
{
    int i;
    int mask = (1 << 31);
    for (i = 0; i < 32; i++)
    {
        printf("%d", ((x & mask) ? 1 : 0));
        x <<= 1;
    }
    printf("\n");
}

unsigned int encode(int roll, int subject, int score) {
    // TODO: Write appropriate encoding code here.
    return 0;
}

void decode(unsigned int encoded, int *pRoll, int *pSubject, int *pScore) {
    // TODO: Write appropriate decoding code here.
    *pRoll = 0;
    *pSubject = 0;
    *pScore = 0;
}

int main()
{
    int roll, subject, score;
    unsigned int encoded;
    char cmd[10];

    while (1) {
        printf("Enter command: ");
        scanf("%s", cmd);
        if (!strcmp(cmd, "encode")) {
            printf("Roll: ");
            scanf("%d", &roll);
            printf("Subject: ");
            scanf("%d", &subject);
            printf("Score: ");
            scanf("%d", &score);
            encoded = encode(roll, subject, score);
            printf("Encoded value is: %u\n", encoded);
        } else if (!strcmp(cmd, "decode")) {
            printf("Encoded value: ");
            scanf("%u", &encoded);
            decode(encoded, &roll, &subject, &score);
            printf("Roll: %d\nSubject: %d\nScore: %d\n", roll, subject, score);
        } else if (!strcmp(cmd, "quit") || !strcmp(cmd, "exit")) {
            printf("Bye!");
            break;
        } else {
            printf("Unknown command. Try again.\n");
        }
    }

    return 0;
}
