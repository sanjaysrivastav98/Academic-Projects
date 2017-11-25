`include "parity_generator.v"

module tb_PG;
	reg [3:0]X;
	wire [4:0]Y;
	
	parity_generator p(X,Y);
	initial
	begin
	$monitor($time, " X=%4b Y=%5b",X,Y);
	
	#10 X=4'b0000;
	#10 X=4'b 0001;
	#10 X=4'b 1111;
	#10 X=4'b 1101;
	#10 $finish;
	
	end
	endmodule