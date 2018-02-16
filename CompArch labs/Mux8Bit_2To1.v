`include "mux2to1.v"
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