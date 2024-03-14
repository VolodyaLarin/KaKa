package main

import "fmt"

func main() {
	var sum int = 20

	var i int = 0
	for i = 1; i < 10; i = i + 1 {
		fmt.Printf("%d ", sum)
		sum = sum + i
	}

	fmt.Printf("%d\n", sum)
}
