`include "FADDER_1_beh.v"

module FADDER_4_beh(A,B,M,C,S,V);

	input [0:3]A;
	input [0:3]B;
	input M;
	output C;
	output [0:3]S;
	reg [0:3]S;
	reg C;
	wire [0:3]Cout;