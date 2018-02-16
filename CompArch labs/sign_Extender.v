module sign_Extender(instr,outinstr);
	input [15:0]instr;
	output reg [31:0]outinstr;
	
	always@(*)
	begin
	if (instr[15]==1) 
		begin
		outinstr[31:16]=16'b1111111111111111;
		outinstr[15:0]=instr;
		end
	else
		begin
			outinstr[31:16]=16'b0000000000000000;
			outinstr[15:0]=instr;
		end
	end
endmodule