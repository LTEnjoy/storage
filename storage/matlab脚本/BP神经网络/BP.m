function [W1,T1,W2,T2] = BP(input,nodeNum,output,f)
%input代表输入样本矩阵，样本为列向量，列数为样本数。
%nodeNum代表隐层节点数
%output代表输出结果矩阵，结果为列向量，列数为结果数（与样本对应）
%激活函数默认使用Sigmoid函数

numOfAttr = size(input,1);  %样本属性个数
numOfResult = size(output,1);   %结果属性个数
W1 = ones(numOfAttr,nodeNum); %输入层权重矩阵
T1 = ones(nodeNum,1);   %隐含层阈值
input2 = ones(nodeNum,1);   %隐含层输入
W2 = ones(nodeNum,numOfResult); %输出层权重矩阵
T2 = ones(numOfResult,1);   %输出层阈值
output2 = ones(numOfResult,1);  %输出层输出
g = ones(numOfResult,1);    %输出层神经元梯度项
e = ones(nodeNum,1);    %隐含层神经元梯度项
y = 0.1;    %设置学习率

%遍历每个样本进行BP算法
for count = 1:100000
    for n = 1:size(input,2)
        %获取隐含层的输入
        for i = 1:nodeNum
            sum = 0;
            for j = 1:numOfAttr
                sum = sum + input(j,n)*W1(j,i);
            end
            sum = sum - T1(i);
            input2(i,1) = f(sum);
        end
        %获取输出层的输出
        for i = 1:numOfResult
            sum = 0;
            for j = 1:nodeNum
                sum = sum + input2(j,1)*W2(j,i);
            end
            sum = sum - T2(i);
            output2(i,1) = f(sum);
        end
        %计算输出层神经元梯度项
        for i = 1:numOfResult
            g(i) = output2(i)*(1-output2(i))*(output(i,n)-output2(i));
        end
        %计算隐含层神经元梯度项
        for i = 1:nodeNum
            e(i) = 0;
            for j = 1:numOfResult
                e(i) = e(i) + W2(i,j)*g(j);
            end
            e(i) = e(i)*input2(i)*(1-input2(i));
        end
        %更新连接权W1、W2和阈值T1、T2的值
        for i = 1:nodeNum
            for j = 1:numOfAttr
                W1(j,i) = W1(j,i) + y*e(i)*input(i,n);
                t = y*e(i)*input(i,n);
            end
            T1(i) = T1(i) - y*e(i); 
        end
        for i = 1:numOfResult
            for j = 1:nodeNum
                W2(j,i) = W2(j,i) + y*g(i)*input2(j);
            end
            T2(i) = T2(i) - y*g(i);
        end
    end
end