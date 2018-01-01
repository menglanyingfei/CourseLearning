% �˳����Ӧ������һ, �ó����������ʱ��61, 151
clear;clc
[data]=xlsread('A�⸽��', 2);
for n=1:180
    plot(data(:,n))
    xlim([1 512])
    ylim([0 160])
    drawnow
    f = getframe(1);
    im{n} = frame2im(f);
    pause(0.1)
end

% Ϊ����ļ�����
name = '��̬�仯ͼ.gif'; 
for index = 1:180
    [a, b] = rgb2ind(im{index}, 256);
    if index == 1
        imwrite(a, b, name,'gif','LoopCount',Inf,'DelayTime',0.05);
    else
        imwrite(a, b, name,'gif','WriteMode','append','DelayTime',0.05);
    end
end
