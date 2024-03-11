package main

import "fmt"

type rect struct {
	width  int
	height int
}

func (r *rect) area() int {
	return r.width * r.height
}

func (r rect) perim() int {
	return 2*r.width + 2*r.height
}

func (r rect) print() {
	printf("W: %d H: %d\n", r.width, r.height)
	printf("area: %d perim %d\n", r.area(), r.perim())
}

func main() int {
	var r rect
	r.width = 10
	r.height = 12

	r.print()

	var rp *rect = &r
	rp.width = rp.width * 2
	rp.print()
	r.print()

	return 0
}
