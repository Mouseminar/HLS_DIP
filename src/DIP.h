#include "LinearTransform.h"
#include "MedianFilter.h"
#include "sobel.h"
#include "Threshold.h"

#ifndef DIP_H_
#define DIP_H_

void DIP(ap_uint<2> mode, hls::stream<trans_pkt>& src, hls::stream<trans_pkt>& dst, int rows, int cols, int k, int b);

#endif
