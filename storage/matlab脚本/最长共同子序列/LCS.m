%利用动态规划解最长共同子序列问题
%x y是 一行的行序列字符串
function result = LCS(x,y)
x = split(x,"");
x(1) = [];
x(end) = [];
y = split(y,"");
y(1) = [];
y(end) = [];
numTable = zeros(size(x,1)+1,size(y,1)+1);
strTable = zeros(size(x,1)+1,size(y,1)+1);
strTable = string(strTable);
for i =1:size(x,1)
    for j = 1:size(y,1)
        strTable(i,j) = "";
    end
end
for i = 2:size(x,1)+1
    for j = 2:size(y,1)+1
        if x(i-1) == y(j-1)
            numTable(i,j) = numTable(i-1,j-1)+1;
            strTable(i,j) = strTable(i-1,j-1)+x(i-1);
        else
            if numTable(i,j-1) >= numTable(i-1,j)
                numTable(i,j) = numTable(i,j-1);
                strTable(i,j) = strTable(i,j-1);
            else
                numTable(i,j) = numTable(i-1,j);
                strTable(i,j) = strTable(i-1,j);
            end
        end
    end
end
result = strTable(end,end);
