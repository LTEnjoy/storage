clc;
clear;
close all;
%清空环境中的变量
t0 = clock;                                                   %程序计时开始
%
%%%%%%%%%%%%%%%%%%%初始化%%%%%%%%%%%%%%%%%
city =  [16.4700   96.1000
     16.4700   94.4400
     22.0900   94.5400
     22.3900   93.3700
     25.2300   97.2400
     22.0000   96.0500
     20.4700   97.0200
     17.2000   96.2900
     15.3000   97.3800
     14.0500   98.1200
     16.5300   97.3800
     21.5200   95.5900
     19.4100   97.1300
     20.0900   92.5500];
n = size(city,1);                                        %城市距离初始化
D =  squareform(pdist(city));                                                   

m=50;                                                      %蚂蚁数量
alpha = 1;                                                     % 信息素重要程度因子
beta = 1;                                                    % 启发函数重要程度因子
v = 0.5;                                                      % 信息素挥发因子
Q = 1;                                     % 信息因子常系数
H= 1./D;                                             % 启发函数
T= ones(n,n);                                                     % 信息素矩阵
Table = zeros(m,n);                                            % 路径记录表
iter = 1;                                                                % 迭代次数初值
iter_max = 100;                                                   % 最大迭代次数
best_route = zeros(iter_max,n);                                       % 各代最佳路径      
best_length = zeros(iter_max,1);                                     % 各代最佳路径的长度 
%
while iter<=iter_max
    % 随机产生每只蚂蚁的起点城市
    start = zeros(m,1);
    for i = 1:m
        temp = randperm(n);
        start(i) = temp(1);
    end
        Table(:,1) = start;
        city_index=1:n;
        for i = 1:m
            % 逐个城市路径选择
            for j = 2:n
                tabu = Table(i,1:(j - 1));                                                   % 已访问的城市集合
                allow =city_index( ~ismember(city_index,tabu));    % 筛选出未访问的城市集合
                P = zeros(1,length(allow));
                % 计算相连城市的转移概率
                for k = 1:length(allow)
                     P(k) = T(tabu(end),allow(k))^alpha * H(tabu(end),allow(k))^beta;
                end
                P = P/sum(P);
                % 轮盘赌法选择下一个访问城市
                Pc = cumsum(P);     %参加说明2(程序底部)
                target_index = find(Pc >= rand);
                target = allow(target_index(1));
                Table(i,j) = target;
            end
        end
    % 计算各个蚂蚁的路径距离
    Length = zeros(m,1);
    for i = 1:m
      Route = [Table(i,:) Table(i,1)];
      for j = 1:n
          Length(i) = Length(i) + D(Route(j),Route(j + 1));
      end
    end  
    %对最优路线和距离更新           
    if iter == 1
        [min_length,min_index] = min(Length);
        best_length(iter) = min_length; 
        best_route(iter,:) = Table(min_index,:);
    else
        [min_length,min_index] = min(Length);
        if min_length < best_length(iter-1)
             best_length(iter)=min_length;
             best_route(iter,:)=Table(min_index,:);
        else
            best_length(iter)=best_length(iter-1);
            best_route(iter,:)=best_route(iter-1,:);
        end
    end
    % 更新信息素
    Delta_T= zeros(n,n);
    % 逐个蚂蚁计算
    for i = 1:m
        % 逐个城市计算
        Route = [Table(i,:) Table(i,1)];
        for j = 1:n
            Delta_T(Route(j),Route(j+1)) = Delta_T(Route(j),Route(j+1)) + 1/D(Route(j),Route(j+1))* Q/Length(i);
        end
    end
    T= (1-v) * T + Delta_T;
    % 迭代次数加1，并清空路径记录表
    iter = iter + 1;
    Table = zeros(m,n);             
end
%--------------------------------------------------------------------------
% 结果显示
shortest_route=best_route(end,:);                 %选出最短的路径中的点
short_length=best_length(end);
Time_Cost=etime(clock,t0);
disp(['最短距离:' num2str(short_length)]);
disp(['最短路径:' num2str([shortest_route shortest_route(1)])]);
disp(['程序执行时间:' num2str(Time_Cost) '秒']);
%--------------------------------------------------------------------------
% 绘图
figure(1)
%采用连线图画起来
plot([city(shortest_route,1);city(shortest_route(1),1)], [city(shortest_route,2);city(shortest_route(1),2)],'o-');
for i = 1:size(city,1)
    %对每个城市进行标号
    text(city(i,1),city(i,2),['   ' num2str(i)]);
end
xlabel('城市位置横坐标')
ylabel('城市位置纵坐标')
title(['蚁群算法最优化路径(最短距离）:' num2str(short_length) ''])
 
figure(2)
%画出收敛曲线
plot(1:iter_max,best_length,'b')
xlabel('迭代次数')
ylabel('距离')
title('迭代收敛曲线')