#include <math.h>
#include "test_Array_dbl.h"
#include "../src/Array_dbl.h"

/**
 * @brief Test mean calculation for @p Array_dbl
 * 
 * Check that the mean calculated for an @p Array_dbl object is the same as the
 * mean known for a selection of values: mean({2.0, 6.0, 7.0, 4.0, 9.0}) = 5.6.
 *
 */
START_TEST (array_mean)
{   
    // initalise array
    size_t N = 5;
    double values[] = {2.0, 6.0, 7.0, 4.0, 9.0};
    Array_dbl *array_dbl = Array_dbl_new(N);
    for (size_t i=0; i<N; i++)
    {
        Array_dbl_set(array_dbl, i, values[i]);
    }

    // Assert
    double tol = 0.000001;
    ck_assert(Array_dbl_mean(array_dbl) - 5.6 < tol);
} 
END_TEST

// Array_dbl reliability suite
Suite *Array_dbl_test_suite(void) {
    Suite *s;
    TCase *tc_array_mean;

    // Create test suite
    s = suite_create("Array_dbl");

    // Create test cases
    tc_array_mean = tcase_create("array_mean");

    // Add test cases to test suite
    tcase_add_test(tc_array_mean, array_mean);
    suite_add_tcase(s, tc_array_mean);
    
    return s;
}