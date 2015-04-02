import sys
mindist = [None] * 101
class Node:
	def __init__(self, value):
		self.value = value
		self.connections = []
		self.visited = 0
	def printme(self):
		print "I am: %d" %self.value
	def connectNode(self,node):
		self.connections.append(node)
	def printPath(self):
		self.printme()
		for node in self.connections:
			node.printPath()
	def shortestPath(self,to):
		min_ = 999
		if self.value == to:
			return 0
		if mindist[self.value] != None:
			return mindist[self.value]
		min_n = self.connections[0]
		for node in self.connections:
			if node.visited == 1:
				continue
			node.visited = 1
			val = node.shortestPath(to)
			#print "visited: %d" % node.value
			#print "val: %d" % val
			if val < min_:
				min_ = val
				min_n = node
			node.visited = 0
		#print "current: %d " % self.value
		#print "min was: %d for node %d" % (min_, min_n.value)
		mindist[self.value] = min_ + 1
		return min_ + 1
			
			

class Graph:
	nodes = {}
	def __init__(self):
		nodes = {}
	def addNode(self,value):
		node = Node(value)
		self.nodes[value] = node
		return node
	def connect(self,n1,n2):
		n1.connectNode(n2)
	def getNodes(self):
		return self.nodes
		
		
def getPath():
	graph = Graph()
	last = graph.addNode(100)
	nodes = graph.getNodes()
	for x in range(99,0,-1):
		node = graph.addNode(x)
		for y in range(1,7):
			if x + y > 100:
				break
			#print "Connecting %d to %d" % (node.value, nodes[x+y].value)
			graph.connect(node,nodes[x+y])
	#nodes = graph.getNodes()
	head = nodes[1]
	ladd_snake = raw_input()
	l_s = ladd_snake.split(',')
	ladd = raw_input()
	ladders = ladd.split(' ')
	for y in range(0,int(l_s[0])):
		#print "loop: %d" % y
		st_en = ladders[y].split(',')
		st = nodes[int(st_en[0])]
		end = nodes[int(st_en[1])]
		graph.connect(st,end)
	snake = raw_input()
	snakes = snake.split(' ')
	for y in range(0,int(l_s[1])):
		st_en = snakes[y].split(',')
		st = nodes[int(st_en[0])]
		end = nodes[int(st_en[1])]
		graph.connect(st,end)
	shortest = head.shortestPath(100)
	shortest = shortest - 1
	print "%d" % shortest
	head = None
	graph = None
	last = None
	nodes = None




cases = raw_input()
for x in range(0,int(cases)):
	getPath()
	mindist = [None] * 101
