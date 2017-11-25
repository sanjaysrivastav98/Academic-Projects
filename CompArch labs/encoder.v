module encoder(op_code,function_code);
	input [7:0]function_code;
	output reg [2:0]op_code;
	always@(*)
	begin
	case(function_code)
	
		8'b00000001 : op_code = 3'b000;
		8'b00000010 : op_code = 3'b001;
		8'b00000100 : op_code = 3'b010;
		8'b00001000 : op_code = 3'b011;
		8'b00010000 : op_code = 3'b100;
		8'b00100000 : op_code = 3'b101;
		8'b01000000 : op_code = 3'b110;
		8'b10000000 : op_code = 3'b111;
		default 	: $display("ERROR in function_code");
	endcase
	end
endmodule