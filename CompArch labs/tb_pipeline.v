`include "encoder.v"
`include "pip_ALU.v"
`include "parity_generator.v"

module tb_pipeline;
	reg [15:0]funAB;
	wire [4:0]Y;
	
	reg [2:0]ctrl;
	reg [3:0]A,B,out;
	wire [2:0]en;
	wire [3:0]X;
	reg clk;
	
	initial
	begin
	clk=0; 
	end
	
	always
	#2 clk=~clk;
	
	encoder e(en,funAB[15:8]);
	pip_ALU p1(A,B,ctrl,X);
	parity_generator p2(X,Y);
	
	always@(posedge clk)
	begin
		ctrl <= en;
		A <= funAB[7:4];
		B <= funAB[3:0];
		out <= X;
		
	end
	
	initial
	begin
	$monitor($time," funcAB=%16b , Y=%5b",funAB,Y);
	
	#2 funAB = 16'b0000000110000000;
	#2 funAB=16'b 0000100001111011;
	#2 funAB=16'b 0001000010001001;
	#8 $finish;
	end
	endmodule
	
	
	
	
	
	
