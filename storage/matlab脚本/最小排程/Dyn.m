%线性规划解决最小排程
function [way,distance] = Dyn(S1,S2)
%S1有四列，分别代表到下一个S1的时间、到下一个S2的时间、
%到达该S1最短的时间、到达S1最短时间的上一个出发点。S2类似。
way = zeros(1,size(S1,1)-2);
for i = 2:size(S1,1)
    S1(i,3) = min(S1(i-1,3)+S1(i-1,1),S2(i-1,3)+S2(i-1,1));
    if S1(i,3) == S1(i-1,3)+S1(i-1,1)
        S1(i,4) = 1;
    else
        S1(i,4) = 2;
    end
    S2(i,3) = min(S1(i-1,3)+S1(i-1,2),S2(i-1,3)+S2(i-1,2));
    if S2(i,3) == S1(i-1,3)+S1(i-1,2)
        S2(i,4) = 1;
    else
        S2(i,4) = 2;
    end
end
distance = S1(end,3);
for i = size(S1,1):-1:3
    way(i-2) = S1(i,4);
end