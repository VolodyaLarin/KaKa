package main

func main() {
	var twoD [2][3]int

	var i int = 0
	for i = 0; i < 2; i = i + 1 {
		var j int = 0
		for j = 0; j < 3; j = j + 1 {
			twoD[i][j] = i*10 + j
		}
	}

	printf("\n\n%d %d %d \n%d %d %d\n",
		twoD[0][0], twoD[0][1], twoD[0][2],
		twoD[1][0], twoD[1][1], twoD[1][2],
	)

}
