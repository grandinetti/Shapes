//
//  main.c
//  ShapeTester
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

int main(int argc, const char * argv[])
{
    MutableShapeRef shape = ShapeCreateMutable(0.0, 0.0, 0.0);
    ShapeShow(shape);
    
    ShapeTranslate(shape, 10.0, 20.0);
    ShapeRotate(shape, 180.);
    ShapeShow(shape);
    ShapeFinalize(shape);

    MutableSquareRef square = MutableSquareCreate(0.0, 0.0, 0.0, 10.0);
    ShapeShow((ShapeRef) square);
    SquareShow(square);
  
    ShapeTranslate((MutableShapeRef) square, 10.0, 20.0);
    ShapeRotate((MutableShapeRef) square, 180.);
    SquareShow(square);
    SquareFinalize(square);
    
    return 0;
}

