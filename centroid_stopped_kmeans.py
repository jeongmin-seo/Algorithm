import random
import math

def read_data(data_name):

	dataset = []
	row = 0
	f = open(data_name +".csv",'r')

	lines = f.readlines()
	lines.remove(lines[0])

	for line in lines:
		split_line = line.strip().split(',')
		dataset.append([])

		for i in split_line:
			dataset[row].append(i)

		row +=1

	f.close()

	for data in dataset:
		for i in range(0,len(data)):
			data[i] = float(data[i])

	return dataset

def kmeans(dataset, k):

	old_centroid = random.sample(dataset,k)  #데이터 중에서 랜덤으로 k개의 중점 선택  
	(cluster,distances) = calc_distance_from_centroid(dataset,old_centroid)  #각 중점으로 부터 데이터들까지의 거리중 최소인 것을
																		#선택해서 군집과 최소 거리 반환
	distances = sum(distances)  # 반환한 거리값들을 모두 더함
	print("총 거리:",distances)

	centroid = renew_centroid(dataset,old_centroid,cluster)  #반환받은 cluster를 기반으로 중점을 갱신함.

	while not should_stop(old_centroid,centroid):

		(cluster,distances) = calc_distance_from_centroid(dataset,centroid) #갱신한 centroid를 이용해서 다시 데이터들까지의 거리와 군집을 구함.
		
		distances = sum(distances)  #반환한 거리 값들을 모두 더함(평가값)
		print("총 거리:",distances)

		old_centroid = centroid
		centroid = renew_centroid(dataset,old_centroid,cluster)  #반환받은 cluster를 기반으로 중점을 갱신함.

	return cluster

def calc_distance_from_centroid(dataset,centroid):

	cluster = []
	distances = []
	for data in dataset:
		for center in centroid:
			
			D = math.sqrt((data[0]-center[0])**2 + (data[1]-center[1])**2 + 
						(data[2]-center[2])**2 + (data[3]-center[3])**2)  #유클리디안 거리  

			if centroid.index(center) == 0:  #첫번째 실행이면 무조건 D를 distance에 넣고
				distance = D
				cluster.append(0)    # 0클러스터로 분류   

			elif distance > D:   #distance보다 작은 D가 나오면  
				distance = D     # distance에 D저장 
				cluster[-1] = centroid.index(center)  # 적절한 클러스터로 분류   

		distances.append(distance)

	return (cluster,distances)

def renew_centroid(dataset,centroid,cluster):

	new_centroid = []
	count_cluster = []
	N= len(centroid[0])

	for i in range(0,len(centroid)):
		new_centroid.append([])
		count_cluster.append(0)

		for j in range(0,N):
			new_centroid[i].append(0)     #0으로 초기화  

	for data in dataset:
		for j in range(0,N):
			new_centroid[cluster[dataset.index(data)]][j] += data[j]   # 새 중점을 구하기 위해 클러스터별 데이터 값을 모두 더함.
	
		count_cluster[cluster[dataset.index(data)]] += 1    #클러스터별 데이터 개수가 몇개인지 count

	for center in new_centroid:
		for j in range(0,N):
			center[j] = center[j]/count_cluster[new_centroid.index(center)] #평균구함(새 중점  )

	return new_centroid


def should_stop(old_centroid,centroid):
	return old_centroid == centroid  # 중지 조건(클러스터가 더 이상 변하지 않을때 즉, 중점이 변하지 않을때)
	

if __name__ == "__main__":
	data = read_data(input("데이터를 입력하세요:"))
	k = int(input("k값을 입력하세요:"))
	cluster = kmeans(data,k)
	print(cluster)




