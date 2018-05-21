#pragma once

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

double WaveFun(double, double, double);
void StoreValue(FILE*, double, double);
void DataWrite(FILE*, int, double []);
void FileOpera(FILE*, double, int, int,const char [] );