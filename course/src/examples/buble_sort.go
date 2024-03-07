package main

func main() {
	var a [5]int

	a[0] = 228
	a[1] = 1448
	a[2] = 13
	a[3] = 9
	a[4] = 887
	var i int = 0
    var j int = 0
	for i = 0; i < 5; i = i + 1 {
		for j = 0; j < 5-i-1; j = j + 1 {
            if a[j] > a[j+1] {
				var tmp int = a[j]
				a[j] = a[j+1]
				a[j+1] = tmp
			}
		}
	}

	printf("%d %d %d %d %d\n", a[0], a[1], a[2], a[3], a[4])
}
