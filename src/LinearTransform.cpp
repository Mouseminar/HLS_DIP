#include "LinearTransform.h"

static PIXEL Linear(PIXEL p, int k, int b)
{
	double ans;
	ans = ((int)p) * k + b;
	if (ans > 255) ans = 255;
	if (ans < 0) ans = 0;
	return (PIXEL)ans;
}

void LinearTransform(hls::stream<trans_pkt>& src, hls::stream<trans_pkt>& dst, int rows, int cols, int k, int b)
{
//#pragma HLS INTERFACE axis port=src
//#pragma HLS INTERFACE axis port=dst
//#pragma HLS INTERFACE s_axilite port=rows  bundle=CTRL
//#pragma HLS INTERFACE s_axilite port=cols  bundle=CTRL
//#pragma HLS INTERFACE s_axilite port=k  bundle=CTRL
//#pragma HLS INTERFACE s_axilite port=b  bundle=CTRL
//#pragma HLS INTERFACE s_axilite port=return bundle=CTRL
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
			data_p.data = Linear((PIXEL)data_p.data, k, b);
			dst.write(data_p);
		}
	}
}
