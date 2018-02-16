module mux8_to_1(op_code,inp,out);
	input [7:0][3:0]inp;
	input [2:0]op_code;
	output [3:0]out;
	assign out[0]= inp[7][0]&op_code[0]&op_code[1]&op_code[2] | inp[6][0]&~op_code[0]&op_code[1]&op_code[2] | inp[5][0]&op_code[0]&~op_code[1]&op_code[2] | inp[4][0]&~op_code[0]&~op_code[1]&op_code[2] | inp[3][0]&op_code[0]&op_code[1]&~op_code[2] | inp[2][0]&~op_code[0]&op_code[1]&~op_code[2] | inp[1][0]&op_code[0]&~op_code[1]&~op_code[2] | inp[0][0]&~op_code[0]&~op_code[1]&~op_code[2]; 
	assign out[1]= inp[7][1]&op_code[0]&op_code[1]&op_code[2] | inp[6][1]&~op_code[0]&op_code[1]&op_code[2] | inp[5][1]&op_code[0]&~op_code[1]&op_code[2] | inp[4][1]&~op_code[0]&~op_code[1]&op_code[2] | inp[3][1]&op_code[0]&op_code[1]&~op_code[2] | inp[2][1]&~op_code[0]&op_code[1]&~op_code[2] | inp[1][1]&op_code[0]&~op_code[1]&~op_code[2] | inp[0][1]&~op_code[0]&~op_code[1]&~op_code[2]; 
	assign out[2]= inp[7][2]&op_code[0]&op_code[1]&op_code[2] | inp[6][2]&~op_code[0]&op_code[1]&op_code[2] | inp[5][2]&op_code[0]&~op_code[1]&op_code[2] | inp[4][2]&~op_code[0]&~op_code[1]&op_code[2] | inp[3][2]&op_code[0]&op_code[1]&~op_code[2] | inp[2][2]&~op_code[0]&op_code[1]&~op_code[2] | inp[1][2]&op_code[0]&~op_code[1]&~op_code[2] | inp[0][2]&~op_code[0]&~op_code[1]&~op_code[2]; 
	assign out[3]= inp[7][3]&op_code[0]&op_code[1]&op_code[2] | inp[6][3]&~op_code[0]&op_code[1]&op_code[2] | inp[5][3]&op_code[0]&~op_code[1]&op_code[2] | inp[4][3]&~op_code[0]&~op_code[1]&op_code[2] | inp[3][3]&op_code[0]&op_code[1]&~op_code[2] | inp[2][3]&~op_code[0]&op_code[1]&~op_code[2] | inp[1][3]&op_code[0]&~op_code[1]&~op_code[2] | inp[0][3]&~op_code[0]&~op_code[1]&~op_code[2]; 	
endmodule
	