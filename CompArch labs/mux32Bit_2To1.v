`include "Mux8Bit_2To1.v"
module  mux32Bit_2To1(out, select, in1, in2);
  input [31:0] in1, in2;
  input select;
  output  [31:0] out;
  Mux8Bit_2To1 Mux1(out[7:0], select, in1[7:0], in2[7:0]);
  Mux8Bit_2To1 Mux2(out[15:8], select, in1[15:8], in2[15:8]);
  Mux8Bit_2To1 Mux3(out[23:16], select, in1[23:16], in2[23:16]);
  Mux8Bit_2To1 Mux4(out[31:24], select, in1[31:24], in2[31:24]);
endmodule