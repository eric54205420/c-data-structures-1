#include <stdio.h>
#include <stdlib.h>
#include <check.h>

#include "merkle_tree.h"

/**
 *
 */
START_TEST(test_create)
{
    MerkleTree tree = createMerkleTree();

    ck_assert_ptr_eq(tree.merkleNode->left, NULL);
    ck_assert_ptr_eq(tree.merkleNode->right, NULL);
    ck_assert_int_eq(tree.leavesAmount, 0);
}
END_TEST

/**
 *
 */
START_TEST(test_insert)
{
    MerkleTree tree = createMerkleTree();

    insertMT(&tree, 'A');

    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->hash[19], 0x1B);

    ck_assert_int_eq(tree.merkleNode->data, 'A');
    ck_assert_int_eq(tree.leavesAmount, 1);

    insertMT(&tree, 'B');

    ck_assert_int_eq(tree.merkleNode->data, 0);

    /* TODO: check the merkle node hash */

    ck_assert_int_eq(tree.merkleNode->left->data, 'A');
    ck_assert_ptr_eq(tree.merkleNode->left->left, NULL);
    ck_assert_ptr_eq(tree.merkleNode->left->right, NULL);
    /* expected digest: 6DCD4CE23D88E2EE9568BA546C007C63D9131C1B */
    ck_assert_int_eq(tree.merkleNode->left->hash[0], 0x6D);
    ck_assert_int_eq(tree.merkleNode->left->hash[19], 0x1B);

    ck_assert_int_eq(tree.merkleNode->right->data, 'B');
    ck_assert_ptr_eq(tree.merkleNode->right->left, NULL);
    ck_assert_ptr_eq(tree.merkleNode->right->right, NULL);
    /* expected digest: AE4F281DF5A5D0FF3CAD6371F76D5C29B6D953EC */
    ck_assert_int_eq(tree.merkleNode->right->hash[0], 0xAE);
    ck_assert_int_eq(tree.merkleNode->right->hash[19], 0xEC);

    ck_assert_int_eq(tree.leavesAmount, 2);
}
END_TEST

/**
 *
 */
Suite* merkle_tree_suite()
{
    Suite *suite = suite_create("merkle_tree");
    TCase *tcase = tcase_create("case");

    tcase_add_test(tcase, test_create);
    tcase_add_test(tcase, test_insert);

    suite_add_tcase(suite, tcase);

    return suite;
}

/**
 *
 */
int main(int argc, char *argv[])
{
    Suite *suite = merkle_tree_suite();
    SRunner *runner = srunner_create(suite);

    srunner_run_all(runner, CK_NORMAL);
    int number_failed = srunner_ntests_failed(runner);
    srunner_free(runner);

    return number_failed;
}
