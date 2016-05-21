# python 2.7
values = map(lambda x:int(x), raw_input().split()) 
num=[[1,0,0]]
for x in range(values[3]):
	num.append([num[x][0]*values[0]+num[x][1]*values[1]+num[x][2]*values[2],\
                    num[x][0],num[x][1]+num[x][2]])
print num[values[3]][0]+num[values[3]][1]+num[values[3]][2]

