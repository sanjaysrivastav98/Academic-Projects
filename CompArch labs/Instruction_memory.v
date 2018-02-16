module Instruction_memory(ReadAdd,Instruction,clock);
input [31:0]ReadAdd;
input clock;
output reg [31:0]Instruction;
reg [31:0] reginst[31:0];
initial
	$readmemh("reg.txt",reginst);
always @(posedge clock)
	Instruction = reginst[ReadAdd[4:0]];
endmodule
