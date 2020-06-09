function  Untitled2(a,y)
x = 2:18;
S = 1:18;
S(1) = (y(1)+y(2)+y(3))/3;  %S(1)取前三次平均价格的平均值
for k = x
    S(x) = a*y(x-1) + (1-a)*S(x-1);
end
x = 1:18;
p = polyfit(x,S,4); %找出x 和 S的拟合曲线
f=@(x) p(1)*x.^4+p(2)*x.^3+p(3)*x.^2+p(4)*x +p(5);
hold on
S = y;
for k = 19:24
    S = [S,f(k)];
end
fplot(f,[0,24]);
x = 1:24;
plot(x,S,'r+');
xlabel('时期 t/(*10天)');
ylabel('预测价格 S/元');
hold off;