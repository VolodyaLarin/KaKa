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

func printNode(list *Node) {
	var node *Node = list

	for 0; node != nil; 0 {
		printf("%d -> ", (*node).data)
		node = (*node).nextNode

	}
	printf("nil\n")
}

func reverseNode(list *Node) *Node {
	var newList *Node = nil
	var node *Node = list
	for 0; node != nil; 0 {
		var tmpNode *Node = (*node).nextNode
		(*node).nextNode = newList
		newList = node
		node = tmpNode
	}
	return newList
}

func main() int {
	var head *Node = newNode(228, newNode(11, newNode(12, newNode(13, nil))))

	printNode(head)

	var newList *Node = reverseNode(head)

	printNode(newList)

	return 0
}
