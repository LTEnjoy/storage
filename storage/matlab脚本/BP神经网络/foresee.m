function result = foresee(x,W1,T1,W2,T2,f)

input2 = ones(size(T1,1),1);   %隐含层输入
result = ones(size(T2,1),1);  %输出层输出
numOfAttr = size(x,1);
numOfResult = size(T2,1);
nodeNum = size(T1,1);
 %获取隐含层的输入
for i = 1:nodeNum
    sum = 0;
    for j = 1:numOfAttr
        sum = sum + x(j)*W1(j,i);
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
    result(i,1) = f(sum);
end