#ifndef __QC_QUEUE_CHAR_H__
#define __QC_QUEUE_CHAR_H__

#include <stdlib.h>
#include "qc_queue_char.h"

qc_queue_t* qc_queue_init() {
   qc_queue_t* new_queue;
   new_queue = malloc(sizeof(*new_queue));

   if (new_queue != NULL) {
        new_queue->first = NULL;
        new_queue->last = NULL;
        new_queue->size = 0;
   }

   return new_queue;
}

int qc_queue_get_size(qc_queue_t *queue) {
    if (queue == NULL) return -1;
    else return queue->size;
}

int qc_queue_enqueue(qc_queue_t *queue, char data) {
    qc_node_t* new_node;

    if (queue == NULL) return -1;    /* Queue not initialized */

    new_node = malloc(sizeof(*new_node));
    if (new_node == NULL) return -2; /* Memory allocation error */
    new_node->data = data;
    new_node->next = NULL;

    if (qc_queue_get_size(queue) == 0) {
        queue->first = new_node;
        queue->last = new_node;
        queue->size = 1;
    } else {
        queue->last->next = new_node;
        queue->last = new_node;
        queue->size += 1;
    }
    
    return 0;
}

int qc_queue_dequeue(qc_queue_t *queue, char* data) {
    if (queue == NULL) return -1; /* Queue not initialized yet */
    if (qc_queue_get_size(queue) == 0) return -2; /* No data to dequeue */

    qc_node_t *dequeued_node;

    /* Remove first node */
    dequeued_node = queue->first;
    queue->first = dequeued_node->next;
    queue->size -= 1;

    /* Extract data */
    *data = dequeued_node->data;

    /* Clear memory */
    free(dequeued_node);

    return 0;
}

int qc_queue_peek(qc_queue_t *queue, char* data) {
    if (queue == NULL) return -1; /* Queue not initialized yet */
    if (qc_queue_get_size(queue) == 0) return -2; /* No data to peek */
    *data = queue->first->data;
    
    return 0;
}

int qc_queue_clear(qc_queue_t *queue) {
    char unused;
    if (queue == NULL) return -1; /* Queue not initialized yet */

    while (qc_queue_get_size(queue) > 0) {
        qc_queue_dequeue(queue, &unused);
    }

    return 0;
}


#endif
