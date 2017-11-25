`include "mux32Bit_2To1.v"
module  mux32Bit_4To1(out, select, in1, in2, in3, in4);
  input [31:0]  in1, in2, in3, in4;
  input [1:0] select;
  output  [31:0]  out;
  wire  [31:0]  w1, w2;
  mux32Bit_2To1 Mux0(w1[31:0], select[0], in1[31:0], in2[31:0]);
  mux32Bit_2To1 Mux1(w2[31:0], select[0], in3[31:0], in4[31:0]);
  mux32Bit_2To1 Mux2(out[31:0], select[1], w1[31:0], w2[31:0]);
endmodule