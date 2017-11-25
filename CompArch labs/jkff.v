module jkff(clk,J,K,rst,Q);
	input clk,J,K,rst;
	output Q;
	reg Q;
	always @(posedge clk or rst)
	begin
	if(rst==1) Q<=1'b0;
	else if(J==1 && K==0) Q <= 1'b1;
	else if (J==0 && K==1) Q <= 1'b0;
	else if(J==1 && K==1) Q <= ~Q;
	end
endmodule