%层次分析法
function w = AHP(A)                %A为成对比较矩阵
[~,n]=size(A);                     %获取方阵A的行列数
RI=[0 0 0.58 0.90 1.12 1.24 1.32 1.41 1.45 1.49 1.51]; %随机一致性指标
[V,D]=eig(A);                      %求判断矩阵的特征值和特征向量，D特征值，V特征向量；
tz=max(D);
B=max(tz);                         %获得最大特征值B
[~, col]=find(D==B);               %最大特征值所在位置
C=V(:,col);                        %对应特征向量
CI=(B-n)/(n-1);                    %计算一致性检验指标CI
CR=CI/RI(1,n);                     %计算一致性比率
if CR<0.10
    fprintf('CI = %f\n',CI);
    fprintf('CR = %f\n',CR);
    disp('成对比较矩阵A通过一致性检验，各向量权重向量w为：');
    SUM = sum(C);
    w=zeros(n,1);
    for i=1:n
        w(i,1)=C(i)/SUM; %特征向量标准化
    end                            
else
    disp('成对比较矩阵A未通过一致性检验，需对成对比较矩阵A重新构造');
    w = 0;
end
