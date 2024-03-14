package main

import "fmt"

func main() {

	i := 1
	for i <= 3 {
		fmt.Printf("%d\n", i)
		i = i + 1
	}

	for j := 0; j < 3; j++ {
		fmt.Printf("%d\n", j)
	}

	for i = range 3 {
		fmt.Printf("range %d\n", i)
	}
	fmt.Printf("range after i %d\n", i)

	for {
		fmt.Printf("loop with break\n")
		break
		fmt.Printf("should don't be printed")
	}
	for n := range 6 {
		if n%2 == 0 {
			continue
		}
		fmt.Printf("%d\n", n)
	}

}
