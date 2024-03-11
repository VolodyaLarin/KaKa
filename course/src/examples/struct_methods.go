package main

import "fmt"

type rect struct {
    width, height int
}

func (r *rect) area() int {
    return r.width * r.height
}

func (r rect) perim() int {
    return 2*r.width + 2*r.height
}

func (r rect) print() {
    fmt.Printf("area: %d perim %d\n", r.area(), r.perim())
}

func main() int {
    var r rect;
    rect.width = 10
    rect.height = 12

    r.print()

    var rp *rect = &r

    (*rp).print()

    return 0
}