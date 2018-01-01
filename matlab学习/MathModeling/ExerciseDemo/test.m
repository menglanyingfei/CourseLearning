load dealed_date.mat
a=zeros(1,36);
for m=1:36
for n=1:m
   a(n)=1;
end
P=round(rand(1,1));
for t=1:2
    for i=1:36
        for j=1:36
            if a(i)==0&&a(j)==1&&graph(i,j)==1
            a(i)=1*P;
            elseif a(i)==0 
            end
        end
    end
end
end
    count = hist(a,unique(a))
