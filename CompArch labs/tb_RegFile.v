`include "RegFile.v"

module tb_RegFile;
	reg clk,reset,RegWrite;
	reg [4:0]WriteReg,ReadReg1,ReadReg2;
	reg [31:0]WriteData;
	wire [31:0]ReadData1,ReadData2;
	RegFile r(clk,reset,ReadReg1,ReadReg2,WriteData,WriteReg,RegWrite,ReadData1,ReadData2);
	always @(clk)
	#5 clk<=~clk;
	initial
	begin
	$monitor($time," clk=%b RD1=%h RD2=%h",clk,ReadData1,ReadData2);
	clk= 1'b1;
	#5 reset=1'b0;
	#5 ReadReg1=5'b00000;
	#5 ReadReg2=5'b00011;
	#5 reset=1'b1;WriteData=32'hAFAFAFAF;RegWrite=1'b1;WriteReg=5'b00000;
	#5 WriteData=32'h98635533;RegWrite=1'b1;WriteReg=5'b00010;
	#5 ReadReg1=5'b00000;
	#5 ReadReg2=5'b00010;
	#100 $finish;
	end
endmodule