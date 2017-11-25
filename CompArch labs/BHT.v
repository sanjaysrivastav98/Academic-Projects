module BHT(clk,out,inp,writeData,WR);
	input [9:0]inp;
	input [1:0]writeData;
	input WR,clk;
	output reg[1:0]out;
	reg [1:0]bht[1023:0];
	integer i;
	initial begin
	for (i=0;i<1024;i=i+1)
		bht[i]=2'b00;
	end
	always @(WR or writeData)
	begin
		if(WR==1'b1)bht[inp]=writeData;
		else out=bht[inp];
	$display("bht= %b",bht[inp]);
	end
	
endmodule

module MUX1(out,sel,in1,in2);
	input [1:0]in1,in2;
	input sel;
	output [1:0]out;
	assign out[0]=~sel&in1[0] | sel&in2[0];
	assign out[1]=~sel&in1[1] | sel&in2[1];
endmodule

module PREDICTOR(X,N,C);
	input X;
	input [1:0]C;
	output reg[1:0]N;
	always @(*)
	begin
	if     (C==2'b00 && X==1'b1) N=2'b01;
	else if(C==2'b00 && X==1'b0) N=2'b00;
	else if(C==2'b01 && X==1'b1) N=2'b11;
	else if(C==2'b01 && X==1'b0) N=2'b00;
	else if(C==2'b11 && X==1'b1) N=2'b11;
	else if(C==2'b11 && X==1'b0) N=2'b10;
	else if(C==2'b10 && X==1'b0) N=2'b00;
	else if(C==2'b10 && X==1'b1) N=2'b11;
	end
endmodule

module INTG(clk,addr,actual,previous);
	input clk,actual,previous;
	input [9:0]addr;
	wire [1:0]NS,NS2,NS3,NS4;
	reg [1:0]s1,s2;
	wire write1,write2;
	wire [1:0]state,state2;
	
	BHT b1(clk,state,addr,NS3,write1);
	BHT b2(clk,state2,addr,NS4,write2);
	
	MUX1 m(NS,previous,state2,state);
	PREDICTOR p(actual,NS2,NS);
	
	/*always @(*)
	begin
	if(previous==1)begin
		#1 write2 = 1'b0; write
	end
	end*/
	
	assign write2 = previous? 1'b0 : 1'b1;
	assign NS4 = previous? NS4: NS2;
	assign write1 = previous? 1'b1 : 1'b0;
	assign NS3 = previous? NS2 :NS3;
	
	
endmodule
	
	

module tb;
	reg [9:0]addr;
	reg actual,prev;
	reg clk;
	INTG i(clk,addr,actual,prev);
	
	always
	begin
	#2 clk=~clk;prev <= actual;
	end
	initial begin
	$monitor($time," clk=%b,addr=%b,actual =%b,bht1=%2b,bht2=%2b,prev=%b",clk,addr,actual,i.b1.out,i.b2.out,i.previous);
	#0 addr=10'b0011110000;prev=1'b0;clk=1'b0;
	#2 actual = 1'b0;
	#2 actual = 1'b1;
	#2 actual = 1'b1;
	#2 actual = 1'b1;
	#2 actual = 1'b0;
	#10 $finish;
	end
	
endmodule
	
	
	