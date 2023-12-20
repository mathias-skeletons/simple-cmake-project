//
// Created by Mathias Santos de Brito on 19.12.23.
//

#include "check.h"
#include "ex1.h"
#include "../include/ex1_test.h"

START_TEST(ex1_test) {
    fail_if(sum(1,2) != 3);
}
END_TEST

Suite* ex1_test_suite(void) {
    Suite* suite = suite_create("Ex1Tests");
    TCase* tc_arithimetic = tcase_create("ArithmeticTests");

    tcase_add_test(tc_arithimetic, ex1_test);
    suite_add_tcase(suite, tc_arithimetic);

    return suite;
}

int main(void) {
    int number_failed;

    Suite* ex1_suite = ex1_test_suite();
    SRunner* runner = srunner_create(ex1_suite);

    srunner_run_all(runner, CK_NORMAL);
    number_failed = srunner_ntests_failed(runner);

    return (number_failed == 0) ?  0 : 1;
}

