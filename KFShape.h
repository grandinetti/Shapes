//
//  KFShape.h
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#ifndef Shapes_KFShape_h
#define Shapes_KFShape_h

typedef const struct __KFShape * KFShapeRef;
typedef struct __KFShape * KFMutableShapeRef;

bool KFShapeEqual(void *theType1, void *theType2);
void KFShapeFinalize(void *theShape);
KFShapeRef KFShapeCreate(float xPosition, float yPosition, float orientation);
KFMutableShapeRef KFShapeCreateMutable(float xPosition, float yPosition, float orientation);

float KFShapeGetXPosition(KFShapeRef theShape);
float KFShapeGetYPosition(KFShapeRef theShape);
float KFShapeGetOrientation(KFShapeRef theShape);

void KFShapeSetXPosition(KFMutableShapeRef theShape, float xPosition);
void KFShapeSetYPosition(KFMutableShapeRef theShape, float yPosition);
void KFShapeSetOrientation(KFMutableShapeRef theShape, float orientation);
void KFShapeTranslate(KFMutableShapeRef theShape, float xTranslation, float yTranslation);
void KFShapeRotate(KFMutableShapeRef theShape, float angle);

void KFShapeShow(KFShapeRef theShape);

#endif
