#include <stdlib.h>
#include "test_LinkerPar_reliability.h"

START_TEST (LinkerPar_reliability_x)
{
    int x = 0;
    ck_assert_int_eq(x, 0);
} 
END_TEST

START_TEST (LinkerPar_reliability_y)
{
    int x = 5;
    ck_assert_int_eq(x, 5);
} 
END_TEST

// LinkerPar reliability suite
Suite *LinkerPar_reliability_suite(void) {
    Suite *s;
    TCase *tc_reliability_x, *tc_reliability_y;

    s = suite_create("LinkerPar");

    tc_reliability_x = tcase_create("reliability_x");
    tc_reliability_y = tcase_create("reliability_y");

    tcase_add_test(tc_reliability_x, LinkerPar_reliability_x);
    tcase_add_test(tc_reliability_y, LinkerPar_reliability_y);
    suite_add_tcase(s, tc_reliability_x);
    suite_add_tcase(s, tc_reliability_y);
    
    return s;
}