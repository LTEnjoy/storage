function distance = Floyd(D)
%Floyd-Worshall�㷨����ȫ������·��
%DΪ�ڵ���ڽӾ���������ͨ���Ӧ��ֵΪInf,����ͨ���Ӧ��ֵΪ����Ȩ��
%distanceΪ���ص����·�����󣬰�����������֮�����̾����С

n = size(D,1)%��ø������Ȩͼ�Ľڵ����
distance = D;

for k = 1:n
    for i = 1:n
        for j = 1:n
            distance(i,j) = min(D(i,j),D(i,k)+D(k,j));  
        end
    end
    D = distance;
end