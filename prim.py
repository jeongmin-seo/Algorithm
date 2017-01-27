infinite = 9999
undefined = -1

def read_matrix (file_name):

	matrix = []
	row = 0
	
	f = open(file_name + ".txt", 'r')
	lines = f.readlines()

	for line in lines :
		line_split = line.strip().split(' ')
		matrix.append([])

		for i in range(0,len(line_split)):
			matrix[row].append(int(line_split[i]))

		row +=1

	f.close()

	return matrix

def prim(cost, source, targ):

	dist = []    
	prev = []    
	selected=[]  
	start = source -1
	target = targ -1
	N= len(cost[0])

	for i in range(0,N):
		dist.append(infinite)
		prev.append(undefined)

	dist[start] = 0
	selected.append(start)

	while(len(selected) <N):
		m=0
		d = infinite

		for j in selected:
			for i in range(0,N):

				if cost[j][i] < d and i not in selected:
					d = cost[j][i]
					dist[i] = dist[j] + cost[j][i]
					prev[i] = j
					m = i

		print("prev:",prev,"dist:",dist)
		selected.append(m)

	start = target

	j = 0 					#경로 출력을 위한부분 
	path = []
	while(start != -1):
		path.append(start+1)
		start = prev[start]

	return (dist[target],path)



if __name__ == "__main__":
	file_name = input("파일명을 입력하세요:")
	matrix = read_matrix(file_name)
	source = int(input("시작점을 입력하세요:"))
	target = int(input("도착점을 입력하세요:"))
	(distance,path) = prim(matrix,source,target)
	print("이동 경로:",end=' ')

	N=len(path)
	for i in range(N):
		if i == (N-1):
			print(path[N-(i+1)])
		else:
			print(path[N-(i+1)],end='->')

	print("총 거리:", distance)
