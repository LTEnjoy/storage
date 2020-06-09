function a(x,y,k)  %K-聚类法 x y为数据的横纵坐标，K为分类数
                    

hold on ;
plot(x,y,'r.');
p = randperm(length(x),k); %随机数随机选取初始中心
center = zeros(k,5);    %每一类的中心坐标
type = 1:length(x); %存储每个数据属于的类别
judge = 0;
count = 0;
for i = 1:k
    center(i,:) =[x(p(i)),y(p(i)),0,0,0]; 
end
while 1
    for i = 1:length(x)
        min = 10000;
        for j = 1:k
            if( ((x(i)-center(j,1)).^2 + (y(i)-center(j,2)).^2 )< min)
                type(i) = j;
                min = (x(i)-center(j,1)).^2 + (y(i)-center(j,2)).^2;
            end
        end
        center(type(i),3) = center(type(i),3) + x(i);
        center(type(i),4) = center(type(i),4) + y(i);
        center(type(i),5) = center(type(i),5) + 1;
    end
    for i = 1:k
         center(i,1) = center(i,3)/center(i,5);
         center(i,2) = center(i,4)/center(i,5);
    end
  
    if( count == 2000)
       hold on;
       plot(center(1,1),center(1,2),'b*');
       plot(center(2,1),center(2,2),'g*');
       plot(center(3,1),center(3,2),'r*');
       plot(center(4,1),center(4,2),'m*');
       plot(center(5,1),center(5,2),'k*');
       plot(center(6,1),center(6,2),'c*');
       for j = 1:length(x)
           if(type(j) == 1)
              plot(x(j),y(j),'b.');
           elseif(type(j) == 2)
               plot(x(j),y(j),'g.');
           elseif(type(j) == 3)
               plot(x(j),y(j),'r.');
           elseif(type(j) == 4)
               plot(x(j),y(j),'m.');
           elseif(type(j) == 5)
               plot(x(j),y(j),'k.');
           elseif(type(j) == 6)
               plot(x(j),y(j),'c.');
           end
       end
       break;
    end
    count = count +1;
    for i = 1:k
        center(i,3) = 0;
        center(i,4) = 0;
        center(i,5) = 0;
    end
end  
hold off
end
            