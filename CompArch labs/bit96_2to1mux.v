`include "bit32_2to1mux.v"
module bit32_3to1mux(out,sel,in1,in2);
input [31:0] in1,in2,in3;
output [31:0] out;
input [1:0]sel;
wire [31:0]temp;

bit32_2to1mux b1(temp,sel[0],in1,in2);
bit32_2to1mux b2(out,sel[1],temp,in3);

endgenerate
endmodule