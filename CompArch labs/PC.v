module PC(clk,rst,count);
	input clk,rst;
	output [31:0]count;
	always @(posedge clk)
	begin
	if (rst)
	count=0;
	else
	count=count+1;
	end
	
endmodule