n = 4;
x = zeros(1,n);

for k = 1:n
    x(k) = (2^(2^n) - 1) / (2^(2^(n-k)) +1);
end
