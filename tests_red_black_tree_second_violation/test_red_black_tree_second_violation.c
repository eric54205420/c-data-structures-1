#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "red_black_tree.h"

/**
 * NOTE: in the following ASCII trees, B and R represents Black and Red
 * The number represents the node itself (in order to follow nodes movement)
 */

/**
 *
 */
START_TEST(test_insert_second_violation)
{
    /**
     * Try to resolve the following violation:
     *
     *     5B
     *     |
     *   ---
     *   |   
     *   2R
     *   |
     *  ---
     *  |
     *  1R
     *
     * to:
     *
     *     2B
     *     |
     *   -----
     *   |   |
     *   1R  5R
     *
     * TODO
     */
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("red_black_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_insert_second_violation);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = linked_list_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
