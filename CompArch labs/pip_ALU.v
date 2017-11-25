`include "mux8_to_1.v"
module pip_ALU(A,B,op_code,X);
	input [3:0]A,B;
	input [2:0]op_code;
	output [3:0]X;
	wire [7:0][3:0]inp;
	assign inp[0]=A+B;
	assign inp[1]=A-B;
	assign inp[2] = A^B;
	assign inp[3]=A|B;
	assign inp[4]= A&B;
	assign inp[5]= ~(A|B);
	assign inp[6]= ~(A&B);
	assign inp[7]= ~(A^B);
	
	mux8_to_1 m(op_code,inp,X);
	endmodule
	
	