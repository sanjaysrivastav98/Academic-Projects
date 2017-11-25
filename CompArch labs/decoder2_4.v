module decoder2_4 (register,reg_no);
	output reg [31:0]register;
	input [4:0]reg_no;
	integer j;	
	always @(reg_no)
	begin
	register=32'h0000000;
	register[reg_no]=1'b1;
	end
	
endmodule