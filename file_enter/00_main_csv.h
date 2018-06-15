#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void StoreValue(FILE *fp, int col, int I, int J, char data_label[][I], double data[J][I]);
void MtrxSzCulc(FILE *fp, int *ROWM, int *COLM);
void DipoleMometum(int P, int N, double data[N][P]);