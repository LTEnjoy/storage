function result = romberg(f,a,b,accuracy)
%romberg�㷨
% a��������
% b��������
% accuracyΪ���ȣ���һ�μ�ǰһ�εľ���ֵС�ڸþ�����ֹͣ��
% fΪ����
T = (b-a)/2 *(f(a) + f(b));
k = 1;
sum = 0;
for n = 1:2^(k-1)
    sum = sum+f(a + (2*n-1)/(2^k)*(b-a));
end
nextT = 1/2*T + (b-a)/(2^k)*sum;

while  abs(nextT - T)>=accuracy%��������
    T = nextT;
    k = k+1;
    sum = 0;
    for n = 1:2^(k-1)
        sum = sum+f(a + (2*n-1)/(2^k)*(b-a));
    end
    nextT = 1/2*T + (b-a)/(2^k)*sum;
end
result = nextT;