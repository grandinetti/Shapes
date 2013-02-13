//
//  Shape.c
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
#include "Shape.h"

struct __Shape {
    // Shape Type attributes  - order of declaration is essential
    float xPosition;
    float yPosition;
    float orientation;
};

bool ShapeEqual(ShapeRef theShape1, ShapeRef theShape2)
{
    if(NULL == theShape1 || NULL == theShape2) return false;
    if(theShape1 == theShape2) return true;
    if(theShape1->xPosition != theShape2->xPosition) return false;
    if(theShape1->yPosition != theShape2->yPosition) return false;
    if(theShape1->orientation != theShape2->orientation) return false;
    return true;
}

static struct __Shape *ShapeAllocate()
{
    struct __Shape *theShape = malloc(sizeof(struct __Shape));
    if(NULL == theShape) return NULL;
    return theShape;
}

ShapeRef ShapeCreate(float xPosition, float yPosition, float orientation)
{
    struct __Shape *newShape = ShapeAllocate();
    if(NULL == newShape) return NULL;
    newShape->xPosition = xPosition;
    newShape->yPosition = yPosition;
    newShape->orientation = orientation;
    return newShape;
}

MutableShapeRef ShapeCreateMutable(float xPosition, float yPosition, float orientation)
{
    return (MutableShapeRef) ShapeCreate(xPosition, yPosition, orientation);
}

void ShapeFinalize(ShapeRef theShape)
{
    if(NULL == theShape) return;
    free((void *)theShape);
}

float ShapeGetXPosition(ShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->xPosition;
}

float ShapeGetYPosition(ShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->yPosition;
}

float ShapeGetOrientation(ShapeRef theShape)
{
    if(NULL == theShape) return nan(NULL);
    return theShape->orientation;
}

void ShapeSetXPosition(MutableShapeRef theShape, float xPosition)
{
    if(NULL == theShape) return;
    theShape->xPosition = xPosition;
}

void ShapeSetYPosition(MutableShapeRef theShape, float yPosition)
{
    if(NULL == theShape) return;
    theShape->yPosition = yPosition;
}

void ShapeSetOrientation(MutableShapeRef theShape, float orientation)
{
    if(NULL == theShape) return;
    theShape->orientation = orientation;
}

void ShapeTranslate(MutableShapeRef theShape, float xTranslation, float yTranslation)
{
    if(NULL == theShape) return;
    theShape->xPosition += xTranslation;
    theShape->yPosition += yTranslation;
}

void ShapeRotate(MutableShapeRef theShape, float angle)
{
    if(NULL == theShape) return;
    theShape->orientation += angle;
}

void ShapeShow(ShapeRef theShape)
{
    printf("shape at x=%f, y=%f with orientation %f\n",theShape->xPosition, theShape->yPosition,theShape->orientation);
}
