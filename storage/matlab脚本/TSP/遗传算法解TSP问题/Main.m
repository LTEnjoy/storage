clear;
close all;
clc;

tStart = tic; % 算法计时器
 
%%%%%%%%%%%%自定义参数%%%%%%%%%%%%%
cities =  [16.4700   96.1000
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
 
cityNum = size(cities,1);
cities = cities';

maxGEN = 300;
popSize = 100; % 遗传算法种群大小
crossoverProbabilty = 0.85; %交叉概率
mutationProbabilty = 0.05; %变异概率
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
gbest = Inf;%最小距离
 
% 计算上述生成的城市距离
distances = squareform(pdist(cities')); %计算得到城市的距离矩阵D

% 生成种群，每个个体代表一个路径
pop = zeros(popSize, cityNum);
for i=1:popSize
    pop(i,:) = randperm(cityNum); 
end
offspring = zeros(popSize,cityNum);
%保存每代的最小路径便于画图
minPathes = zeros(maxGEN,1);
 
% GA算法
for  gen=1:maxGEN
 
    % 计算适应度的值，即路径总距离
    [fval, sumDistance, minPath] = fitness(distances, pop);
    minPathes(gen,1) = minPath; 
 
    % 锦标赛选择法
    tournamentSize=4; %设置大小
    for k=1:popSize
        % 选择父代进行交叉
        tourPopDistances=zeros(tournamentSize,1);
        for i=1:tournamentSize
            randomRow = randi(popSize);
            tourPopDistances(i,1) = sumDistance(randomRow,1);
        end
 
        % 选择最好的，即距离最小的
        parent1  = min(tourPopDistances);
        [parent1X,parent1Y] = find(sumDistance==parent1,1, 'first');
        parent1Path = pop(parent1X(1,1),:);
        offspring(k,:) = parent1Path;
    end
    pop = offspring;
    
    %父代适应度按顺序两两之间进行交叉
     [fval, sumDistance, minPath] = fitness(distances, pop);
     [~,rank] = sort(sumDistance);
     for k = 1:2:popSize
        parent1 = pop(rank(k),:);
        parent2 = pop(rank(k+1),:);
        pop(rank(k),:) = crossover(parent1, parent2, crossoverProbabilty);%交叉
        pop(rank(k+1),:) = crossover(parent2, parent1, crossoverProbabilty);%交叉
     end
     
     %子代进行变异
     for k = 1:popSize
         pop(k,:) = mutate(pop(k,:), mutationProbabilty);%变异
    end
     
    % 更新
    % 画出当前状态下的最短路径
    if minPath < gbest
        gbest = minPath;
    end
end
paint(cities, pop, gbest, sumDistance,gen);
fprintf('最短路径:%.2fKM \n',minPath);
figure 
plot([1:300],minPathes');
title('收敛曲线图（每一代的最短路径）');
ylabel('路径长度');
xlabel('迭代次数');
grid on
tEnd = toc(tStart);
fprintf('时间:%d 分  %f 秒.\n', floor(tEnd/60), rem(tEnd,60));