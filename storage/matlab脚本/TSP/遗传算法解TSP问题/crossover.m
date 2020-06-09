function [childPath] = crossover(parent1Path, parent2Path, prob)
% ����
 
    random = rand();
    if prob >= random
        [l, length] = size(parent1Path);
        childPath = zeros(l,length);
        setSize = floor(length/2) -1;
        offset = randi(setSize);
        for i=offset:setSize+offset-1
            childPath(1,i) = parent1Path(1,i);
        end
        iterator = 1;%�Ӵ���Ԫ��λ��
        j = 1;      %����2��Ԫ��λ��
        while any(childPath == 0)
            if childPath(1,iterator)~= 0
                iterator = iterator +1;
                continue;
            end
            if ~any(childPath == parent2Path(1,j))
                childPath(1,iterator) = parent2Path(1,j);
               iterator = iterator + 1;
            end
            j = j + 1;
        end
    else
        childPath = parent1Path;
    end
end