package main

import "fmt"

type Node struct {
	data     int
	nextNode *Node
}

func newNode(data int, next *Node) *Node {
	var node Node
	node.data = data
	node.nextNode = next
	return &node
}

func inputList() *Node {
	var list *Node = nil
	var size int
	fmt.Printf("Input size: ")
	fmt.Scanf("%d", &size)
	fmt.Printf("Write values: ")
	for i := 0; i < size; i = i + 1 {
		var data int
		fmt.Scanf("%d", &data)
		list = newNode(data, list)
	}
	return list
}

func printNode(list *Node) {
	var node *Node = list

	for node != nil {
		fmt.Printf("%d -> ", node.data)
		node = node.nextNode

	}
	fmt.Printf("nil\n")
}

func reverseNode(list *Node) *Node {
	var newList *Node = nil
	var node *Node = list
	for node != nil {
		var tmpNode *Node = node.nextNode
		node.nextNode = newList
		newList = node
		node = tmpNode
	}
	return newList
}

func main() {
	var head *Node = inputList()

	printNode(head)

	var newList *Node = reverseNode(head)

	printNode(newList)
}
