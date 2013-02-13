//
//  CFShape.h
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#ifndef Shapes_CFShape_h
#define Shapes_CFShape_h

typedef const struct __CFShape * CFShapeRef;
typedef struct __CFShape * CFMutableShapeRef;

CFShapeRef CFShapeCreate(float xPosition, float yPosition, float orientation);
CFMutableShapeRef CFShapeCreateMutable(float xPosition, float yPosition, float orientation);
CFShapeRef CFShapeCreateStatic(float xPosition, float yPosition, float orientation);

float CFShapeGetXPosition(CFShapeRef theShape);
float CFShapeGetYPosition(CFShapeRef theShape);
float CFShapeGetOrientation(CFShapeRef theShape);

void CFShapeSetXPosition(CFMutableShapeRef theShape, float xPosition);
void CFShapeSetYPosition(CFMutableShapeRef theShape, float yPosition);
void CFShapeSetOrientation(CFMutableShapeRef theShape, float orientation);
void CFShapeTranslate(CFMutableShapeRef theShape, float xTranslation, float yTranslation);
void CFShapeRotate(CFMutableShapeRef theShape, float angle);

void CFShapeShow(CFShapeRef theShape);

#endif
