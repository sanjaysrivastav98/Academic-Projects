`include "FADDER.v"

module bitadder_8(A,B,Cin,Cout,S);
	input [0:7]A;
	input [0:7]B;
	input Cin;
	output Cout;
	output [0:7]S;
	
	wire [0:6]tempCin;
	
	FADDER f1(S[7],tempCin[6],A[7],B[7],Cin);
	FADDER f2(S[6],tempCin[5],A[6],B[6],tempCin[6]);
	FADDER f3(S[5],tempCin[4],A[5],B[5],tempCin[5]);
	FADDER f4(S[4],tempCin[3],A[4],B[4],tempCin[4]);
	FADDER f5(S[3],tempCin[2],A[3],B[3],tempCin[3]);
	FADDER f6(S[2],tempCin[1],A[2],B[2],tempCin[2]);
	FADDER f7(S[1],tempCin[0],A[1],B[1],tempCin[1]);
	FADDER f8(S[0],Cout,A[0],B[0],tempCin[0]);
endmodule