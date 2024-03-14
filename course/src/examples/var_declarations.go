package main

import "fmt"

func main() {

	var a = "initial"
	fmt.Printf("%s\n", a)

	var b, c int = 1, 2
	fmt.Printf("%d %d\n", b, c)

	var d = true
	fmt.Printf("%d\n", d)

	var e int
	fmt.Printf("%d\n", e)

	var (
		product      = "Mobile"
		quantity int = 50
		price        = 50.50
		inStock      = true
	)

	fmt.Printf("%s %d %lf %d\n", product, quantity, price, inStock)

	f := "apple"
	fmt.Printf("%s\n", f)

	m, n, o := 1, 2, 3
	fmt.Printf("%d %d %d\n", m, n, o)

	m, _, s := 5, 6, "hello"

	fmt.Printf("%d %s\n", m, s)

	m, n, o = 10, 11, 12
	fmt.Printf("%d %d %d\n", m, n, o)

	m, _, o = 20, 21, 22
	fmt.Printf("%d %d\n", m, o)
}
