#include <CUnit/CUnit.h>
#include <CUnit/Console.h>
#include <stdlib.h>
#include "qc_queue_char.h"


qc_queue_t* queue;

static int initialize() {
    queue = qc_queue_init();
    if (queue == NULL) return 1;
    return 0;
}

static int cleanup() {
    free(queue);
    return 0;
}

static void test_queue_get_size() {
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

static void test_queue_enqueue_dequeue() {
    int size;
    int return_code;
    char data;

    // Basic enqueue
    return_code = qc_queue_enqueue(queue, 'A');
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0);
    CU_ASSERT_EQUAL(size, 1);

    // Enqueue with null pointer
    return_code = qc_queue_enqueue(NULL, 'A');
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, -1);
    CU_ASSERT_EQUAL(size, 1);

    // Basic dequeue
    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0);
    CU_ASSERT_EQUAL(data, 'A');
    CU_ASSERT_EQUAL(size, 0);

    // Multiple data
    return_code = qc_queue_enqueue(queue, 'A');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, 'D');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, '+');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, ';');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, ' ');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, '2');
    CU_ASSERT_EQUAL(return_code, 0);
    return_code = qc_queue_enqueue(queue, 'E');
    CU_ASSERT_EQUAL(return_code, 0);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(size, 7);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, 'A');
    CU_ASSERT_EQUAL(size, 6);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, 'D');
    CU_ASSERT_EQUAL(size, 5);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, '+');
    CU_ASSERT_EQUAL(size, 4);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, ';');
    CU_ASSERT_EQUAL(size, 3);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, ' ');
    CU_ASSERT_EQUAL(size, 2);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, '2');
    CU_ASSERT_EQUAL(size, 1);

    return_code = qc_queue_dequeue(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0)
    CU_ASSERT_EQUAL(data, 'E');
    CU_ASSERT_EQUAL(size, 0);
}

static void test_queue_peek() {
    int return_code;
    char data;
    int size;
    
    // Null pointer
    return_code = qc_queue_peek(NULL, &data);
    CU_ASSERT_EQUAL(return_code, -1);
    
    // No data to peek
    return_code = qc_queue_peek(queue, &data);
    CU_ASSERT_EQUAL(return_code, -2);
    
    // Peek with one element
    qc_queue_enqueue(queue, 'A');
    return_code = qc_queue_peek(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0);
    CU_ASSERT_EQUAL(data, 'A');
    CU_ASSERT_EQUAL(size, 1);
    
    // Peek with multiple elements
    qc_queue_enqueue(queue, ' ');
    qc_queue_enqueue(queue, '2');
    qc_queue_enqueue(queue, '?');
    return_code = qc_queue_peek(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0);
    CU_ASSERT_EQUAL(data, 'A');
    CU_ASSERT_EQUAL(size, 4);
    
    // Peek special char
    qc_queue_clear(queue);
    qc_queue_enqueue(queue, '?');
    return_code = qc_queue_peek(queue, &data);
    size = qc_queue_get_size(queue);
    CU_ASSERT_EQUAL(return_code, 0);
    CU_ASSERT_EQUAL(data, '?');
    CU_ASSERT_EQUAL(size, 1);
}

int main(void) {
    CU_pSuite suite_qc_queue_char;

    CU_initialize_registry();

    suite_qc_queue_char = CU_add_suite("qc_queue_char",
            &initialize, &cleanup);

    CU_ADD_TEST(suite_qc_queue_char, &test_queue_get_size);
    CU_ADD_TEST(suite_qc_queue_char, &test_queue_enqueue_dequeue);
    CU_ADD_TEST(suite_qc_queue_char, &test_queue_peek);

    CU_console_run_tests();

    CU_cleanup_registry();
}
