module Instruction_memory(ReadAdd,Instruction,clock);
input [31:0]ReadAdd;
input clock;
output reg [31:0]Instruction;
reg [31:0] memory[31:0];
initial begin
    memory[0] = 32'b00000000000000000000000000000000;  // nop
    memory[1] = 32'b00000000000000000000000000000000;  // nop
    memory[2] = 32'b00000000000000000000000000000000;  // nop
    memory[3] = 32'b10001100000100010000000000001000;  // lw  $s1($17), 8($0)
    memory[4] = 32'b10001100000100100000000000000100;  // lw  $s2($18), 4($0)
    memory[5] = 32'b00000010001100100100000000100000;  // add $t0($8), $s1($17), $s2($18)
    memory[6] = 32'b00000000000000000000000000000000;  // nop
    memory[7] = 32'b00000000000000000000000000000000;  // nop
    memory[8] = 32'b00000000000000000000000000000000;  // nop
    memory[9] = 32'b00000000000000000000000000000000;  // nop
    memory[10]= 32'b00000000000000000000000000000000;  // nop
    memory[11]= 32'b00000000000000000000000000000000;  // nop
    memory[12]= 32'b00000000000000000000000000000000;  // nop
    memory[13]= 32'b00000000000000000000000000000000;  // nop
    memory[14]= 32'b00000000000000000000000000000000;  // nop
    memory[15]= 32'b00000000000000000000000000000000;  // nop
    memory[16]= 32'b00000000000000000000000000000000;  // nop
    memory[17]= 32'b00000000000000000000000000000000;  // nop
    memory[18]= 32'b00000000000000000000000000000000;  // nop 
    memory[19]= 32'b00000000000000000000000000000000;  // nop
    memory[20]= 32'b00000000000000000000000000000000;  // nop
    memory[21]= 32'b00000000000000000000000000000000;  // nop
    memory[22]= 32'b00000000000000000000000000000000;  // nop
    memory[23]= 32'b00000000000000000000000000000000;  // nop
    memory[24]= 32'b00000000000000000000000000000000;  // nop
    memory[25]= 32'b00000000000000000000000000000000;  // nop
    memory[26]= 32'b00000000000000000000000000000000;  // nop
    memory[27]= 32'b00000000000000000000000000000000;  // nop
    memory[28]= 32'b00000000000000000000000000000000;  // nop 
    memory[29]= 32'b00000000000000000000000000000000;  // nop
    memory[30]= 32'b00000000000000000000000000000000;  // nop
    memory[31]= 32'b00000000000000000000000000000000;  // nop
  end
always @(posedge clock)
	Instruction = memory[ReadAdd[4:0]];
endmodule



module mux4_1(regData,q1,q2,q3,q4,reg_no);
	input q1,q2,q3,q4;
	output regData;
	input [1:0]reg_no;
	
	assign regData= (reg_no[1]&reg_no[0]&q4) | (reg_no[1] &(~reg_no[0]) & q3) | ((~reg_no[1]) & reg_no[0]&q2) | ((~reg_no[0]) & (~reg_no[1]) &q1);

endmodule

module mux32_4to1(regData,q,reg_no);
	input [31:0][31:0]q;
	output [31:0]regData;
	input [4:0]reg_no;
	assign regData=q[reg_no];
	
endmodule

module decoder2_4 (register,reg_no);
	output reg [31:0]register;
	input [4:0]reg_no;
	integer j;	
	always @(reg_no)
	begin
	register=32'h0000000;
	register[reg_no]=1'b1;
	end
	
endmodule

module dff_async_clear(d, clearb, clock, q);
input d, clearb, clock;
output q;
reg q;
always @ (negedge clearb or posedge clock)
begin
if (!clearb) q <= 1'b0;
else q <= d;
end
endmodule

module reg_32bit(q,d,clk,reset);
	input [31:0]d;
	input clk,reset;
	output [31:0]q;
	genvar j;
	generate for (j=0;j<32;j=j+1) begin: register_loop
		dff_async_clear d1(d[j],reset,clk,q[j]);
	end
	endgenerate
endmodule
	
	
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

module bit32AND (out,in1,in2);
input [31:0] in1,in2;
output [31:0] out;
assign {out}=in1 &in2;
endmodule

module bit32OR (out,in1,in2);
input [31:0] in1,in2;
output [31:0] out;
assign {out}=in1 |in2;
endmodule

module FA_dataflow (Cout, Sum,In1,In2,Cin);
input In1,In2;
input Cin;
output Cout;
output Sum;
assign {Cout,Sum}=In1+In2+Cin;
endmodule

module FA_32dataflow(Cout,Sum,In1,In2,Cin);
input [31:0]In1;
input [31:0]In2;
input Cin;
output Cout;
output [31:0]Sum;
wire [32:0]temp;
assign temp[0]=Cin;
integer i;
wire [31:0]In2_temp;
assign In2_temp = Cin? ~In2 : In2;
genvar j;
generate for (j=0;j<32;j=j+1) begin: FA_loop
FA_dataflow f1(temp[j+1],Sum[j],In1[j],In2_temp[j],temp[j]);
end
endgenerate
assign Cout=temp[32];
endmodule

module mux2to1(out,sel,in1,in2);
input in1,in2,sel;
output out;
wire not_sel,a1,a2;
not (not_sel,sel);
and (a1,sel,in2);
and (a2,not_sel,in1);
or(out,a1,a2);
endmodule

module  Mux8Bit_2To1(out, select, in1, in2);
  input [7:0] in1, in2;
  input select;
  output  [7:0] out;
  genvar  j;
  generate  for(j = 0; j < 8; j = j + 1)  
    begin:  mux_loop
      mux2to1 Mux(out[j], select, in1[j], in2[j]);
    end
  endgenerate
endmodule

module  mux32Bit_2To1(out, select, in1, in2);
  input [31:0] in1, in2;
  input select;
  output  [31:0] out;
  Mux8Bit_2To1 Mux1(out[7:0], select, in1[7:0], in2[7:0]);
  Mux8Bit_2To1 Mux2(out[15:8], select, in1[15:8], in2[15:8]);
  Mux8Bit_2To1 Mux3(out[23:16], select, in1[23:16], in2[23:16]);
  Mux8Bit_2To1 Mux4(out[31:24], select, in1[31:24], in2[31:24]);
endmodule

module  mux32Bit_4To1(out, select, in1, in2, in3, in4);
  input [31:0]  in1, in2, in3, in4;
  input [1:0] select;
  output  [31:0]  out;
  wire  [31:0]  w1, w2;
  mux32Bit_2To1 Mux0(w1[31:0], select[0], in1[31:0], in2[31:0]);
  mux32Bit_2To1 Mux1(w2[31:0], select[0], in3[31:0], in4[31:0]);
  mux32Bit_2To1 Mux2(out[31:0], select[1], w1[31:0], w2[31:0]);
endmodule



module ALU(A,B,Binvert,Cin,op,Zero,res,Cout);
	output [31:0]res;
	output Cout,Zero;
	input [31:0]A,B;
	input [1:0]op;
	input Binvert,Cin;
	wire  [31:0]  wAnd, wOr, wAdd, wMux, notB;
	assign Zero = A == B ? 1'b1 : 1'b0;
    assign  {notB} = ~B;
    bit32AND  And(wAnd, A, B);
	bit32OR Or(wOr, A, B);
	FA_32dataflow  Add(Cout, wAdd, A, B, Binvert);
	mux32Bit_4To1 Mux2(res, op, wAnd, wOr, wAdd, 32'h00000000);
endmodule

module  ALUControlUnit(Op, Func, ALUOp0, ALUOp1);
  input [5:0] Func;
  input ALUOp0, ALUOp1;
  output  [2:0] Op;
  assign  Op[0] = ALUOp1 & (Func[3] | Func[0]);
  assign  Op[1] = (~ALUOp1) | (~Func[2]);
  assign  Op[2] = ALUOp0 | (ALUOp1 & Func[1]);
endmodule

module  MainControlUnit(RegDst,Jump, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, ALUOp0, ALUOp1, Op);
  output  RegDst,Jump, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, ALUOp0, ALUOp1;
  input [5:0] Op;
  wire  Rformat, lw, sw, beq;
  assign  Rformat = (~Op[5])&(~Op[4])&(~Op[3])&(~Op[2])&(~Op[1])&(~Op[0]);
  assign  lw = (Op[5])&(~Op[4])&(~Op[3])&(~Op[2])&(Op[1])&(Op[0]);
  assign  sw = (Op[5])&(~Op[4])&(Op[3])&(~Op[2])&(Op[1])&(Op[0]);
  assign  beq = (~Op[5])&(~Op[4])&(~Op[3])&(Op[2])&(~Op[1])&(~Op[0]);
  assign  J = (~Op[5])&(~Op[4])&(~Op[3])&(~Op[2])&(Op[1])&(~Op[0]);
  assign  Jump = J;
  assign  ALUSrc = lw | sw;
  assign  MemToReg = lw;
  assign  RegWrite = Rformat | lw;
  assign  MemRead = lw;
  assign  MemWrite = sw;
  assign  RegDst = Rformat;
  assign  Branch = beq;
  assign  ALUOp0 = Rformat;
  assign  ALUOp1 = beq;
endmodule

module data_memory(address,write_data,read_data,memread,memwrite,clk);
	input [31:0]address;
	input [31:0]write_data;
	input memread,memwrite,clk;
	output reg [31:0]read_data;
	reg [31:0] memory[31:0];
		initial begin
	  memory[0] = 32'b00000000000000000000000000000000;  // nop
    memory[1] = 32'b00000000000000000000000001010100;  // Value of 84
    memory[2] = 32'b00000000000000000000000000001011;  // Value of 11
    memory[3] = 32'b00000000000000000000000000000000;  // nop
    memory[4] = 32'b00000000000000000000000000000000;  // nop
    memory[5] = 32'b00000000000000000000000000000000;  // nop
    memory[6] = 32'b00000000000000000000000000000000;  // nop
    memory[7] = 32'b00000000000000000000000000000000;  // nop
    memory[8] = 32'b00000000000000000000000000000000;  // nop
    memory[9] = 32'b00000000000000000000000000000000;  // nop
    memory[10]= 32'b00000000000000000000000000000000;  // nop
    memory[11]= 32'b00000000000000000000000000000000;  // nop
    memory[12]= 32'b00000000000000000000000000000000;  // nop
    memory[13]= 32'b00000000000000000000000000000000;  // nop
    memory[14]= 32'b00000000000000000000000000000000;  // nop
    memory[15]= 32'b00000000000000000000000000000000;  // nop
    memory[16]= 32'b00000000000000000000000000000000;  // nop
    memory[17]= 32'b00000000000000000000000000000000;  // nop
    memory[18]= 32'b00000000000000000000000000000000;  // nop
    memory[19]= 32'b00000000000000000000000000000000;  // nop
    memory[20]= 32'b00000000000000000000000000000000;  // nop
    memory[21]= 32'b00000000000000000000000000000000;  // nop
    memory[22]= 32'b00000000000000000000000000000000;  // nop
    memory[23]= 32'b00000000000000000000000000000000;  // nop
    memory[24]= 32'b00000000000000000000000000000000;  // nop
    memory[25]= 32'b00000000000000000000000000000000;  // nop
    memory[26]= 32'b00000000000000000000000000000000;  // nop
    memory[27]= 32'b00000000000000000000000000000000;  // nop
    memory[28]= 32'b00000000000000000000000000000000;  // nop
    memory[29]= 32'b00000000000000000000000000000000;  // nop
    memory[30]= 32'b00000000000000000000000000000000;  // nop
    memory[31]= 32'b00000000000000000000000000000000;  // nop  
  end
	reg register;
	always @ (posedge clk)
		begin
		if (memread==1)
			read_data=memory[address[4:0]];
		else if (memwrite==1)
			memory[address[4:0]]=write_data;
		end
endmodule

module sign_Extender(instr,outinstr);
	input [15:0]instr;
	output reg [31:0]outinstr;
	
	always@(*)
	begin
	if (instr[15]==1) 
		begin
		outinstr[31:16]=16'b1111111111111111;
		outinstr[15:0]=instr;
		end
	else
		begin
			outinstr[31:16]=16'b0000000000000000;
			outinstr[15:0]=instr;
		end
	end
endmodule

module shifter(out,in);
	input [31:0]in;
	output [31:0]out;
	assign out={in[29:0],1'b0,1'b0};
endmodule	

module PC_gen(clk,rst,count);
	input clk,rst;
	output reg[31:0]count;
	always @(posedge clk)
	begin
	if (rst)
	count=0;
	else
	count=count+1;
	end
	
endmodule

module concatJuPC(out, J, PC);
  input [31:0] J, PC;
  output [31:0] out;
  assign {out} = {{PC[31:28]}, {J[27:0]}};
endmodule

module mux5Bit_2To1(out,sel,in1,in2);
input [4:0] in1,in2;
output [4:0] out;
input sel;
genvar j;
generate for(j=0;j<5;j=j+1) begin: mux_loop
mux2to1 m1(out[j],sel,in1[j],in2[j]);
end
endgenerate
endmodule
	
module SCDataPath(ALUout,PCcur,PC,clock,reset);
	input [31:0]PC;
	input clock,reset;
	output [31:0]PCcur,ALUout;
	reg [31:0]PCcur;
	wire [31:0]Instruction,outinstr,outinstr2,j_instr,jump_addr;
	wire [31:0]temp,ReadData1,ReadData2,PC1,PC2,PC3,B,read_data,ALUout,branch_addr,WriteData;
	wire Carry1,Carry2,Carry3;
	wire RegDst, Jump, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch,bz;
	wire [1:0] ALUOp;
	wire [2:0]Op;
	wire [4:0]WriteReg,ReadReg1,ReadReg2;
	
	Instruction_memory i1(PC,Instruction,clock);
	FA_32dataflow f1(Carry1,PC1,PC,32'h4,1'b0);
	assign temp = {{6'b00000},{Instruction[25:0]}};
	shifter s1(j_instr,temp);
	concatJuPC c1(jump_addr,j_instr,PC1);
	sign_Extender s2(Instruction[15:0],outinstr);
	shifter s3(outinstr2,outinstr);
	FA_32dataflow f2(Carry2,PC2,PC1,outinstr2,1'b0);
	
	
	MainControlUnit m1(RegDst,Jump, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, ALUOp[0], ALUOp[1], Instruction[31:26]);
	mux5Bit_2To1 m2(WriteReg,RegDst,Instruction[20:16],Instruction[15:11]);
	RegFile r1(clock,reset,Instruction[25:21], Instruction[20:16], WriteData,WriteReg,1'b0,ReadData1,ReadData2);
	mux32Bit_2To1 m3(B,ALUSrc,ReadData2,outinstr);
	ALUControlUnit a1(Op, Instruction[5:0], ALUOp[0], ALUOp[1]);
	ALU a2(ReadData1,B,Op[2],Op[2],Op[1:0],Zero,ALUout,Carry3);
	
	and a2(bz,Branch,Zero);
	mux32Bit_2To1 m4(branch_addr,bz,PC1,PC2);
	mux32Bit_2To1 m5(PC3,Jump,jump_addr,branch_addr);
	
	data_memory d1(ALUout,ReadData2,read_data,MemRead,MemWrite,clock);
	mux32Bit_2To1 m6(WriteData,MemToReg,ALUout,read_data);
	RegFile r2(clock,reset,Instruction[25:21], Instruction[20:16], WriteData,WriteReg,RegWrite,ReadData1,ReadData2);
	
	initial
	PCcur = PC;
	
	always@ (negedge clock)
	PCcur = PC3;
endmodule

module TBSCDataPath;
  reg clock, reset;
  reg [31:0]  PC;
  wire  [31:0]  ALUOutput, PCCurrent;
  SCDataPath  SCDP(ALUOutput, PCCurrent, PC, reset, clock);
  initial begin
    $monitor($time, " :PC = %b, Reset = %b, Clock = %b, NextPC = %b, ALUOutput = %b.", PC, reset, clock, PCCurrent, ALUOutput);
    #0  clock = 1'b0; PC = 32'd20; reset = 1'b0;
    #15 reset = 1'b1;
    #10 PC = 32'd12;
    #40 PC = PCCurrent;
    #40 PC = PCCurrent;
    #50 $finish;
  end
  always  begin
    #10 clock = ~clock;
  end
endmodule	

	
	