module  MainControlUnit(RegDst, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, ALUOp0, ALUOp1, Op);
  output  RegDst, ALUSrc, MemToReg, RegWrite, MemRead, MemWrite, Branch, ALUOp0, ALUOp1;
  input [5:0] Op;
  wire  Rformat, lw, sw, beq;
  assign  Rformat = (~Op[5])&(~Op[4])&(~Op[3])&(~Op[2])&(~Op[1])&(~Op[0]);
  assign  lw = (Op[5])&(~Op[4])&(~Op[3])&(~Op[2])&(Op[1])&(Op[0]);
  assign  sw = (Op[5])&(~Op[4])&(Op[3])&(~Op[2])&(Op[1])&(Op[0]);
  assign  beq = (~Op[5])&(~Op[4])&(~Op[3])&(Op[2])&(~Op[1])&(~Op[0]);
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