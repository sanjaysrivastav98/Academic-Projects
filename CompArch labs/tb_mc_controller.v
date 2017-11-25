`include "mc_controller.v"

module tb_mc_controller;
reg [5:0]Op;
reg [3:0]S;
wire RegDst,RegWrite,ALUSrcA,MemToReg,IRWrite,MemWrite,MemRead,IorD,PCWriteCond,PCWrite;
wire [3:0]NS;
wire [1:0]ALUSrcB,ALUOp,PCSource;
reg clk;
mc_controller M(Op,S,NS,RegDst,RegWrite,ALUSrcA,ALUSrcB,ALUOp,PCSource,MemToReg,IRWrite,MemWrite,MemRead,IorD,PCWriteCond,PCWrite);

initial
begin
clk=0; 
end

always
#2 clk=~clk;

always @( posedge clk)
begin
S<=NS;
end

initial
begin

$monitor($time, " s=%d ns=%d ",S,NS);

Op=6'b000000;
S=4'b0000;

#30 $finish;
end
endmodule

	