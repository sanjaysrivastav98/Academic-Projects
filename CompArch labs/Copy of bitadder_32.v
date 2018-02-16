`include "bitadder_8.v"

module bitadder_32(A,B,S,c);
	input [0:31]A;
	input [0:31]B;
	output [0:31]S;
	output c;
	
	wire [0:3]Cout;
	
	bitadder_8 b1(A[24:31],B[24:31],1'b0,Cout[0],S[24:31]);
	bitadder_8 b2(A[16:23],B[16:23],Cout[0],Cout[1],S[16:23]);
	bitadder_8 b3(A[8:15],B[8:15],Cout[1],Cout[2],S[8:15]);
	bitadder_8 b4(A[0:7],B[0:7],Cout[2],c,S[0:7]);
	
endmodule