//
//  CFShape.c
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include "CFRuntime.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include "CFShape.h"

struct __CFShape {
    CFRuntimeBase   _base;

    // Shape Type attributes
    float xPosition;
    float yPosition;
    float orientation;
};

static Boolean CFShapeEqual(CFTypeRef theType1, CFTypeRef theType2)
{
    CFShapeRef theShape1 = (CFShapeRef) theType1;
    CFShapeRef theShape2 = (CFShapeRef) theType2;
    
    if(NULL == theShape1 || NULL == theShape2) return false;
    if(theShape1 == theShape2) return true;

    if(theShape1->xPosition != theShape2->xPosition) return false;
    if(theShape1->yPosition != theShape2->yPosition) return false;
    if(theShape1->orientation != theShape2->orientation) return false;
    return true;
}

void CFShapeFinalize(CFTypeRef theShape)
{
    if(NULL == theShape) return;
}

static CFStringRef CFShapeCopyDebugDesc(CFTypeRef cf)
{
    if(NULL == cf) return NULL;
    CFShapeRef theShape = (CFShapeRef) cf;
    
    return CFStringCreateWithFormat(kCFAllocatorDefault, NULL,
                                    CFSTR("<CFShape %p>"),
                                    theShape);
}

static CFTypeID _kCFShapeID = _kCFRuntimeNotATypeID;

static CFRuntimeClass _kCFShapeClass = {
    0,
    "CFShape",
    NULL,NULL,
    CFShapeFinalize,
    CFShapeEqual,NULL,NULL,CFShapeCopyDebugDesc};

static struct __CFShape *CFShapeAllocate()
{
    if(_kCFShapeID ==_kCFRuntimeNotATypeID) {
        _kCFShapeID = _CFRuntimeRegisterClass((const CFRuntimeClass * const)&_kCFShapeClass);
    }

    // *** Initialize object ***
    struct __CFShape *theShape;
    uint32_t extra = sizeof(struct __CFShape) - sizeof(CFRuntimeBase);
    theShape = (struct __CFShape *)_CFRuntimeCreateInstance(kCFAllocatorDefault, _kCFShapeID, extra, NULL);
    if (NULL == theShape) return NULL;
    return theShape;
}

CFShapeRef CFShapeCreate(float xPosition, float yPosition, float orientation)
{
    struct __CFShape *newShape = CFShapeAllocate();
    if(NULL == newShape) return NULL;
    newShape->xPosition = xPosition;
    newShape->yPosition = yPosition;
    newShape->orientation = orientation;
    return newShape;
}

CFMutableShapeRef CFShapeCreateMutable(float xPosition, float yPosition, float orientation)
{
    return (CFMutableShapeRef) CFShapeCreate(xPosition, yPosition, orientation);
}

// Create unreleaseable CFType 
CFShapeRef CFShapeCreateStatic(float xPosition, float yPosition, float orientation)
{
    CFShapeRef shape = CFShapeCreate(xPosition, yPosition, orientation);
    _CFRuntimeInitStaticInstance((void *) shape, _kCFShapeID);
    return shape;
}

float CFShapeGetXPosition(CFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->xPosition;
}

float CFShapeGetYPosition(CFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->yPosition;
}

float CFShapeGetOrientation(CFShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->orientation;
}

void CFShapeSetXPosition(CFMutableShapeRef theShape, float xPosition)
{
    if(NULL == theShape) return;
    theShape->xPosition = xPosition;
}

void CFShapeSetYPosition(CFMutableShapeRef theShape, float yPosition)
{
    if(NULL == theShape) return;
    theShape->yPosition = yPosition;
}

void CFShapeSetOrientation(CFMutableShapeRef theShape, float orientation)
{
    if(NULL == theShape) return;
    theShape->orientation = orientation;
}

void CFShapeTranslate(CFMutableShapeRef theShape, float xTranslation, float yTranslation)
{
    if(NULL == theShape) return;
    theShape->xPosition += xTranslation;
    theShape->yPosition += yTranslation;
}

void CFShapeRotate(CFMutableShapeRef theShape, float angle)
{
    if(NULL == theShape) return;
    theShape->orientation += angle;
}

void CFShapeShow(CFShapeRef theShape)
{
    printf("shape at x=%f, y=%f with orientation %f\n",theShape->xPosition, theShape->yPosition,theShape->orientation);
}

