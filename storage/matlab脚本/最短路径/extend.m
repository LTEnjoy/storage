function distance = extend(D)
%多次延伸算法计算全点对最短路径
%D为节点的邻接矩阵，若不连通则对应点值为Inf,若连通则对应点值为距离权重
%distance为返回的最短路径矩阵，包含了两个点之间的最短距离大小

n = size(D,1);%获得该有向加权图的节点个数
distance = D;

for k = 1:n-2
    for i = 1:n
        for j = 1:n
            least = inf;
            for t = 1:n
                if least > distance(i,t)+distance(t,j)
                    least = distance(i,t)+distance(t,j);
                end
            end
            distance(i,j) = least;
        end
    end
    D = distance;
end