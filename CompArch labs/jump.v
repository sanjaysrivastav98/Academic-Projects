module jump(out,PC,in);
	input [31:0]in,PC;
	output [31:0]out;
	assign out={PC[31:29],in[28:0]};
	endmodule