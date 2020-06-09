function [ fitnessvar, sumDistances,minPath] = fitness( distances, pop )
% 计算整个种群的适应度值
 
    [popSize, col] = size(pop);
    sumDistances = zeros(popSize,1);
    fitnessvar = zeros(popSize,1);
    for i=1:popSize
       for j=1:col-1
          sumDistances(i) = sumDistances(i) + distances(pop(i,j),pop(i,j+1));
       end 
          sumDistances(i) = sumDistances(i) + distances(pop(i,1),pop(i,14));
           fitnessvar(i,1) = 1/sumDistances(i,1);
    end
    minPath = min(sumDistances);
end