x8 = zeros(1,16);
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
                
                x5 = bitand(x2, ~x4);
                x6 = bitxor(x5, ~x3);
                x7 = bitand(x6, ~x1);
                
                x8(i) = bitxor(x7, x2);
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