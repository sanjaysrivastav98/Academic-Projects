module  ALUControlUnit(Op, Func, ALUOp0, ALUOp1);
  input [5:0] Func;
  input ALUOp0, ALUOp1;
  output  [2:0] Op;
  assign  Op[0] = ALUOp1 & (Func[3] | Func[0]);
  assign  Op[1] = (~ALUOp1) | (~Func[2]);
  assign  Op[2] = ALUOp0 | (ALUOp1 & Func[1]);
endmodule