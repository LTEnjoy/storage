%��΢�ַ��̵ĺ����ļ�
function Dy = dy(t,y)
Dy = zeros(2,1);
Dy(1) = -0.5*y(1) + 0.02*y(1)*y(2);
Dy(2) = y(2) - 0.1*y(1)*y(2);
end
