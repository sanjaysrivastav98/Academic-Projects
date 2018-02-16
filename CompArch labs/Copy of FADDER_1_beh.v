module FADDER_1_beh(A,B,C,S,Cout);
	input A;
	input B,C;
	output S,Cout;
	reg S,Cout;
	
	always@ (A or B)
		if(A==0 && B==0 && C==0)
			begin
				S=0;
				Cout=0;
			end
		else if((A==1 && B==0 && C==0) || (A==0 && B==1 && C==0) || (A==0 && B==0 && C==1))
			begin
				S=1;
				Cout=0;
			end
		else if((A==1 && B==1 && C==0) || (A==0 && B==1 && C==1) || (A==1 && B==0 && C==1))
			begin
				S=0;
				Cout=1;
			end
		else
			begin
				S=1;
				Cout=1;
			end
	endmodule