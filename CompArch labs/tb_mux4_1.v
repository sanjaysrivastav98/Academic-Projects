`include "mux32_4to1.v"
module tb_mux4_1();
reg [31:0][31:0] IN;
wire [31:0] OUT;
reg [1:0]SEL;

mux32_4to1 m1(OUT,IN,SEL);

initial 
begin
$monitor(" ",IN1,IN2,IN3,IN4,OUT,SEL);

IN1=32'h 12344; IN2=32'h 12345; IN3=32'hafaf;IN4=32'h abcd;
#10 SEL= 2'b10;
#20 SEL=2'b01;
#30 SEL=2'b11;
#40 SEL= 2'b00;

#50 $finish;
end
endmodule

