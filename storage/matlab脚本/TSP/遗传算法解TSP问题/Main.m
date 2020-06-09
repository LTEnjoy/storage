clear;
close all;
clc;

tStart = tic; % �㷨��ʱ��
 
%%%%%%%%%%%%�Զ������%%%%%%%%%%%%%
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
popSize = 100; % �Ŵ��㷨��Ⱥ��С
crossoverProbabilty = 0.85; %�������
mutationProbabilty = 0.05; %�������
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
 
gbest = Inf;%��С����
 
% �����������ɵĳ��о���
distances = squareform(pdist(cities')); %����õ����еľ������D

% ������Ⱥ��ÿ���������һ��·��
pop = zeros(popSize, cityNum);
for i=1:popSize
    pop(i,:) = randperm(cityNum); 
end
offspring = zeros(popSize,cityNum);
%����ÿ������С·�����ڻ�ͼ
minPathes = zeros(maxGEN,1);
 
% GA�㷨
for  gen=1:maxGEN
 
    % ������Ӧ�ȵ�ֵ����·���ܾ���
    [fval, sumDistance, minPath] = fitness(distances, pop);
    minPathes(gen,1) = minPath; 
 
    % ������ѡ��
    tournamentSize=4; %���ô�С
    for k=1:popSize
        % ѡ�񸸴����н���
        tourPopDistances=zeros(tournamentSize,1);
        for i=1:tournamentSize
            randomRow = randi(popSize);
            tourPopDistances(i,1) = sumDistance(randomRow,1);
        end
 
        % ѡ����õģ���������С��
        parent1  = min(tourPopDistances);
        [parent1X,parent1Y] = find(sumDistance==parent1,1, 'first');
        parent1Path = pop(parent1X(1,1),:);
        offspring(k,:) = parent1Path;
    end
    pop = offspring;
    
    %������Ӧ�Ȱ�˳������֮����н���
     [fval, sumDistance, minPath] = fitness(distances, pop);
     [~,rank] = sort(sumDistance);
     for k = 1:2:popSize
        parent1 = pop(rank(k),:);
        parent2 = pop(rank(k+1),:);
        pop(rank(k),:) = crossover(parent1, parent2, crossoverProbabilty);%����
        pop(rank(k+1),:) = crossover(parent2, parent1, crossoverProbabilty);%����
     end
     
     %�Ӵ����б���
     for k = 1:popSize
         pop(k,:) = mutate(pop(k,:), mutationProbabilty);%����
    end
     
    % ����
    % ������ǰ״̬�µ����·��
    if minPath < gbest
        gbest = minPath;
    end
end
paint(cities, pop, gbest, sumDistance,gen);
fprintf('���·��:%.2fKM \n',minPath);
figure 
plot([1:300],minPathes');
title('��������ͼ��ÿһ�������·����');
ylabel('·������');
xlabel('��������');
grid on
tEnd = toc(tStart);
fprintf('ʱ��:%d ��  %f ��.\n', floor(tEnd/60), rem(tEnd,60));