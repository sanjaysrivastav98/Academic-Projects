module parity_generator(X,Y);
	input [3:0]X;
	output [4:0]Y;
	wire [2:0]temp;
	assign temp[0]=X[3]^X[2];
	assign temp[1]=temp[0]^X[1];
	assign temp[2]=temp[1]^X[0];
	assign Y={X,temp[2]};
endmodule