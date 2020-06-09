%���Թ滮�����С�ų�
function [way,distance] = Dyn(S1,S2)
%S1�����У��ֱ������һ��S1��ʱ�䡢����һ��S2��ʱ�䡢
%�����S1��̵�ʱ�䡢����S1���ʱ�����һ�������㡣S2���ơ�
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