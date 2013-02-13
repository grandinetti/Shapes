//
//  Square.c
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
#include "Square.h"

struct __Square {
    // Shape Type attributes - Order is important!
    float xPosition;
    float yPosition;
    float orientation;
    
    // Square Type attributes
    float width;
};

bool SquareEqual(SquareRef theSquare1, SquareRef theSquare2)
{
    if(!ShapeEqual((ShapeRef) theSquare1, (ShapeRef) theSquare2)) return false;
    
    if(theSquare1->width != theSquare2->width) return false;
    return true;
}

static struct __Square *SquareAllocate()
{
    struct __Square *theSquare = malloc(sizeof(struct __Square));
    if(NULL == theSquare) return NULL;
    return theSquare;
}

SquareRef SquareCreate(float xPosition, float yPosition, float orientation, float width)
{
    struct __Square *newSquare = SquareAllocate();
    if(NULL == newSquare) return NULL;
    newSquare->xPosition = xPosition;
    newSquare->yPosition = yPosition;
    newSquare->orientation = orientation;
    newSquare->width = width;
    return newSquare;
}

MutableSquareRef MutableSquareCreate(float xPosition, float yPosition, float orientation, float width)
{
    return (MutableSquareRef) SquareCreate(xPosition, yPosition, orientation, width);
}

void SquareFinalize(SquareRef theSquare)
{
    if(NULL == theSquare) return;
    free((void *)theSquare);
}

float SquareGetXPosition(SquareRef theSquare)
{
    return ShapeGetXPosition((ShapeRef) theSquare);
}

float SquareGetYPosition(SquareRef theSquare)
{
    return ShapeGetYPosition((ShapeRef) theSquare);
}

float SquareGetOrientation(SquareRef theSquare)
{
    return ShapeGetOrientation((ShapeRef) theSquare);
}

float SquareGetWidth(SquareRef theSquare)
{
    if(NULL == theSquare) return nan(NULL);
    return theSquare->width;
}

void SquareSetXPosition(MutableSquareRef theSquare, float xPosition)
{
    ShapeSetXPosition((MutableShapeRef) theSquare, xPosition);
}

void SquareSetYPosition(MutableSquareRef theSquare, float yPosition)
{
    ShapeSetYPosition((MutableShapeRef) theSquare, yPosition);
}

void SquareSetOrientation(MutableSquareRef theSquare, float orientation)
{
    ShapeSetOrientation((MutableShapeRef) theSquare, orientation);
}

void SquareSetWidth(MutableSquareRef theSquare, float width)
{
    if(NULL == theSquare) return;
    theSquare->width = width;
}

void SquareShow(SquareRef theSquare)
{
    printf("square with width=%f at x=%f, y=%f with orientation %f\n",theSquare->width, theSquare->xPosition, theSquare->yPosition,theSquare->orientation);
}

