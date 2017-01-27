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


def dijkstra (cost, source,targ):

	dist = []       #출발점에서 각각 점들로 가는데에 최소비용이 얼마인지 저장할 리스트
	prev = []       #이전 노드에서 어딜 경유했는지 담을 리스트 
	start = source-1
	target = targ-1
	N = len(cost[0])

	selected = []

	for i in range(0,N):
		dist.append(infinite)    #무한대로 초기화(비용을 계산하기 전까지 모르기때문)
		prev.append(-1)      #아직 경유한곳이 없기때문에 모두 -1로 초기화  
		selected.append(0)
	
	dist[start] = 0       #출발지에서 출발지로 가는데는 비용이 0이기 때문에  
	selected[start] = 1   # 선택된(이미 경유한 노드 표시)

	while(selected[target] == 0):
		mini = infinite
		m=0

		for i in range(0,N):
			d = dist[start] + cost[start][i]   #이전노드 까지 도달하기 위한 최소비용 + 다음 노드를 가기 위한 최소비용

			if d <= dist[i] and selected[i] ==0:  #이미 알고있는 비용보다 계산된 비용이 더 작고 경유하지 않은 노드라면 
				dist[i] = d        #계산된 비용으로 저장 
				prev[i] = start    #이전 노드에 출발점을 저장  

			if mini > dist[i] and selected[i] == 0:
				mini = dist[i]
				m = i    #최소일때 i를 m에 저장 

		print("prev는",prev,"dist는",dist)
		start = m   #다음 시작점을 m으로 지정
		selected[start] = 1

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
	(distance,path) = dijkstra(matrix,source,target)
	print("이동 경로:",end=' ')

	N=len(path)
	for i in range(N):
		if i == (N-1):
			print(path[N-(i+1)])
		else:
			print(path[N-(i+1)],end='->')

	print("총 거리:", distance)