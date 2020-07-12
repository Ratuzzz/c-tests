#include <stdlib.h>
#include "qc_queue_char.h"

qc_queue_t* qc_queue_init() {
   qc_queue_t* p_new_queue;
   p_new_queue = malloc(sizeof(*p_new_queue));

   if (p_new_queue != NULL) {
        p_new_queue->first = NULL;
        p_new_queue->last = NULL;
        p_new_queue->size = 0;
   }

   return p_new_queue;
}

int qc_queue_get_size(const qc_queue_t *p_queue) {
    if (p_queue == NULL) return -1;
    else return p_queue->size;
}

int qc_queue_enqueue(qc_queue_t *p_queue, char data) {
    qc_node_t* p_new_node;

    if (p_queue == NULL) return -1;    /* Queue not initialized */

    p_new_node = malloc(sizeof(*p_new_node));
    if (p_new_node == NULL) return -2; /* Memory allocation error */
    p_new_node->data = data;
    p_new_node->next = NULL;

    if (qc_queue_get_size(p_queue) == 0) {
        p_queue->first = p_new_node;
        p_queue->last = p_new_node;
        p_queue->size = 1;
    } else {
        p_queue->last->next = p_new_node;
        p_queue->last = p_new_node;
        p_queue->size += 1;
    }
    
    return 0;
}

int qc_queue_dequeue(qc_queue_t *p_queue, char* data) {
    if (p_queue == NULL) return -1; /* Queue not initialized yet */
    if (qc_queue_get_size(p_queue) == 0) return -2; /* No data to dequeue */

    qc_node_t *p_dequeued_node;

    /* Remove first node */
    p_dequeued_node = p_queue->first;
    p_queue->first = p_dequeued_node->next;
    p_queue->size -= 1;

    /* Extract data */
    *data = p_dequeued_node->data;

    /* Clear memory */
    free(p_dequeued_node);
    p_dequeued_node = NULL;

    return 0;
}

int qc_queue_peek(qc_queue_t *p_queue, char* data) {
    if (p_queue == NULL) return -1; /* Queue not initialized yet */
    if (qc_queue_get_size(p_queue) == 0) return -2; /* No data to peek */
    *data = p_queue->first->data;
    
    return 0;
}

int qc_queue_clear(qc_queue_t *p_queue) {
    char unused;
    if (p_queue == NULL) return -1; /* Queue not initialized yet */

    while (qc_queue_get_size(p_queue) > 0) {
        qc_queue_dequeue(p_queue, &unused);
    }

    return 0;
}

