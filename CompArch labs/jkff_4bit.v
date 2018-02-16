`include"jkff.v"

module jkff_4bit(clk,rst,Q);
	input clk,rst;
	output [3:0]Q;
	jkff j1(clk,1'b1,1'b1,rst,Q[0]);
	jkff j2(clk,Q[0],Q[0],rst,Q[1]);
	wire inp;
	assign inp = Q[0]&Q[1];
	jkff j3(clk,inp,inp,rst,Q[2]);
	wire inp2;
	assign inp2 = inp&Q[2];
	jkff j4(clk,inp2,inp2,rst,Q[3]);
endmodule