#include <stdio.h>
#include <stdlib.h>

typedef struct Tape
{
    int length;
    int pos;
    int machine;
} Tape;

Tape *cmp1, *cmp2;
int compare(const void *a, const void *b)
{
    cmp1 = (Tape *)a;
    cmp2 = (Tape *)b;

    return cmp2->length - cmp1->length;
}

int main(void)
{
    Tape *tape = NULL;
    int i, n, m = 0, mach;

    setbuf(stdout, NULL);
    printf("Enter the number of tapes : ");
    scanf("%d", &n);
    printf("Enter the number of machines : ");
    scanf("%d", &mach);

    tape = (Tape *)calloc(n, sizeof(Tape));

    printf("Enter the lengths of each tape : \n");
    for (i = 0; i < n; i++)
    {
        printf("Tape %d :", i + 1);
        scanf("%d", &tape[i].length);
        tape[i].pos = i + 1;
    }

    qsort(tape, n, sizeof(Tape), compare);

    for (i = 0; i < n; i++)
    {
        tape[i].machine = m + 1;
        m = (m + 1) % (mach);
    }

    printf("The optimal tape storage is : \n");
    for (i = 0; i < n; i++)
    {
        printf("Tape : %d - Length : %d Machine : %d\n", tape[i].pos, tape[i].length, tape[i].machine);
    }
    return EXIT_SUCCESS;
}
