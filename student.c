#include <assert.h>
#include "student.h"

static int gpa_comparator(struct ll_node *n1, struct ll_node *n2) {
    double gpa1 = LL_ENTRY(n1, struct student, node)->gpa;
    double gpa2 = LL_ENTRY(n2, struct student, node)->gpa;
    if (gpa1 < gpa2) {
        return -1;
    } else if (gpa2 < gpa1) {
        return 1;
    } else {
        return 0;
    }
}

struct student *student_worst_performer(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return LL_ENTRY(ll_min(&list->node, gpa_comparator), struct student, node);
}

struct student *student_valedictorian(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    return LL_ENTRY(ll_max(&list->node, gpa_comparator), struct student, node);
}

static bool student_on_honor_roll(struct ll_node *n) {
    return LL_ENTRY(n, struct student, node)->gpa >= 3.5;
}

struct student *student_honour_roll(struct student *list) {
    assert(list != NULL);
    // TODO: Implement your solution here.
    struct ll_node *result = ll_filter(&list->node, student_on_honor_roll);
    return (result != NULL) ? LL_ENTRY(result, struct student, node) : NULL;
}
