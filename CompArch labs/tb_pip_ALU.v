`include "pip_ALU.v"

module tb_pip_ALU;
	reg [3:0]A,B;
	reg [2:0] op;
	wire [3:0]X;
	
	pip_ALU p(A,B,op,X);
	
	initial
	begin
	$monitor($time, " A=%4b,B=%4b , op=%3b, X= %4b",A,B,op,X);
	A=4'b0100;
	B=4'b0110;
	#10 op=3'b010;
	#20 op= 3'b101;
	#30 op= 3'b111;
	#40 op= 3'b000;
	#50 op=3'b000;
	#60 op=3'b001;
	#70 op=3'b010;
	#80 op=3'b011;
	#90 op=3'b100;
	#100 op=3'b101;
	#110 op=3'b110;
	#120 op=3'b111;
	#130 $finish;
	
	end
	endmodule
	
