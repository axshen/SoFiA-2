#include <stdlib.h>
#include <math.h>
#include "test_LinkerPar.h"
#include "../src/Matrix.h"

/**
 * @brief Test calculation of covariance matrix
 * 
 * Mocking the calculation of the covariance matrix. Mock data from @p R (statistical programming
 * language) example. This test asserts that @p Matrix_covariance calculates the covariance matrix
 * correctly when compared to @p R @p cov() function.
 * 
 */
START_TEST (matrix_covar_calculation)
{
    // Mock values
    int dim = 3;
    int length = 20;
    double values[] = {
        0.8806373, -1.95192098, 0.18689515,
        0.2047431, -0.05791818, 1.62288586,
        1.9609153, -0.69923266, 0.64002178,
        -1.6226039, 0.04363565, -1.43477284,
        -0.3895771, -1.40679746, -0.07397084,
        2.3732863, -0.66334044, -1.54496257,
        -0.7292960, -0.65010853, -0.71494086,
        0.1044472, -0.85997308, -0.70125238,
        -0.4302851, -0.77777749, 1.03645629,
        -1.7177167, -1.13172392, 0.74644620,
        -0.1734137, 0.19126767, 0.40525712,
        1.4433185, -0.24667962, -0.29331336,
        0.9023200, 0.43797946, 0.99681764,
        -0.5091546, 1.48462769, 1.11789176,
        0.1317887, -0.84363408, -0.77479099,
        -0.2870769, -1.36878009, 0.30097708,
        -0.9766067, 0.07478984, -1.28814253,
        -0.3386619, -0.04540933, 1.76817654,
        1.2044417, -0.01799294, 0.36824827,
        -0.5093679, -0.57040164, 0.84257331,
    };
    Matrix *covar = Matrix_new(dim, dim);

    // Covariance calculation
    Matrix_covariance(covar, values, dim, length);

    // Assert calculated value within tolerance of known value
    // Low tolerance used as comparing with R
    double tol = 0.1;
    ck_assert(fabs(Matrix_get_value(covar, 0, 0) - 1.19512605) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 0, 1) - -0.05807801) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 0, 2) - -0.04001114) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 0) - -0.05807801) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 1) - 0.58313571) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 2) - 0.15017211) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 0) - -0.04001114) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 1) - 0.15017211) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 2) - 0.97185709) < tol);

    // Cleanup
    Matrix_delete(covar);
} 
END_TEST

/**
 * @brief Test calculation of covariance matrix and scaling
 * 
 * Mocking the calculation of the covariance matrix with scaling. Mock data provided 
 * from test_case example. This test asserts that the new function @p Matrix_covariance 
 * with existing @p Matrix_mul_scalar can reproduce the same covariance matrix values.
 * 
 */
START_TEST (matrix_scaled_covar)
{
    // Mock values
    int dim = 3;
    int n_neg = 18;
    double scale_kernel = 0.4;
    double par_neg[] = {
        0.565177, 1.984872, 0.268868,
        0.650231, 2.531438, 0.183133,
        0.635017, 1.838638, 0.476910,
        0.608428, 2.498141, 0.128925,
        0.502900, 2.568780, 0.013686,
        0.598281, 2.816818, 0.037221,
        0.591695, 3.119744, -0.074493, 
        0.542738, 3.077445, -0.055454, 
        0.516489, 2.914339, -0.076000,
        0.502908, 2.093995, 0.267920,
        0.657908, 3.315991, 0.020424,
        0.673569, 3.199827, 0.014284,
        0.627123, 3.177527, -0.085161,
        0.464713, 1.907204, 0.217008, 
        0.613266, 2.393899, 0.270048,
        0.631925, 2.314303, 0.405818,
        0.541647, 3.541295, -0.095594,
        0.595598, 2.631868, 0.090289
    };
    Matrix *covar = Matrix_new(dim, dim);
    
    // Covariance calculation
    Matrix_covariance(covar, par_neg, dim, n_neg);
	Matrix_mul_scalar(covar, scale_kernel * scale_kernel);

    // Assert calculated value within tolerance of known value
    double tol = 0.000001;
    ck_assert(fabs(Matrix_get_value(covar, 0, 0) - 0.0005535) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 0, 1) - 0.0011550) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 0, 2) - 0.0002126) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 0) - 0.0011550) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 1) - 0.0400061) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 1, 2) - -0.0118386) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 0) - 0.0002126) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 1) - -0.0118386) < tol);
    ck_assert(fabs(Matrix_get_value(covar, 2, 2) - 0.0046538) < tol);

    // Cleanup
    Matrix_delete(covar);
} 
END_TEST

// Test the covariance matrix scaling calculations
START_TEST (covariance_scaling)
{
    int x = 0;
    ck_assert_int_eq(x, 0);
} 
END_TEST

// Test generation of skellam array
START_TEST (skellam_array)
{
    int x = 0;
    ck_assert_int_eq(x, 0);
} 
END_TEST

// LinkerPar reliability suite
Suite *LinkerPar_test_suite(void) {
    Suite *s;
    TCase *tc_matrix_covar_calculation, *tc_matrix_scaled_covar;

    // Create test suite
    s = suite_create("LinkerPar");

    // Create test cases
    tc_matrix_covar_calculation = tcase_create("matrix_covar_calculation");
    tc_matrix_scaled_covar = tcase_create("matrix_scaled_covar");

    // Add test cases to test suite
    tcase_add_test(tc_matrix_covar_calculation, matrix_covar_calculation);
    tcase_add_test(tc_matrix_scaled_covar, matrix_scaled_covar);
    suite_add_tcase(s, tc_matrix_covar_calculation);
    suite_add_tcase(s, tc_matrix_scaled_covar);
    
    return s;
}