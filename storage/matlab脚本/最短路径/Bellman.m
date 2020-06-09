function info = Bellman(V,E,s)
%����Bellmanѭ�����̷��������·��

%ÿ���ڵ㶼��һ�������ţ���1��ʼ������ʹ��ʱ�����б�úš�
%info���ش���㵽����һ���ڵ����̾��룬��һ��Ϊ�����ţ��ڶ���Ϊ��Ӧ����,������Ϊ�ýڵ�ĸ��ڵ�
%V����ڵ����
%E�������бߵļ��ϣ���һ��Ϊ�ߵ�����ţ��ڶ���Ϊ�ߵ��յ���,������ΪȨ�أ����룩
%s������ʼ�ڵ�ı��

%��ʼ������
info = zeros(V,3);
for i = 1:V
    info(i,1) = i;
    info(i,2) = inf;
end
info(s,2) = 0;  %������̾�����0

%����V-1��ѭ����ÿ��ѭ������ÿ���߽���һ�����̷�
for i = 1:V-1
    for j = 1:size(E,1)
        startLabel = E(j,1);
        endLabel = E(j,2);
        if info(startLabel) == inf
            continue;
        elseif info(startLabel,2) + E(j,3) < info(endLabel,2) %���̷��ж�
            info(endLabel,2) = info(startLabel,2) + E(j,3);
            info(endLabel,3) = startLabel;
        end
    end
end

%�ٽ���һ��ѭ�����̷����ж��Ƿ��и�Ȩ��·
for j = 1:size(E,1)
        startLabel = E(j,1);
        endLabel = E(j,2);
        if info(startLabel) == inf
            continue;
        elseif info(startLabel,2) + E(j,3) < info(endLabel,2) %���̷��ж�
            disp("������ͼ�к��и�Ȩ��·��")
            info = 0;
            return;
        end
end
