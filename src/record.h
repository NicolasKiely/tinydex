/**
 * Manager for record lists
 */
#ifndef RECORD_HEADER 
#define RECORD_HEADER

#define RECORD_CHUNK_SIZE 4096


/* Record data structure */
struct Record {
    /* Buffer of characters */
    char *pBuf;

    /* Allocated memory size */
    unsigned long bufSize;

    /* Characters used */
    unsigned long charSize;

    /* Next record in list */
    struct Record *pNext;

    /* Previous record in list */
    struct Record *pPrev;
};


/* Manages list of records */
struct RecordList {
    /* First Record */
    struct Record *pFirst;

    /* Last Record */
    struct Record *pLast;

    /* Number of records */
    unsigned long count;
};


/* Creates new record */
struct Record *Record_create();

/* Frees record */
void Record_free(struct Record **ppRecord);


/* Creates new record list */
struct RecordList *RecordList_create();

/* Frees record list */
void RecordList_free(struct RecordList **ppRecords);

#endif
