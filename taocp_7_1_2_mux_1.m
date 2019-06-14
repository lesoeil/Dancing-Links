x6 = zeros(1,8);
lo = 1;
hi = 2;
for x1 = lo:hi
    for x2 = lo:hi
        for x3 = lo:hi
            x4 = bitand(x1-1, x2-1);
            x5 = bitand(~(x1-1), x3-1);
            i = 1+(x1-1)+(x2-1)*2+(x3-1)*4;
            x6(i) = bitor(x4, x5);
        end
    end
end