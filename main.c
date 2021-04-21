#include "includes/utils.h"

int     main()
{
    t_stack *a, *b;

    a = NULL;
    b = NULL;

    push(&a, 4);
    push(&a, 8);
    push(&a, 1);
    push(&a, 6);
    push(&a, 2);

    push_b(&a, &b);
    push_b(&a, &b);

    print_stack(b);
    print_stack(a);
    reverse_rotate_r(&a, &b);
    print_stack(a);
    print_stack(b);
    return 0;
}