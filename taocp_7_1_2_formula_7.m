x10 = zeros(1, 16);
x11 = zeros(1, 16);
x12 = zeros(1, 16);
x19 = zeros(1, 16);
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
                
                x5 = bitxor(x1, x3);
                x6 = bitxor(x1, x2);
                x7 = bitxor(x3, x4);
                x8 = bitor(x5, x6);
                x9 = bitxor(x6, x7);
                x10(i) = bitand(x8, ~x9);
                x11(i) = bitand(bitor(bitxor(x1,x4), x5), ~x9); %formual(7)
                x12(i) = bitand(bitor(x5, bitor(bitxor(x1,x4), x6)), ~x9);
                x13 = bitand(x1, x2);
                x14 = bitand(x3, x4);
                x15 = bitor(x13, x14);
                
                x16 = bitor(x1, x2);
                x17 = bitor(x3, x4);
                x18 = bitand(x16, x17);
                
                x19(i) = bitxor(x15, x18);
                %x19(i) = bitxor(bitor(bitand(x1, x2), bitand(x3, x4)), bitand(bitor(x1, x2), bitor(x3,x4)));%formula(8)
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