`include "jkff_4bit.v"

module tb_jkff_4bit;
	reg clk,rst;
	wire [3:0]Q;
	
	initial
	clk=0;
	
	always
	#2 clk=~clk;
	
	jkff_4bit j(clk,rst,Q);
	
	initial
	begin
	$monitor($time," clk=%b Q=%4b rst=%b",clk,Q,j.j2.rst);
	#1 rst=1'b1;
	#1 rst=1'b0;
	#100 $finish;
	end
	endmodule
	