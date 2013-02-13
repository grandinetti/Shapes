//
//  main.c
//  CFShapeTester2
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
    CFMutableArrayRef array = CFArrayCreateMutable(kCFAllocatorDefault, 0, &kCFTypeArrayCallBacks);
    for(float orientation = 0.0; orientation <360.; orientation += 45.0) {
        CFMutableShapeRef shape = CFShapeCreateMutable(0.0, 0.0, orientation);
        CFShapeShow(shape);
        CFArrayAppendValue(array, shape);
        CFRelease(shape);
    }
    
    printf("\n\n");
    CFIndex count = CFArrayGetCount(array);
    for(CFIndex index = 0; index< count; index++) {
        CFMutableShapeRef shape = (CFMutableShapeRef) CFArrayGetValueAtIndex(array, index);
        CFShapeShow(shape);
    }
    
    CFRelease(array);
    
    return 0;
}

