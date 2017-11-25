`include "BHT.v"

module tb_BHT;
	wire [1:0]out;
	reg [9:0]inp;
	reg [1:0]writeData;
	reg WR;
	
	BHT b(out,inp,writeData,WR);
	
	initial begin
		$monitor($time," out= %2b, in = %10b, writeData= %2b, WR=%b",out,inp,writeData,WR);
		inp=10'b0000000000;
		#2 writeData = 2'b10;WR=1'b1;
		#2 writeData = 2'b00;WR=1'b1;
		#2 inp=10'b11111111;WR=1'b0;
		#2 writeData = 2'b11;
		#2 WR=1'b1;
		#10 $finish;
		
	end
	endmodule