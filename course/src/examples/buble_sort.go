package main

func main() {
	const size int = 5
	var a [5]int

	var i int = 0
	var j int = 0

	printf("Введите элементы массива (5 штук): ")

	for i = 0; i < size; i = i + 1 {
		scanf("%d", &a[i])
	}

	for i = 0; i < size; i = i + 1 {
		for j = 0; j < size-i-1; j = j + 1 {
			if a[j] > a[j+1] {
				var tmp int = a[j]
				a[j] = a[j+1]
				a[j+1] = tmp
			}
		}
	}

	for i = 0; i < size; i = i + 1 {
		printf("%d ", a[i])
	}

	printf("\n")
}
