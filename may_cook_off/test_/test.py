import random
mySet = []
keySet = {}
nodes = 100000
query = 200000
intRange = 100000000
print nodes,query
for i in range(1,nodes+query+1):
  num = random.randrange(1,intRange)
  while num in mySet:
    num = random.randrange(1,intRange)
  mySet.append(num)
  temp = num
  num = random.randrange(1,intRange+1)
  while num in keySet.values():
    num = random.randrange(1,intRange+1)
  keySet[str(temp)] = num
ind = random.randrange(1,nodes+1)
print mySet[ind],keySet.get(str(mySet[ind]))
connectedSet =[]
connectedSet.append(mySet[ind])
mySet.remove(mySet[ind])
for i in range(1,nodes):
  ind = random.randrange(0,len(mySet))
  temp = mySet[ind]
  print mySet[ind], connectedSet[random.randrange(0,len(connectedSet))], keySet.get(str(mySet[ind]))
  mySet.remove(temp)
  connectedSet.append(temp)

for i in range(0,query):
  choice = random.randrange(1,1000)
  if choice%2==0:
    ind = random.randrange(0,len(mySet))
    temp = mySet[ind]
    print 0, connectedSet[random.randrange(0,len(connectedSet))], temp,keySet.get(str(temp))
    mySet.remove(temp)
    connectedSet.append(temp)
  else:
    print " %d %d %d"%(1, connectedSet[random.randrange(0,len(connectedSet))],random.randrange(1,intRange))

