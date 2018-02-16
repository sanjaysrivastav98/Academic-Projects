module bcd_to_gray_df(a,b,c,d,e,f,g,h);
	input a,b,c,d;
	output e,f,g,h;
	
	assign e=a|1,
		f=a^b,
		g=b^c,
		h=c^d;
endmodule
	