//
//  KFShape.c
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
#include "KFShape.h"

struct __KFShape {
    u_int32_t retainCount;
    void (*finalize)(void *);
    bool (*equal)(void *, void *);

    // Shape Type attributes  - order of declaration is essential
    float xPosition;
    float yPosition;
    float orientation;
};

bool KFShapeEqual(void *theType1, void *theType2)
{
    KFShapeRef theShape1 = (KFShapeRef) theType1;
    KFShapeRef theShape2 = (KFShapeRef) theType2;
    
    if(NULL == theShape1 || NULL == theShape2) return false;
    if(theShape1 == theShape2) return true;

    if(theShape1->xPosition != theShape2->xPosition) return false;
    if(theShape1->yPosition != theShape2->yPosition) return false;
    if(theShape1->orientation != theShape2->orientation) return false;
    return true;
}

void KFShapeFinalize(void *theShape)
{
    if(NULL == theShape) return;
    free((void *)theShape);
}

static struct __KFShape *KFShapeAllocate()
{
    struct __KFShape *theShape = malloc(sizeof(struct __KFShape));
    if(NULL == theShape) return NULL;
    theShape->retainCount = 1;
    theShape->finalize = KFShapeFinalize;
    theShape->equal = KFShapeEqual;
    return theShape;
}

KFShapeRef KFShapeCreate(float xPosition, float yPosition, float orientation)
{
    struct __KFShape *newShape = KFShapeAllocate();
    if(NULL == newShape) return NULL;
    newShape->xPosition = xPosition;
    newShape->yPosition = yPosition;
    newShape->orientation = orientation;
    return newShape;
}

KFMutableShapeRef KFShapeCreateMutable(float xPosition, float yPosition, float orientation)
{
    return (KFMutableShapeRef) KFShapeCreate(xPosition, yPosition, orientation);
}

float KFShapeGetXPosition(KFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->xPosition;
}

float KFShapeGetYPosition(KFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->yPosition;
}

float KFShapeGetOrientation(KFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->orientation;
}

void KFShapeSetXPosition(KFMutableShapeRef theShape, float xPosition)
{
    if(NULL == theShape) return;
    theShape->xPosition = xPosition;
}

void KFShapeSetYPosition(KFMutableShapeRef theShape, float yPosition)
{
    if(NULL == theShape) return;
    theShape->yPosition = yPosition;
}

void KFShapeSetOrientation(KFMutableShapeRef theShape, float orientation)
{
    if(NULL == theShape) return;
    theShape->orientation = orientation;
}

void KFShapeTranslate(KFMutableShapeRef theShape, float xTranslation, float yTranslation)
{
    if(NULL == theShape) return;
    theShape->xPosition += xTranslation;
    theShape->yPosition += yTranslation;
}

void KFShapeRotate(KFMutableShapeRef theShape, float angle)
{
    if(NULL == theShape) return;
    theShape->orientation += angle;
}

void KFShapeShow(KFShapeRef theShape)
{
    printf("shape at x=%f, y=%f with orientation %f\n",theShape->xPosition, theShape->yPosition,theShape->orientation);
}
