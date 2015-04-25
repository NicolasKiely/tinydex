#include <stdlib.h>
#include <string.h>

#include "record.h"

struct Record *createRecord(){
    struct Record *pNewRecord = malloc(sizeof(struct Record));
    if (pNewRecord != NULL){
        memset(pNewRecord, 0, sizeof(struct Record));
    }
    return pNewRecord;
}


void freeRecord(struct Record *pRecord){
    if (pRecord != NULL){
        free(pRecord);
    }
}
