//
//  Shape.h
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#ifndef Shapes_Shape_h
#define Shapes_Shape_h

typedef const struct __Shape * ShapeRef;
typedef struct __Shape * MutableShapeRef;

bool ShapeEqual(ShapeRef theShape1, ShapeRef theShape2);
void ShapeFinalize(ShapeRef theShape);
ShapeRef ShapeCreate(float xPosition, float yPosition, float orientation);
MutableShapeRef ShapeCreateMutable(float xPosition, float yPosition, float orientation);

float ShapeGetXPosition(ShapeRef theShape);
float ShapeGetYPosition(ShapeRef theShape);
float ShapeGetOrientation(ShapeRef theShape);

void ShapeSetXPosition(MutableShapeRef theShape, float xPosition);
void ShapeSetYPosition(MutableShapeRef theShape, float yPosition);
void ShapeSetOrientation(MutableShapeRef theShape, float orientation);
void ShapeTranslate(MutableShapeRef theShape, float xTranslation, float yTranslation);
void ShapeRotate(MutableShapeRef theShape, float angle);

void ShapeShow(ShapeRef theShape);

#endif
