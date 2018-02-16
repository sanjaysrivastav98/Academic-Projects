`include "bitadder_8.v"

module tb_bitadder_8;
	reg [0:7]A;
	reg [0:7]B;
	wire [0:7]S;
	wire c;
	
	bitadder_8 ba(A,B,1'b0,c,S);
	
	initial
	begin 
		#10 A=8'b00000000 ; B=8'b00000001;
		#10 A=8'b00000011 ; B=8'b00000110;
		#10 A=8'b10001000 ; B=8'b10001100;
		#10 $finish;
	end
	
	initial 
		begin
		$monitor(,$time," A = %b | B = %b | c = %b | S = %b ",A,B,c,S);
		end
	endmodule