// DIP.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include "DIP.h"

void DIP(ap_uint<2> mode, hls::stream<trans_pkt>& src, hls::stream<trans_pkt>& dst, int rows, int cols, int k, int b)
{
#pragma HLS INTERFACE axis port=src
#pragma HLS INTERFACE axis port=dst
#pragma HLS INTERFACE s_axilite port=mode  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=rows  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=cols  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=k  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=b  bundle=CTRL
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
	switch (mode)
	{
	case 0:
		LinearTransform(src, dst, rows, cols, k, b);
		break;
	case 1:
		MedianFilter(src, dst, rows, cols);
		break;
	case 2:
		sobel(src, dst, rows, cols);
		break;
	case 3:
		Threshold(src, dst, rows, cols, b);
		break;
	default:
		break;
	}
}
