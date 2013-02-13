//
//  KFType.h
//  Shapes
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#ifndef Shapes_KFType_h
#define Shapes_KFType_h

typedef struct __KFType * KFTypeRef;

bool KFTypeEqual(KFTypeRef theType1, KFTypeRef theType2);

void KFRelease(KFTypeRef theType);
KFTypeRef KFRetain(KFTypeRef theType);

#endif
