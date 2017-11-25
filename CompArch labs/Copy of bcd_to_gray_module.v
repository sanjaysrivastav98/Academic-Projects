module bcd_to_gray_module(a,b,c,d,e,f,g,h);
	input a,b,c,d;
	output e,f,g,h;
	
	or a1(e,0,a);
	xor a2(f,a,b);
	xor a3(g,b,c);
	xor a4(h,c,d);
endmodule