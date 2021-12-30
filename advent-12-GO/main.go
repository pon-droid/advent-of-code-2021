package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
	"unicode"
)

func init_nodeset(input []string) map[string][]string {
	serial := make(map[string][]string)
	for i := range input {
		s := strings.Split(input[i], "-")

		node, node2 := s[0], s[1]
		temp, temp2 := serial[node], serial[node2]

		temp = append(temp, node2)
		temp2 = append(temp2, node)

		serial[node] = temp
		serial[node2] = temp2
	}
	return serial
}

func print_nodeset(nodes map[string][]string) {

	for key, val := range nodes {
		fmt.Println("=================")
		fmt.Println(key)
		fmt.Println(val)
		fmt.Println("=================")
	}
}

func init_visited(nodes map[string][]string) map[string]bool {
	visited := make(map[string]bool)
	for i := range nodes {
		visited[i] = false
	}
	return visited
}

func lowercase(temp string) bool {
	conv := temp[0]
	return unicode.IsLower(rune(conv))
}

func n_dfs_2(cave string, floor map[string][]string, patterns *int, visited *map[string]int) {
	if cave == "end" {
		*patterns++
		return
	}

	if lowercase(cave) {
		(*visited)[cave]++

		hit_small := 0
		for n_cave := range *visited {
			if (*visited)[n_cave] > 2 {
				hit_small++
			}

			if (*visited)[n_cave] > 2 {
				(*visited)[n_cave]--

				return
			}

			if hit_small > 2 {
				(*visited)[n_cave]--
				return
			}
		}
	}

	for _, n_cave := range floor[cave] {
		if n_cave == "start" {
			continue
		}

		n_dfs_2(n_cave, floor, patterns, visited)
	}

	if lowercase(cave) {
		(*visited)[cave]--
	}

}

func n_dfs(cave string, floor map[string][]string, patterns *int, visited *map[string]int, part int) {
	if cave == "end" {
		*patterns++
		return
	}

	if lowercase(cave) {
		(*visited)[cave]++
		hit_small := 0
		for n_cave := range *visited {
			if (*visited)[n_cave] > 1 {
				hit_small++

			}
			if (*visited)[n_cave] > part {
				(*visited)[cave]--
				return
			}

		}
		if hit_small > 1 {
			(*visited)[cave]--
			return
		}
	}

	for _, n_cave := range floor[cave] {
		if n_cave == "start" {
			continue
		}

		n_dfs(n_cave, floor, patterns, visited, part)
	}

	if lowercase(cave) {
		(*visited)[cave]--
	}

}

func dfs(visited *map[string]bool, nodes map[string][]string, node string) {
	if (*visited)[node] {
		return
	}

	(*visited)[node] = true

	fmt.Println(node)

	for key := range nodes {
		dfs(visited, nodes, key)
	}

}

func main() {

	file, _ := os.Open("input.txt")

	scanner := bufio.NewScanner(file)
	input := []string{}
	for scanner.Scan() {
		temp := scanner.Text()
		//fmt.Println(temp)
		input = append(input, temp)
	}

	nodes := init_nodeset(input)
	visited := make(map[string]int)
	patterns := 0
	n_dfs("start", nodes, &patterns, &visited, 2)
	fmt.Println(patterns)
	//print_nodeset(nodes)
	//dfs(&visited, nodes, "start")
	//fmt.Println(visited)
	//start, A, b, d, end, c

}
