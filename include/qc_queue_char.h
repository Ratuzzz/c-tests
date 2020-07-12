#ifndef QC_QUEUE_CHAR_H
#define QC_QUEUE_CHAR_H

typedef struct qc_node_t {
    char data;
    struct qc_node_t *next;
} qc_node_t;

typedef struct qc_queue_t {
    qc_node_t *first;
    qc_node_t *last;
    int size;
} qc_queue_t;

/*
 * Init a new queue, NULL is returned if an error occured during memory
 * allocation.
 */
qc_queue_t* qc_queue_init();

/*
 * Return the number of elements in 'queue'.
 * Return code : 
 *     -1, error queue null pointer
 */
int qc_queue_get_size(const qc_queue_t* p_queue);

/*
 * Add an element to 'queue'.
 * Return code :
 *      0, success
 *     -1, queue null pointer
 *     -2, memory allocation error
 */
int qc_queue_enqueue(qc_queue_t* p_queue, char data);

/*
 * Remove the first element of 'queue', its data is stored in 'data'
 * Return code :
 *      0, success
 *     -1, queue null pointer
 *     -2, no data to dequeue
 */
int qc_queue_dequeue(qc_queue_t* p_queue, char* data);

/*
 * Stores the data from the first element of 'queue' in 'data'
 * Return code :
 *      0, success
 *     -1, queue null pointer
 *     -2, no data to peek
 */
int qc_queue_peek(qc_queue_t* p_queue, char* data);

/*
 * Removes all data from 'queue'
 * Return code :
 *      0, success
 *     -1, queue null pointer
 */
int qc_queue_clear(qc_queue_t* p_queue);

#endif /* If define QC_QUEUE_CHAR_H */
