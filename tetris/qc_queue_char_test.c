#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdlib.h>
#include "qc_queue_char.h"


qc_queue_t* queue;

int qc_initialize_tests() {
    queue = qc_queue_init();
    if (queue == NULL) return 1;
    return 0;
}

int qc_cleanup_tests() {
    free(queue);
    return 0;
}

void test_qc_queue_get_size() {
    int size;
    char unused;

    // Empty queue
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 0);

    // Null pointer must return an error 
    size = qc_queue_get_size(NULL);
    CU_ASSERT_EQUAL(size, -1);

    // One element 
    qc_queue_enqueue(queue, 'A');
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 1);

    // Many elements
    qc_queue_enqueue(queue, 'H');
    qc_queue_enqueue(queue, 'u');
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 3);

    // After removing an element
    qc_queue_dequeue(queue, &unused);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 2);

    // After clearing
    qc_queue_clear(queue);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 0);

    return;
}

int main(void) {
    CU_ErrorCode error_code;
    CU_pSuite suite_qc_queue_char;

    error_code = CU_initialize_registry();

    suite_qc_queue_char = CU_add_suite("qc_queue_char",
            &qc_initialize_tests, &qc_cleanup_tests);

    CU_ADD_TEST(suite_qc_queue_char, &test_qc_queue_get_size);

    CU_console_run_tests();

    CU_cleanup_registry();
}

/* Registry ⊂ Suites ⊂ Tests */

/*
 *  Return CUE_SUCCESS or CUE_NOMEMORY
 *  CU_ErrorCode CU_initialize_registry()
 */

/*
 *  CU_pSuite CU_add_suite(
 *      const char* strName,
 *      CU_InitializeFunc pInit,  no args, returns 0 if all ok
 *      CU_CleanupFunc pClean)    no args, returns 0 if all ok
 *
 *   CUE_SUCCESS suite creation was successful
 *   CUE_NOREGISTRY the registry has not been initialized
 *   CUE_NO_SUITENAME strName was NULL
 *   CUE_DUP_SUITE the suite's name was not unique
 *   CUE_NOMEMORY memory allocation failed
 */

/*
 *  CU_pTest CU_add_test(
 *      CU_pSuite pSuite,       Pointer to the suite containing the test
 *      const char* strName,    Name of the test
 *      CU_TestFunc pTestFunc)  No arg, no return value
 *
 *  CU_ADD_TEST(suite, test) create test and add it to the suite
 */

/*
 *  void CU_console_run_tests()
 */

/*
 *  CU_cleanup_registry()
 */
