`include "dff_async_clear.v"
module reg_32bit(q,d,clk,reset);
	input [31:0]d;
	input clk,reset;
	output [31:0]q;
	genvar j;
	generate for (j=0;j<32;j=j+1) begin: register_loop
		dff_async_clear d1(d[j],reset,clk,q[j]);
	end
	endgenerate
endmodule
	