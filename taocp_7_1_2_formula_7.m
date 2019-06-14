x10 = zeros(1, 16);
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
            end
        end
    end
end