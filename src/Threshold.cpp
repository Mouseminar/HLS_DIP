#include "Threshold.h"

void Threshold(hls::stream<trans_pkt>& src, hls::stream<trans_pkt>& dst, int rows, int cols, PIXEL ts)
{
	trans_pkt data_p;
	ap_uint<13> row, col;

	for (row = 1; row < rows + 1; row++)
	{
#pragma HLS LOOP_TRIPCOUNT min=1 max=720
		for (col = 0; col < cols; col++)
		{
#pragma HLS LOOP_TRIPCOUNT min=1 max=1280
#pragma HLS pipeline
			data_p = src.read();
			PIXEL p = data_p.data;
			if (p > ts) data_p.data = 255;
			else data_p.data = 0;
			dst.write(data_p);
		}
	}
}
