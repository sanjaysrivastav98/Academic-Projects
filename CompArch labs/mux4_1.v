module mux4_1(regData,q1,q2,q3,q4,reg_no);
	input q1,q2,q3,q4;
	output regData;
	input [1:0]reg_no;
	
	assign regData= (reg_no[1]&reg_no[0]&q4) | (reg_no[1] &(~reg_no[0]) & q3) | ((~reg_no[1]) & reg_no[0]&q2) | ((~reg_no[0]) & (~reg_no[1]) &q1);

endmodule	