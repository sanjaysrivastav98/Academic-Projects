module mc_controller(Op,S,NS,RegDst,RegWrite,ALUSrcA,ALUSrcB,ALUOp,PCSource,MemToReg,IRWrite,MemWrite,MemRead,IorD,PCWriteCond,PCWrite);
	input [5:0]Op;
	input [3:0]S;
	output [3:0]NS;
	output RegDst,RegWrite,ALUSrcA,MemToReg,IRWrite,MemWrite,MemRead,IorD,PCWriteCond,PCWrite;
	output [1:0]ALUSrcB,ALUOp,PCSource;
	
	assign PCWrite = (~S[0]&~S[1]&~S[2]&~S[3] | S[0]&~S[1]&~S[2]&S[3]);
	assign PCWriteCond= ~S[0]&~S[1]&~S[2]&S[3];
	assign IorD = S[0]&S[1]&~S[2]&~S[3] | S[0]&~S[1]&S[2]&~S[3];
	assign MemRead = ~S[0] & ~S[1]&~S[2]&~S[3] | S[0]&S[1]&~S[2]&~S[3];
	assign MemWrite = S[0]&~S[1]&S[2]&~S[3];
	assign IRWrite = ~S[0]&~S[1]&~S[2]&~S[3];
	assign MemToReg = ~S[0]&~S[1]&S[2]&~S[3];
	assign PCSource[1] = S[0]&~S[1]&~S[2]&S[3];
	assign PCSource[0]= ~S[0]&~S[1]&~S[2]&S[3];
	assign ALUOp[1] = ~S[0]&S[1]&S[2]&~S[3];
	assign ALUOp[0]= ~S[0]&~S[1]&~S[2]&S[3];
	assign ALUSrcB[1]= S[0]&~S[1]&~S[2]&~S[3] | ~S[0]&S[1]&~S[2]&~S[3];
	assign ALUSrcB[0]= ~S[0]&~S[1]&~S[2]&~S[3] | S[0]&~S[1]&~S[2]&~S[3];
	assign ALUSrcA = ~S[0]&S[1]&~S[2]&~S[3] | ~S[0]&S[1]&S[2]&~S[3] | ~S[0]&~S[1]&~S[2]&S[3];
	assign RegWrite = ~S[0]&~S[1]&S[2]&~S[3] | S[0]&S[1]&S[2]&~S[3];
	assign RegDst = S[0]&S[1]&S[2]&~S[3];
	assign NS[3]= S[0]&~S[1]&~S[2]&~S[3]&~Op[0]&Op[1]&~Op[2]&~Op[3]&~Op[4]&~Op[5] | S[0]&~S[1]&~S[2]&~S[3]&~Op[0]&~Op[1]&Op[2]&~Op[3]&~Op[4]&~Op[5];
	assign NS[2]= S[0]&S[1]&~S[2]&~S[3] | ~S[0]&S[1]&S[2]&~S[3] | S[0]&~S[1]&~S[2]&~S[3]&~Op[0]&~Op[1]&~Op[2]&~Op[3]&~Op[4]&~Op[5] | ~S[0]&S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&Op[3]&~Op[4]&Op[5];
	assign NS[1]= ~S[0]&S[1]&S[2]&~S[3] | S[0]&~S[1]&~S[2]&~S[3]&~Op[0]&~Op[1]&~Op[2]&~Op[3]&~Op[4]&~Op[5] | S[0]&~S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&~Op[3]&~Op[4]&Op[5] | S[0]&~S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&Op[3]&~Op[4]&Op[5] | ~S[0]&S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&~Op[3]&~Op[4]&Op[5];
	assign NS[0] = ~S[0]&~S[1]&~S[2]&~S[3] | ~S[0]&S[1]&S[2]&~S[3] | S[0]&~S[1]&~S[2]&~S[3]&~Op[0]&Op[1]&~Op[2]&~Op[3]&~Op[4]&~Op[5] | ~S[0]&S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&Op[3]&~Op[4]&Op[5] | ~S[0]&S[1]&~S[2]&~S[3]&Op[0]&Op[1]&~Op[2]&~Op[3]&~Op[4]&Op[5];
	
endmodule