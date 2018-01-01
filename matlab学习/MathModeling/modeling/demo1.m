% 此程序对应于问题一, 得出两个特殊的时刻61, 151
clear;clc
[data]=xlsread('A题附件', 2);
for n=1:180
    plot(data(:,n))
    xlim([1 512])
    ylim([0 160])
    drawnow
    f = getframe(1);
    im{n} = frame2im(f);
    pause(0.1)
end

% 为输出文件命名
name = '动态变化图.gif'; 
for index = 1:180
    [a, b] = rgb2ind(im{index}, 256);
    if index == 1
        imwrite(a, b, name,'gif','LoopCount',Inf,'DelayTime',0.05);
    else
        imwrite(a, b, name,'gif','WriteMode','append','DelayTime',0.05);
    end
end
