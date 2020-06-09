%result返回最近距离
%point返回的是最近距离的两个点的坐标，第一列为x,第二列为y
%D是所有点的坐标矩阵，第一列是x,第二列是y，每一行x，y一一对应
%利用分治法递归求解

function [result,point] = Strassen(D)
if size(D,1) == 1
    result = inf;
    point = [];
    return;
elseif size(D,1) == 2
        result = pdist(D);
        point = D;
        return;
else
    n = ceil(size(D,1)/2);
    [minLeft,pointLeft] = Strassen(D(1:n,:));
    [minRight,pointRight] = Strassen(D(n:end,:));
    minimum = min(minLeft,minRight);
    if minimum == minLeft
        point = pointLeft;
    else
        point = pointRight;
    end
    center = D(n,1);
    left = [0,0];
    right = [0,0];
    i = n-1;
    while i > 0 && center - D(i,1) <minimum
        left = [left;D(i,:)];
        i = i-1;
    end
    left(1,:) = [];
    
    i = n+1;
    while i<size(D,1) && D(i,1) - center <minimum
        right = [right;D(i,:)];
        i = i+1;
    end
    right(1,:) = [];
    
    S = [left;D(n,:);right];
    [S(:,2),rank] = sort(S(:,2));
    t = zeros(size(S,1),1);
    for i = 1:size(S,1)
        t(i) = S(rank(i),1);
    end
    S(:,1) = t;
    
    for i = 1:size(S,1)
        for j = i+1:size(S,1)
            if j > size(S,1)
                break;
            end
            dis = pdist([S(i,:);S(j,:)]);
            if dis < minimum
                minimum = dis;
                point = [S(i,:);S(j,:)];
            end
        end
    end
    result = minimum;
end
