M = [1 2 2 
      1/2 1 3
   1/2 1/3 1];                                % Judgment matrix Of M-C
[V,D]=eig(M);
W=V(:,1)/sum(V(:,1));
C1 = [1, 1,1/2
         1,1,2
         2, 1/2,1];                             % Judgment matrix Of C1-P
[V1,D1]=eig(C1);
W1=V1(:,1)/sum(V1(:,1));
C2 = [1,1/2
         2,1];                             % Judgment matrix Of C2-P
[V2,D2]=eig(C2);
W2=V2(:,1)/sum(V2(:,1));
C3 = [1, 3,1
         1/3,1,2
         1, 1/2,1];                             % Judgment matrix Of C3-P 
[V3,D3]=eig(C3);
W3=V3(:,1)/sum(V3(:,1));
U = [W1(1),0,0
        W1(2),0,0
        W1(3),0,0
        0,W2(1),0
        0,W2(2),0
        0,0,W3(1)
        0,0,W3(2)
        0,0,W3(3)];
U*W                                            % Eventually ans variable corresponding to the weight ratio of each scheme layer P