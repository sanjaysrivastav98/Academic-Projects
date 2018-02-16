`include "data_memory.v"

module tb_data;
	reg [31:0]address,write_data;
	reg memread,memwrite;
	wire [31:0]read_data;
	data_memory d(address,write_data,read_data,memread,memwrite);
	initial
	begin
	$monitor($time," addr=%32h, write=%32h, r/w=%b%b, read=%32h",address,write_data,memread,memwrite,read_data);
	address=32'h0000000A;
	memread=1'b0;
	memwrite=1'b1;
	#5 write_data=32'hABCD0000;
	#5 memread=1'b1;memwrite=1'b0;
	#5 address=32'h00000003;
	#5 memread=1'b0;memwrite=1'b1;
	#5 write_data=32'h10000001;
	#100 $finish;
	
	end
	endmodule