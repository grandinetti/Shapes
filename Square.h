//
//  Square.h
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#ifndef Shapes_Square_h
#define Shapes_Square_h

typedef const struct __Square * SquareRef;
typedef struct __Square * MutableSquareRef;

bool SquareEqual(SquareRef theSquare1, SquareRef theSquare2);
void SquareFinalize(SquareRef theSquare);
SquareRef SquareCreate(float xPosition, float yPosition, float orientation, float width);
MutableSquareRef MutableSquareCreate(float xPosition, float yPosition, float orientation, float width);

float SquareGetXPosition(SquareRef theSquare);
float SquareGetYPosition(SquareRef theSquare);
float SquareGetOrientation(SquareRef theSquare);
float SquareGetWidth(SquareRef theSquare);

void SquareSetXPosition(MutableSquareRef theSquare, float xPosition);
void SquareSetYPosition(MutableSquareRef theSquare, float yPosition);
void SquareSetOrientation(MutableSquareRef theSquare, float orientation);
void SquareSetWidth(MutableSquareRef theSquare, float width);

void SquareShow(SquareRef theSquare);

#endif
