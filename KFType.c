//
//  KFType.c
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include "KFType.h"

struct __KFType {
    u_int32_t retainCount;
    void (*finalize)(void *);
    bool (*equal)(void *, void *);
};

bool KFTypeEqual(KFTypeRef theType1, KFTypeRef theType2)
{
    return theType1->equal(theType1,theType2);
}

void KFRelease(KFTypeRef theType)
{
    if(NULL==theType) return;
    if(theType->retainCount == 1) {
        theType->finalize(theType);
        return;
    }
    theType->retainCount--;
    return;
}

KFTypeRef KFRetain(KFTypeRef theType)
{
    if(NULL==theType) return NULL;
    theType->retainCount++;
    return theType;
}