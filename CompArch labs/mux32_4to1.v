`include "mux4_1.v"
module mux32_4to1(regData,q,reg_no);
	input [31:0][31:0]q;
	output [31:0]regData;
	input [4:0]reg_no;
	assign regData=q[reg_no];
	
endmodule
