#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

extern double WaveFun(double, double, double);
extern void StoreValue(FILE*, double, double);
extern void DataWrite(FILE*, int, double []);
extern void FileOpera(FILE*, double, int, int,const char [] );