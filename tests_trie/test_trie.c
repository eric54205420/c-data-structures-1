#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "trie.h"

/**
 *
 */
START_TEST(test_create)
{
    TrieNode* trie = create("hello");
}
END_TEST

/**
 *
 */
START_TEST(test_keyExists)
{
    TrieNode* first_trie = create("hello");
    ck_assert_int_eq(keyExists(first_trie, "hello"), 1);

    TrieNode* second_trie = create("hello");
    ck_assert_int_eq(keyExists(second_trie, "bonjour"), 0);

    TrieNode* third_trie = create("hello");
    ck_assert_int_eq(keyExists(third_trie, "hell"), 0);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    TrieNode* first_trie = create("hello");
    insert(first_trie, "bonjour");
    insert(first_trie, "bonsoir");
    insert(first_trie, "bon");

    ck_assert_int_eq(keyExists(first_trie, "hello"), 1);
    ck_assert_int_eq(keyExists(first_trie, "bonjour"), 1);
    ck_assert_int_eq(keyExists(first_trie, "bonsoir"), 1);
    ck_assert_int_eq(keyExists(first_trie, "bon"), 1);

    ck_assert_int_eq(keyExists(first_trie, "bo"), 0);
    ck_assert_int_eq(keyExists(first_trie, "bons"), 0);
}
END_TEST

/**
 *
 */
Suite* linked_list_suite()
{
    Suite *suite = suite_create("trie");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_keyExists);
    tcase_add_test(tcase, test_insert);

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
