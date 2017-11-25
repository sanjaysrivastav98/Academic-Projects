`include "encoder.v"

module tb_encoder;
	reg [7:0]function_code;
	wire [2:0]op;
	encoder e(op,function_code);
	initial
	begin
	$monitor($time, " functioncode = %8b opcode = %3b",function_code,op);
	
	function_code = 8'b00000001;
	#10 function_code=8'b10000000;
	#20 function_code=8'b00000010;
	#30 function_code = 8'b 00100000;
	#40 $finish;
	
	end
	
	endmodule
	