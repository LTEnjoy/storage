for j = 1:18
    count = 0;
    for i = 1:61
        if(type(1,i) == "2")
           a(1,j) = a(1,j) + str2double(type(j+2,i));
           count = count +1;
        end
    end
    hold on;
    a(1,j) = a(1,j)/count;

end
t = 1:18;
    p = polyfit(t,a,4);
    f=@(a) p(1)*a.^4+p(2)*a.^3+p(3)*a.^2+p(4)*a +p(5);
    plot(t,a,'r.')
    fplot(f,[0,18])
    title('第三类价格总和变化图')
    xlabel('时期 t/(*10天)');
    ylabel('平均价格 S/元');