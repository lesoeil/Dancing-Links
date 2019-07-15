x10 = zeros(1, 16);
x15 = zeros(1, 16);
lo = 1;
hi = 2;

for b4 = lo:hi
    for b3 = lo:hi
        for b2 = lo:hi
            for b1 = lo:hi
                x1 = b1-1;
                x2 = b2-1;
                x3 = b3-1;
                x4 = b4-1;
                i = 1+x1*8+x2*4+x3*2+x4*1;
                
                x5 = bitxor(x1, x2);
                x6 = bitxor(x5, x3);
                x7 = bitxor(x3, x4);
                x8 = bitand(x6, ~x7);                
                x9 = bitor(x1, x2);                
                x10(i) = bitxor(x8, x9);
                
                x11 = bitand(x1, x2);
                x12 = bitand(x3, x4);
                x13 = bitxor(x11, x12);
                x14 = bitand(x9, x7);
                x15(i) = bitor(x13, x14);
                
            end
        end
    end
end

%{
8  4  2  1
x1 x2 x3 x4
0000
0001
0100
0111
1100
1101
1110
1111
%}