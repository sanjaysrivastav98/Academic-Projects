`include "bit32AND.v"
`include "bit32OR.v"
`include "FA_32dataflow.v"
`include "mux32Bit_4To1.v"
module ALU(A,B,Binvert,Cin,op,res,Cout);
	output [31:0]res;
	output Cout;
	input [31:0]A,B;
	input [1:0]op;
	input Binvert,Cin;
	wire  [31:0]  wAnd, wOr, wAdd, wMux, notB;
    assign  {notB} = ~B;
    bit32AND  And(wAnd, A, B);
	bit32OR Or(wOr, A, B);
	FA_32dataflow  Add(Cout, wAdd, A, B, Binvert);
	mux32Bit_4To1 Mux2(res, op, wAnd, wOr, wAdd, 32'h00000000);
endmodule
