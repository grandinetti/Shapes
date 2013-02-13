//
//  main.m
//  CFShapeTester3
//
//  Created by Philip on 11/18/12.
//  Copyright (c) 2012 Philip. All rights reserved.
//

#import <Foundation/Foundation.h>
#include <CoreFoundation/CoreFoundation.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <math.h>
#include "CFShape.h"

int main(int argc, const char * argv[])
{

    @autoreleasepool {
        
        NSMutableArray *array = [[NSMutableArray alloc] init];
        for(float orientation = 0.0; orientation <360.; orientation += 45.0) {
            CFMutableShapeRef shape = CFShapeCreateMutable(0.0, 0.0, orientation);
            CFShapeShow(shape);
            NSLog(@"retain count is %ld",[(id) shape retainCount]);
            [array addObject:(id) shape];
            NSLog(@"retain count is %ld",[(id) shape retainCount]);
            [(id) shape retain];
            NSLog(@"retain count is %ld",[(id) shape retainCount]);
            [(id) shape release];
            CFRelease(shape);
        }
        
        printf("\n\n");
        NSUInteger count = [array count];
        for(NSUInteger index = 0; index< count; index++) {
            CFMutableShapeRef shape = (CFMutableShapeRef) [array objectAtIndex:index];
            CFShapeShow(shape);
        }
        
        [array release];
    }
    return 0;
}

