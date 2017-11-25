`include"jkff.v"
module tb_jkff;
reg  clk, J,K;
wire q;
initial
	clk=0;
	
	always
	#5 clk=~clk;
jkff dff (clk,J,K,q); // Or dff_async_clear dff (d, clk, rst, q);
//Always at rising edge of clock display the signals
always @(posedge clk)begin
$display("J=%b, K=%b,  clk=%b, q=%b\n", J,K, clk, q);
end
//Module to generate clock with period 10 time units

initial
 begin
J=1; K=1;
#5
J=1; K=0;
#8
J=1; K=1;
#11
J=0; K=0;
#13
$finish;
end
initial
begin
$dumpfile("jkFF.vcd"); $dumpvars;
end
endmodule