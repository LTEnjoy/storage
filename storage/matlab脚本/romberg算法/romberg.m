function result = romberg(f,a,b,accuracy)
%romberg算法
% a积分下限
% b积分上限
% accuracy为精度（后一次减前一次的绝对值小于该精度则停止）
% f为函数
T = (b-a)/2 *(f(a) + f(b));
k = 1;
sum = 0;
for n = 1:2^(k-1)
    sum = sum+f(a + (2*n-1)/(2^k)*(b-a));
end
nextT = 1/2*T + (b-a)/(2^k)*sum;

while  abs(nextT - T)>=accuracy%调整精度
    T = nextT;
    k = k+1;
    sum = 0;
    for n = 1:2^(k-1)
        sum = sum+f(a + (2*n-1)/(2^k)*(b-a));
    end
    nextT = 1/2*T + (b-a)/(2^k)*sum;
end
result = nextT;