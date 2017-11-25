`include "bcd_to_gray_df.v"

module tb_bcd_to_gray;
	reg a,b,c,d;
	wire e,f,g,h;
	bcd_to_gray_df bcd_to_gray_gate (a,b,c,d,e,f,g,h);
	initial
		begin
			$monitor(,$time," bcd = %b%b%b%b grey = %b%b%b%b",a,b,c,d,e,f,g,h);
			#00 a=1'b0;b=1'b0;c=1'b0;d=1'b0;
			#10 a=1'b0;b=1'b0;c=1'b0;d=1'b1;
			#20 a=1'b0;b=1'b0;c=1'b1;d=1'b0;
			#30 a=1'b0;b=1'b0;c=1'b1;d=1'b1;
			#40 a=1'b0;b=1'b1;c=1'b0;d=1'b0;
			#50 a=1'b0;b=1'b1;c=1'b0;d=1'b1;
			#60 a=1'b0;b=1'b1;c=1'b1;d=1'b0;
			#70 a=1'b0;b=1'b1;c=1'b1;d=1'b1;
			#80 a=1'b1;b=1'b0;c=1'b0;d=1'b0;
			#90 a=1'b1;b=1'b0;c=1'b0;d=1'b1;
			#100 $finish;
		end
		
	initial
		begin
			$dumpfile("bcd_to_gray_testbench.vcd");
			$dumpvars;
		end

endmodule
	