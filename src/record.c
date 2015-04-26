#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "record.h"


struct Record *Record_create(){
    struct Record *pNewRecord = malloc(sizeof(struct Record));
    if (pNewRecord == NULL){
        fprintf(stderr, "Error, could not allocate record\n");
        return NULL;
    }

    memset(pNewRecord, 0, sizeof(struct Record));
    return pNewRecord;
}


void Record_free(struct Record **ppRecord){
    struct Record *pRecord;
    if (ppRecord == NULL){ return; }
    pRecord = *ppRecord;
    if (pRecord == NULL){ return; }

    free(pRecord);
    *ppRecord = NULL;
}


struct RecordList *RecordList_create(){
    struct RecordList *pRecords;
    pRecords = malloc(sizeof(struct RecordList));
    if (pRecords == NULL) {
        fprintf(stderr, "Error, could not allocate record list\n");
        return NULL;
    }

    memset(pRecords, 0, sizeof(struct RecordList));
    return pRecords;
}


void RecordList_free(struct RecordList **ppRecords){
    struct RecordList *pRecords;
    if (ppRecords == NULL){ return; }
    pRecords = *ppRecords;
    if (pRecords == NULL){ return; }

    free(pRecords);
    *ppRecords = NULL;
}
