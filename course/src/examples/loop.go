package main

func main() {
	var a [5]int

	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4])

	a[4] = 100

	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4])

	var twoD [2][3]int
	var i int = 0
	for i = 0; i < 2; i = i + 1 {
		var j int = 0
		for j = 0; j < 3; j = j + 1 {
			twoD[i][j] = i + j
		}
	}

	printf("%d %d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4])

}
