`include "bit32AND.v"
module tb32bitand;
reg [31:0] IN1,IN2;
wire [31:0] OUT;
bit32AND a1 (OUT,IN1,IN2);
initial
begin
$monitor("in1=%32h in2=%32h out %32h",IN1,IN2,OUT);
IN1=32'hA5A5;
IN2=32'h5A5A;
#100 IN1=32'h5A5A;
#400 $finish;
end
endmodule