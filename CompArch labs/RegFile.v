`include "mux32_4to1.v"
`include "decoder2_4.v"
`include "reg_32bit.v"
module RegFile(clk,reset,ReadReg1,ReadReg2,WriteData,WriteReg,RegWrite,ReadData1,ReadData2);
	input clk,reset,RegWrite;
	input [4:0]WriteReg,ReadReg1,ReadReg2;
	input [31:0]WriteData;
	output [31:0]ReadData1,ReadData2;
	wire [31:0][31:0]regis;
	wire [31:0]registers;
	decoder2_4 d1(registers,WriteReg);
	reg [31:0]clk2;
	wire temp;
	and m1(temp,clk,RegWrite);
	integer j;
	always@(*)begin
		for(j=0;j<32;j=j+1) begin
			if (temp==1 && registers[j]==1) clk2[j]=1;
		end
	end
	genvar i;
	generate for(i=0;i<32;i=i+1) begin: registerLoop
		reg_32bit r(regis[i],WriteData,clk2[i],reset);
	end
	endgenerate
	mux32_4to1 m1(ReadData1,regis,ReadReg1);
	mux32_4to1 m2(ReadData2,regis,ReadReg2);
	
endmodule
	
	
	
	
	
	
	
	