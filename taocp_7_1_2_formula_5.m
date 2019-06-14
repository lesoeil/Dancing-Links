x13 = zeros(1,16);
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
                
                x5 = bitand(~x1, ~x3);
                x6 = bitand(x5, ~x2);                
                x7 = bitand(x5, ~x4);
                x8 = bitor(x6, x7);
                
                x9 = bitand(x2, x3);
                x10 = bitand(x9, x4);
                x11 = bitand(x1, x2);
                x12 = bitor(x10, x11);
                
                x13(i) = bitor(x8, x12);
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