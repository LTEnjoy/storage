function info = Bellman(V,E,s)
%采用Bellman循环缩短法来求最短路径

%每个节点都有一个顶点标号，从1开始递增。使用时请自行编好号。
%info返回从起点到任意一个节点的最短距离，第一列为顶点标号，第二列为对应距离,第三列为该节点的父节点
%V代表节点个数
%E代表所有边的集合，第一列为边的起点标号，第二列为边的终点标号,第三列为权重（距离）
%s代表起始节点的标号

%初始化操作
info = zeros(V,3);
for i = 1:V
    info(i,1) = i;
    info(i,2) = inf;
end
info(s,2) = 0;  %起点的最短距离是0

%进行V-1次循环，每次循环都对每条边进行一次缩短法
for i = 1:V-1
    for j = 1:size(E,1)
        startLabel = E(j,1);
        endLabel = E(j,2);
        if info(startLabel) == inf
            continue;
        elseif info(startLabel,2) + E(j,3) < info(endLabel,2) %缩短法判断
            info(endLabel,2) = info(startLabel,2) + E(j,3);
            info(endLabel,3) = startLabel;
        end
    end
end

%再进行一次循环缩短法，判断是否有负权回路
for j = 1:size(E,1)
        startLabel = E(j,1);
        endLabel = E(j,2);
        if info(startLabel) == inf
            continue;
        elseif info(startLabel,2) + E(j,3) < info(endLabel,2) %缩短法判断
            disp("该有向图中含有负权回路！")
            info = 0;
            return;
        end
end
