`include "Instruction_memory.v"
module tb_instmem;
reg [4:0]Regadd;
wire [31:0]instr;
Instruction_memory i(Regadd,instr);
