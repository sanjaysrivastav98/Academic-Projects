`include "FA_32dataflow.v"
module tb_FA_32df;
reg [31:0]in1;
reg [31:0]in2;
reg Cin;
wire Cout;
wire [31:0]sum;

FA_32dataflow f1(Cout,sum,in1,in2,Cin);

initial
begin
$monitor("in1=%d, in2=%d, cin=%b,cout=%b, sum=%d",in1,in2,Cin,Cout,sum);

#10 Cin=1'b0; in1=32'ha5a5;in2=32'h1212;
#20 Cin=1'b1; in1=32'd100;in2=32'd50;
#100 $finish;

end
endmodule