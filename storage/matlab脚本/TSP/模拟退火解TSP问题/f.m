%模拟退火工具箱的测试用函数
function F = f(x)
F = -1 * (x(1)^2 + x(2).^2 - 10*cos(2*pi*x(1)) - 10*cos(2*pi*x(2)) + 20);
end