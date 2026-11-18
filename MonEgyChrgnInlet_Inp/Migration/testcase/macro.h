#ifndef MACRO_H
#define MACRO_H

// Static flags for comparison tracking
static int BCU_g_first_flag  = 1;
static int BCU_g_exists_flag = 0;

// Reset macro - resets flags for new comparison sequence
#define BCU_COMPARE_RESET() \
    do { BCU_g_first_flag = 1; BCU_g_exists_flag = 0; } while (0)

// GET_BIT macro - extracts specific bit from a value
#define GET_BIT(value, bitpos) \
    (((int)(value) >> (bitpos)) & 1)

// BCU_ASSERT_EXISTS - Single macro to verify that exists condition was met
// This is independent of assertion type - just checks if flag was set
#define BCU_ASSERT_EXISTS() \
    BCU_ASSERT_ARE_EQUAL(BCU_g_exists_flag, 1)

// ============================================================================
// BCU_ASSERT_ARE_EQUAL - Integer comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS(actual, expected) \
    BCU_ASSERT_ARE_EQUAL((actual), (expected))

#define BCU_COMPARE_FIRST(actual, expected) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_EQUAL((actual), (expected)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for integer comparison - tracks if condition was ever true
#define BCU_TRACK_EXISTS(actual, expected) \
    do { if ((actual) == (expected)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST(actual, expected) \
    BCU_ASSERT_ARE_EQUAL((actual), (expected))

// ============================================================================
// BCU_ASSERT_ARE_EQUAL_FLOAT - Float comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_FLOAT(actual, expected) \
    BCU_ASSERT_ARE_EQUAL_FLOAT((actual), (expected))

#define BCU_COMPARE_FIRST_FLOAT(actual, expected) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_EQUAL_FLOAT((actual), (expected)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for float comparison (exact equality - may have precision issues)
#define BCU_TRACK_EXISTS_FLOAT(actual, expected) \
    do { if ((actual) == (expected)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_FLOAT(actual, expected) \
    BCU_ASSERT_ARE_EQUAL_FLOAT((actual), (expected))

// ============================================================================
// BCU_ASSERT_ARE_EQUAL_TOL - Integer with tolerance comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_EQUAL_TOL((actual), (expected), (tolerance))

#define BCU_COMPARE_FIRST_TOL(actual, expected, tolerance) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_EQUAL_TOL((actual), (expected), (tolerance)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS with tolerance - tracks if values were within tolerance
#define BCU_TRACK_EXISTS_TOL(actual, expected, tolerance) \
    do { if (abs((int)(actual) - (int)(expected)) <= (tolerance)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_EQUAL_TOL((actual), (expected), (tolerance))

// ============================================================================
// BCU_ASSERT_ARE_EQUAL_FLOAT_TOL - Float with tolerance comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_FLOAT_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_EQUAL_FLOAT_TOL((actual), (expected), (tolerance))

#define BCU_COMPARE_FIRST_FLOAT_TOL(actual, expected, tolerance) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_EQUAL_FLOAT_TOL((actual), (expected), (tolerance)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for float with tolerance - tracks if values were within tolerance
#define BCU_TRACK_EXISTS_FLOAT_TOL(actual, expected, tolerance) \
    do { if (fabs((actual) - (expected)) <= (tolerance)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_FLOAT_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_EQUAL_FLOAT_TOL((actual), (expected), (tolerance))

// ============================================================================
// BCU_ASSERT_ARE_NOT_EQUAL - Integer not-equal comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_NOT_EQUAL(actual, expected) \
    BCU_ASSERT_ARE_NOT_EQUAL((actual), (expected))

#define BCU_COMPARE_FIRST_NOT_EQUAL(actual, expected) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_NOT_EQUAL((actual), (expected)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for not-equal - tracks if values were ever not equal
#define BCU_TRACK_EXISTS_NOT_EQUAL(actual, expected) \
    do { if ((actual) != (expected)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_NOT_EQUAL(actual, expected) \
    BCU_ASSERT_ARE_NOT_EQUAL((actual), (expected))

// ============================================================================
// BCU_ASSERT_ARE_NOT_EQUAL_FLOAT - Float not-equal comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_NOT_EQUAL_FLOAT(actual, expected) \
    BCU_ASSERT_ARE_NOT_EQUAL_FLOAT((actual), (expected))

#define BCU_COMPARE_FIRST_NOT_EQUAL_FLOAT(actual, expected) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_NOT_EQUAL_FLOAT((actual), (expected)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for float not-equal - tracks if values were ever not equal
#define BCU_TRACK_EXISTS_NOT_EQUAL_FLOAT(actual, expected) \
    do { if ((actual) != (expected)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_NOT_EQUAL_FLOAT(actual, expected) \
    BCU_ASSERT_ARE_NOT_EQUAL_FLOAT((actual), (expected))

// ============================================================================
// BCU_ASSERT_ARE_NOT_EQUAL_TOL - Integer not-equal with tolerance macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_NOT_EQUAL_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_NOT_EQUAL_TOL((actual), (expected), (tolerance))

#define BCU_COMPARE_FIRST_NOT_EQUAL_TOL(actual, expected, tolerance) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_NOT_EQUAL_TOL((actual), (expected), (tolerance)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for not-equal with tolerance - tracks if difference exceeded tolerance
#define BCU_TRACK_EXISTS_NOT_EQUAL_TOL(actual, expected, tolerance) \
    do { if (abs((int)(actual) - (int)(expected)) > (tolerance)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_NOT_EQUAL_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_NOT_EQUAL_TOL((actual), (expected), (tolerance))

// ============================================================================
// BCU_ASSERT_ARE_NOT_EQUAL_FLOAT_TOL - Float not-equal with tolerance macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_NOT_EQUAL_FLOAT_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_NOT_EQUAL_FLOAT_TOL((actual), (expected), (tolerance))

#define BCU_COMPARE_FIRST_NOT_EQUAL_FLOAT_TOL(actual, expected, tolerance) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_NOT_EQUAL_FLOAT_TOL((actual), (expected), (tolerance)); BCU_g_first_flag = 0; } } while (0)

// BCU_TRACK_EXISTS for float not-equal with tolerance - tracks if difference exceeded tolerance
#define BCU_TRACK_EXISTS_NOT_EQUAL_FLOAT_TOL(actual, expected, tolerance) \
    do { if (fabs((actual) - (expected)) > (tolerance)) { BCU_g_exists_flag = 1; } } while (0)

#define BCU_COMPARE_LAST_NOT_EQUAL_FLOAT_TOL(actual, expected, tolerance) \
    BCU_ASSERT_ARE_NOT_EQUAL_FLOAT_TOL((actual), (expected), (tolerance))

// ============================================================================
// BCU_ASSERT_ARE_EQUAL_ARRAY - Array comparison macros
// NOTE: Array comparisons are typically used for always/last only
// ============================================================================

#define BCU_COMPARE_ALWAYS_ARRAY(actual_array, expected_array, size) \
    BCU_ASSERT_ARE_EQUAL_ARRAY((actual_array), (expected_array), (size))

#define BCU_COMPARE_FIRST_ARRAY(actual_array, expected_array, size) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_EQUAL_ARRAY((actual_array), (expected_array), (size)); BCU_g_first_flag = 0; } } while (0)

#define BCU_COMPARE_LAST_ARRAY(actual_array, expected_array, size) \
    BCU_ASSERT_ARE_EQUAL_ARRAY((actual_array), (expected_array), (size))

// ============================================================================
// BCU_ASSERT_ARE_NOT_EQUAL_ARRAY - Array not-equal comparison macros
// ============================================================================

#define BCU_COMPARE_ALWAYS_NOT_EQUAL_ARRAY(actual_array, expected_array, size) \
    BCU_ASSERT_ARE_NOT_EQUAL_ARRAY((actual_array), (expected_array), (size))

#define BCU_COMPARE_FIRST_NOT_EQUAL_ARRAY(actual_array, expected_array, size) \
    do { if (BCU_g_first_flag) { BCU_ASSERT_ARE_NOT_EQUAL_ARRAY((actual_array), (expected_array), (size)); BCU_g_first_flag = 0; } } while (0)

#define BCU_COMPARE_LAST_NOT_EQUAL_ARRAY(actual_array, expected_array, size) \
    BCU_ASSERT_ARE_NOT_EQUAL_ARRAY((actual_array), (expected_array), (size))

#define BCU_TRACK_EXISTS_ARRAY(actual_array, expected_array, size) \
    do { int _i; for (_i = 0; _i < (size); _i++) { if ((actual_array)[_i] == (expected_array)[_i]) { BCU_g_exists_flag = 1; break; } } } while (0)

#endif // MACRO_H
