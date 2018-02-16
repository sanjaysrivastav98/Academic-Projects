`include "FA_dataflow.v"

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