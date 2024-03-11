package main

import (
	"fmt"
)

type geometry interface {
	area() float64
	perim() float64
}

type rect struct {
	width  float64
	height float64
}

type circle struct {
	radius float64
}

func (r rect) area() float64 {
	return r.width * r.height
}
func (r rect) perim() float64 {
	return 2*r.width + 2*r.height
}

func (c circle) area() float64 {
	return 3.14 * c.radius * c.radius
}

func (c circle) perim() float64 {
	return 2 * 3.14 * c.radius
}
func measure(g geometry) {
	printf("Площадь: %g см^2, периметр: %g см\n", g.area(), g.perim())
}

func main() int {
	var r rect
	r.width = float64(3)
	r.height = float64(4)
	var c circle
	c.radius = float64(5)

	var g1 geometry = r
	measure(g1)

	var g2 geometry = c
	measure(g2)
	return 0
}
