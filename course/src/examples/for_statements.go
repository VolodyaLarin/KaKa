package main

import "fmt"

func main() {

	i := 1
	for i <= 3 {
		printf("%d\n", i)
		i = i + 1
	}

	for j := 0; j < 3; j++ {
		printf("%d\n", j)
	}

	for i = range 3 {
		printf("range %d\n", i)
	}
	printf("range after i %d\n", i)

	for {
		printf("loop with break\n")
		break
		printf("should don't be printed")
	}
	for n := range 6 {
		if n%2 == 0 {
			continue
		}
		printf("%d\n", n)
	}

}
