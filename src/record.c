#include <stdlib.h>
#include <string.h>

#include "record.h"

struct Record *Record_create(){
    struct Record *pNewRecord = malloc(sizeof(struct Record));
    if (pNewRecord != NULL){
        memset(pNewRecord, 0, sizeof(struct Record));
    }
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
