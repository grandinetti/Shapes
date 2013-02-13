//
//  main.c
//  KFShapeTester
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

int main(int argc, const char * argv[])
{
    KFMutableShapeRef shape = KFShapeCreateMutable(0.0, 0.0, 0.0);
    KFShapeShow(shape);
    
    KFShapeTranslate(shape, 10.0, 20.0);
    KFShapeRotate(shape, 180.);
    KFShapeShow(shape);
    
    KFRelease((KFTypeRef) shape);
    
    return 0;
}

