#include <stdio.h>


int main(){
    // 1 - DECLARING AN ARRAY AND POINTER
    int a[5] = {1, 2, 3, 4, 5};
    int *p;
    p = a; 
    // could be 'p = &a' because 'a == &a'
    // printf("%u, %u", a, &a);

    // 2 - WAYS TO ACCESS THE VALUES USING a
    printf("\nARRAY\n");
    printf("Value at %u is %d\n", a, *a);
    printf("Value at %u is %d\n", (a + 1), *(a + 1)); // a + 1 == (a + 1)
    printf("Value at %u is %d\n", (a + 2), *(a + 2));
    printf("Value at %u is %d\n", &a[4], a[4]);
    printf("Value at %u is %d\n", &3[a], 3[a]);

    // 3 - WAYS TO ACCESS THE VALUES USING p
    printf("\nPOINTER\n");
    printf("Value at %u is %d\n", p, *p);
    printf("Value at %u is %d\n", (p + 1), *(p + 1)); // p + 1 == (p + 1)
    printf("Value at %u is %d\n", (p + 2), *(p + 2));
    printf("Value at %u is %d\n", &p[3], p[3]);
    printf("Value at %u is %d\n", &4[p], 4[p]);

    // 3 - MODIFYING VALUES
    // a - Using array
    a[0] = a[0] * 2;
    *(a + 1) = *(a + 1) * 2;
    2[a] = 2[a] * 2;
    *(3 + a) = a[3] * 2;
    a[4] = (*a + 3) * 2;

    printf("\nUsing ARRAY\n");
    printf("The New Value at %u is %d\n", a, *a);
    printf("The New Value at %u is %d\n", (a + 1), *(a + 1));
    printf("The New Value at %u is %d\n", &a[2], a[2]);
    printf("The New Value at %u is %d\n", &3[a], 3[a]);
    printf("The New Value at %u is %d\n", (a + 4), *(a + 4));

    // b - Using Pointer
    p[0] = p[0] / 2;
    *(p + 1) = *(p + 1) / 2;
    2[p] = 2[p] / 2;
    *(3 + p) = p[3] / 2;
    p[4] = (*p + 3) / 2;

    printf("\nUsing POINTER\n");
    printf("The New Value at %u is %d\n", p, *p);
    printf("The New Value at %u is %d\n", (p + 1), *(p + 1));
    printf("The New Value at %u is %d\n", &p[2], p[2]);
    printf("The New Value at %u is %d\n", &3[p], 3[p]);
    printf("The New Value at %u is %d\n", (p + 4), *(p + 4));

    return 0;
}