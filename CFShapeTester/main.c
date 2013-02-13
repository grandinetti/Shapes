//
//  main.c
//  CFShapeTester
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#include <CoreFoundation/CoreFoundation.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include "CFShape.h"

int main(int argc, const char * argv[])
{

    CFMutableShapeRef shape = CFShapeCreateMutable(0.0, 0.0, 0.0);
    CFShapeShow(shape);
    
    CFShapeTranslate(shape, 10.0, 20.0);
    CFShapeRotate(shape, 180.);
    CFShapeShow(shape);
    
    CFRelease(shape);

    return 0;
}

