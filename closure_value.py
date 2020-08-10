n=int(input())
y=[]
sellers_price=[]
sellers_quantity=[]
sellers_companies=[]
buyers_price=[]
buyers_quantity=[]
buyers_companies=[]
txns=[]
for i in range(n):
    x=[i for i in input().split()]
    y.append(x)
for i in y:
    if(i[1]=="Sell"):
        sellers_price.append(int(i[3]))
        sellers_companies.append(i[2])
        sellers_quantity.append(int(i[4]))
    else:
        buyers_price.append(int(i[3]))
        buyers_companies.append(i[2])
        buyers_quantity.append(int(i[4]))
for i in range(len(buyers_companies)):
    for j in range(len(sellers_companies)):
        if(sellers_companies[j]==buyers_companies[i]):
            if(buyers_price[i]>sellers_price[j]):
                sold= buyers_quantity[i] if buyers_quantity[i]<sellers_quantity[j] else sellers_quantity[j]
                buyers_quantity[i] = buyers_quantity[i]-sold
                sellers_quantity[j] = sellers_quantity[j]-sold
                txns.append(buyers_companies[i]+':'+str(sellers_price[j]))
if (len(txns)!=0):
    for i in txns:
        print(i)
else:
    print("Stocks not traded")