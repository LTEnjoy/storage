function distance = extend(D)
%��������㷨����ȫ������·��
%DΪ�ڵ���ڽӾ���������ͨ���Ӧ��ֵΪInf,����ͨ���Ӧ��ֵΪ����Ȩ��
%distanceΪ���ص����·�����󣬰�����������֮�����̾����С

n = size(D,1);%��ø������Ȩͼ�Ľڵ����
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