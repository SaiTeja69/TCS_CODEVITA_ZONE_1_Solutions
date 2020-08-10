n,k=input().split()
n,k=int(n),int(k)
y=[int(i) for i in input().split()]
l=[]
count=0
for i in y:
    l.append([i-k,i+k])
for x in range(len(y)):
    for i in range(len(y)):
        if y[i]<=l[x][1] and y[i]>=l[x][0] and y[i]!=y[x]:
            count=count+1
            break
print(count,end="")