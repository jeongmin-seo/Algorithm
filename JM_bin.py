#-*- coding: utf-8 -*-

def NumOfPinary(N):

	if N==1 or N==2:
		return 1

	else:
		return (NumOfPinary(N-1)+NumOfPinary(N-2))

if __name__ == "__main__":
	N = int(raw_input("자릿수를 입력하세요:"))

	print(NumOfPinary(N))
