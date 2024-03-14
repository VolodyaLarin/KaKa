package main

import "fmt"

func main() {

	var number1 int = 20
	var number3 float64 = 15.12
	var sum float32

	sum = float32(number1+int(number3)) + 0.11

	fmt.Printf("Sum is %f %lf\n", number3, number3/2.1)

	fmt.Printf("Sum is %g\n", sum)
}
