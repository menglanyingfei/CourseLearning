sum=0
var=1
var1=$#
let var2=var1+var1 
while [ $var -le $var2 ]
do
     temp=$1
     let sum+=temp
     let var+=1
     shift
done
echo "$sum"
