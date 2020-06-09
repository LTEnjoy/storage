% 排队论模型
% 顾客到达过程服从泊松分布，相邻间隔为参数lambda的指数分布
% 服务时间服从参数为mu的指数分布
% 有s个并列服务台，全部占用后顾客排成一队等待

% 用于评价排队系统优劣的指标
% 符号含义：
% Ls(队长)：系统中总顾客数n的期望值
% Lq（排队长）：系统中排队等待的顾客数的期望值
% Ws（逗留时间）：一个顾客在系统中的全部停留时间
% Wq（等待时间）：一个顾客在系统中的排队等待时间
% 其他相关指标:
% 忙期：指从顾客到达空闲服务机构起到服务机构再次空闲的时间长度
% 忙期服务量：值一个忙期内系统平均完成服务的顾客数
% 损失率：指顾客到达排队系统，未接受服务而离去的概率
% 服务强度：ρ= λ/sμ

% 各项指标的计算公式（见保存的图片）

function [Lq, Ls, Ws, Wq] = MMS(s,lambda,mu)
ro=lambda/mu;
ros=ro/s;
sum1=0;
for i=0:(s-1) 
    sum1 = sum1+ro.^i/factorial(i);
end
sum2=ro.^s/factorial(s)/(1-ros);
p0=1/(sum1+sum2);
p=ro.^s.*p0/factorial(s)/(1-ros);
Lq=p.*ros/(1-ros);
Ls=Lq+ro;
Ws=Ls/lambda;
Wq=Lq/lambda;
fprintf('排队等待的平均人数为%5.2f人\n',Lq)
fprintf('系统内的平均人数为%5.2f人\n',Ls)
fprintf('平均逗留时间为%5.2f分钟\n',Ws*60)
fprintf('平均等待时间为%5.2f分种\n',Wq*60)

