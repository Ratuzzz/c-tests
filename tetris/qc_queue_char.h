typedef struct qc_node_t {
    char data;
    struct qc_node_t *next;
} qc_node_t;

typedef struct qc_queue_t {
    qc_node_t *first;
    qc_node_t *last;
    int size;
} qc_queue_t;

qc_queue_t* qc_queue_init();
int qc_queue_get_size(qc_queue_t* queue);
int qc_queue_enqueue(qc_queue_t* queue, char data);
int qc_queue_dequeue(qc_queue_t* queue, char* data);
int qc_queue_peek(qc_queue_t* queue, char* data);
int qc_queue_clear(qc_queue_t* queue);
