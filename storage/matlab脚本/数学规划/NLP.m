%非线性规划
%语句是[x,value] = fmincon(fun,x0,A,b,Aeq,beq,lb,ub,nonlcon,options)
%fun是需要自己定义的函数，x0是自变量的初始值，nonlcon是自己定义的非线性约束的条件，其他同线性规划
% 例如：f(x)=x1^2+x2^2+x3^2+8
% x1^2 - x2 + x3^2 >= 0
% x1 + x2^2 + x3^2 <= 20
% -x1 - x2^2 + 2 =0
% x2 + 2x3^2 = 3
% x1,x2,x3 >= 0

% 编写f(x)函数文件：
% function f = fun(x)
% f=x(1).^2+x(2).^2+x(3).^2+8;

% 再编写非线性约束文件：
% function [g,h] = nonlcon(x)
% g=[-x(1).^2+x(2)-x(3).^2, x(1)+x(2).^2+x(3).^3-20]; 这是不等式约束条件
% h=[-x(1)-x(2).^2+2, x(2)+2*x(3).^2-3];              这是等式约束条件

%最后调用fmincon函数
[x,value]=fmincon('fun',[0;0;0],[],[],[],[],zeros(3,1),[],'nonlcon');