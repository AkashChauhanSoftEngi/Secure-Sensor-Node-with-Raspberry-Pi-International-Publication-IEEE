%x = 1900:10:2000;
%y = [75.995,91.972,105.711,123.203,131.669,...
 %    150.697,179.323,203.212,226.505,249.633,281.422];
%figure;
%bar(x,y);

% % % % % % bar group plot
% Y = round(rand(5,3)*10);
% Y=[5 7 8 9];
% z=[7];
% figure;
% subplot(2,2,1);
% bar(Y,'grouped');



% % % % % title('memory size')
% A = [4485 4952 16383 8495];
% bar(A,0.2)
% set(gca,'XTickLabel',{'rc4','rc5','skipjack','blowfish'});
% ylabel('Memory used at run time(in byte)');



% % % % % LOC
% A=[88 147 279 120];
% bar(A,0.2)
% set(gca,'XTickLabel',{'rc4','rc5','skipjack','blowfish'});
% ylabel('Lines of Code(LOC)');
% xlabel('Algorithm');
% title('Lines of Code');

%%%%%%%%%%%cache performance
% Y=[0.19 0.04 0.44 0.0;0.12 0.03 0.08 0.0;0.5 0.1 0.3 0.0;0.3 0.1 0.2 0.0;0.2 0.0 0.1 0];
% figure;
% subplot(2,2,1);
% bar(Y,'grouped');
% set(gca,'XTickLabel',{'I1','LLi','D1','LLD','LL'});


%%%%%%%%%%cpu load 
% x1=[100 500 1000 1500 2000];
% y1=[18.47 31.33 40.14 46.5 51.6];
% x2=[100 500 1000 1500 2000];
% y2=[38.23 53.65 71.44 70.95 76.75];
% x3=[100 500 1000 1500 2000];
% y3=[21.31 46.78 56.12 63.46 68.25];
% x4=[100 500 1000 1500 2000];
% y4=[96.85 99.4 99.55 99.63 99.64];
% figure;
% plot(x1,y1,x2,y2,x3,y3,x4,y4);
% xlabel('Accelerometer Input[X Y Z]');
% ylabel('Cpu Load(in %)');
% title('Cpu Load');


%%%%%%%%%%page fault 
%   x1=[100 500 1000 1500 2000];
%   y1=[2622.59 2396.5 2247.73 2127.21 2043.45];
%   x2=[100 500 1000 1500 2000];
%   y2=[2656.73 1491.46 993.08 704.4 592.65];
%   x3=[100 500 1000 1500 2000];
%   y3=[2962.17 2229.98 1638.83 1359.95 1167.91];
%   x4=[100 500 1000 1500 2000];
%   y4=[59.37	12.55 6.29 4.2 3.15];
%   figure;
%   plot(x1,y1,x2,y2,x3,y3,x4,y4);
%   xlabel('Accelerometer Input[X Y Z]');
%   ylabel('Page Fault');
%   title('Page Fault');

%%%%%context switch
% y1=[4063.16	3508.61	3184.29	2429.44	2487.23];
% y2=[3344.8	1630.95	1714.68	1444.27	1338.79];
% y3=[3494.94	2697.81	1537.81	1840.47	1600.18];
% y4=[86.32	39.87	35.41	31.67	30.62];
% x1=[100 500 1000 1500 2000];
% x2=[100 500 1000 1500 2000];
% x3=[100 500 1000 1500 2000];
% x4=[100 500 1000 1500 2000];
% figure;
% plot(x1,y1,x2,y2,x3,y3,x4,y4);
% xlabel('Accelerometer Input[X Y Z]');
% % ylabel('Context switch (per sec)');
% title('Context Switch');


%%%%%cpu read and write
%  y1=[147.75 219.29 173.93 162.74 134.17];
%  y2=[114.68 96.57 100.02 91.22 102.33];
%  y3=[149.17 155.94 89.8 81.6 75.84];
%  y4=[2.53 0.89 0.58 0.51 0.49];
%  x1=[100 500 1000 1500 2000];
%  x2=[100 500 1000 1500 2000];
%  x3=[100 500 1000 1500 2000];
%  x4=[100 500 1000 1500 2000];
%  figure;
%  plot(x1,y1,x2,y2,x3,y3,x4,y4);
%  xlabel('Accelerometer Input[X Y Z]');
%  ylabel('Read Operation (per sec)');
%  title('Per Second Read Operations');

%%%%%%write operations
y1=[73.88 93.98 80.28 69.74	61.92];
y2=[76.45 107.3 128.6 131.76 136.44];
y3=[42.62 77.97 101.02 117.86 121.34];
y4=[1.68 0.89 0.8 0.71 0.71];
x1=[100 500 1000 1500 2000];
x2=[100 500 1000 1500 2000];
x3=[100 500 1000 1500 2000];
x4=[100 500 1000 1500 2000];
figure;
plot(x1,y1,x2,y2,x3,y3,x4,y4);
xlabel('Accelerometer Input[X Y Z]');
ylabel('Write Operation (per sec)');
title('Per Second write Operations');
 
 
 