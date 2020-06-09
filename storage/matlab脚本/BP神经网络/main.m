% for i = 1:6
%     for j = 1:10
%         input(i,j) = input(i,j)*2/3;
%     end
% end
result = zeros(10,1);
for i = 1:7
   result(i) = foresee(test(:,i),W1,T1,W2,T2,@f);
end