module data_memory(address,write_data,read_data,memread,memwrite,clk);
	input [31:0]address;
	input clk;
	input [31:0]write_data;
	input memread,memwrite;
	output reg [31:0]read_data;
	reg [31:0] reginst[31:0];
	initial
		$readmemh("reg.txt",reginst);
	always @ (posedge clk )
		begin
		if (memread==1)
			read_data=reginst[address[4:0]];
		else if (memwrite==1)
			reginst[address[4:0]]=write_data;
		//$writememh("reg.txt",reginst);
		end
endmodule
	