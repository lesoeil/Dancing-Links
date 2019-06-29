package taocp

import (
	"fmt"
	"math"
	"os"
)

//L is list
var L []uint64

type set64 map[uint64]bool

// List is
var list = make([]set64, 10)

/*AlgoL is the implementation of 7.1.2 Algorithm L (Find normal lengths).
This algorithm determines L(f) for all normal truth tables 0 ≤ f < 2^(2^n-1),
by building lists of all nonzero normal functions of length r for r ≥ 0.
*/
func AlgoL(n uint64) {
	var c uint64

	// L1. Initialize.
	var fTotal = Ppow2(n) / 2
	fmt.Printf("n: %d ppower: %d\n", n, fTotal)
	L = make([]uint64, fTotal)

	for i := range L {
		L[i] = math.MaxUint64
	}
	L[0] = 0

	//To check how many list will be needed.
	//for n = 4, seems the maximum length is 7 or 8?
	//var list [10]set64
	for i := range list {
		list[i] = make(set64)
	}
	x := make([]uint64, n+1)
	for k := 1; k <= int(n); k++ {
		x[k] = (Ppow(2, n) - 1) / (Ppow(2, n-uint64(k)) + 1)
		fmt.Printf("x[%d]: %x ", k, x[k])

		//Set L(x_k) <- 0
		L[x[k]] = 0

		//Put x_k into list 0
		var y = list[0]
		y[x[k]] = true
		if k == int(n) {
			fmt.Println()
		}
	}

	c = Ppow(2, n)/2 - (n + 1)
	//fmt.Printf("Number of places where L(f) = ∞ : %#x i.e. %d in decimal\n", c, c)

	/*
		c := int(math.Pow(2, (math.Pow(2, float64(n)) - 1)))
		fmt.Printf("0x%x Number of places when L(f) = ∞", c)
	*/

	var cc uint64
	for idx, v := range L {
		fmt.Printf("%d: %08x\n", idx, v)
		if v == math.MaxUint64 {
			cc++
		}
	}

	fmt.Printf("L(i) equal to %08x : %08x\n", uint64(math.MaxUint64), cc)
	fmt.Printf("Number of places where L(f) = ∞ : %#x i.e. %d in decimal\n", c, c)

	//L2. [Loop on r.] Do step L3 for r = 1, 2, ...; eventually the algorithm will
	//		terminate when c becomes 0.
	for r := 1; ; r++ {
		if c == 0 {
			fmt.Printf("c is %x , so terminate L2\n", c)
			break
		} else {
			fmt.Printf("c is %x , so loop L2 still run.\n", c)
		}
		algoL3(r, c)
	}

}

func algoL3(r int, c uint64) {
	fmt.Printf("Entering L3 with r = %x\n", r)
	for j, k := 0, r-1; j <= k; j, k = j+1, k-1 {
		algoL4(j, k, r, c)
	}
	fmt.Printf("Exit L3 with r = %x\n", r)
}

func algoL4(j int, k int, r int, c uint64) {
	fmt.Printf("Entering L4 with j = %x  k = %x\n", j, k)
	if j == k { //To restrict h to functions that follow g in list k

	} else {
		for g := range list[j] {
			for h := range list[k] {
				fmt.Printf("list[%d] g: %d  list[%d] h: %d \n", j, g, k, h)
				algoL5(g, h, r, c)
			}
		}
	}

	fmt.Printf("Exit L4 with j = %x  k = %x\n", j, k)
}

func algoL5(g uint64, h uint64, r int, c uint64) {

	var f uint64

	f = g & h
	algoL6(f, r, c)

	f = (math.MaxUint64 - g) & h
	algoL6(f, r, c)

	f = g & (math.MaxUint64 - h)
	algoL6(f, r, c)

	f = g | h
	algoL6(f, r, c)

	f = g ^ h
	algoL6(f, r, c)
}

func algoL6(f uint64, r int, c uint64) {
	if L[f] == math.MaxUint64 {
		L[f] = uint64(r)
		c = c - 1
		temp := list[r]
		temp[f] = true
	}

	if c == 0 {
		os.Exit(0)
	}
}

//Ppow2 return base 2 power of n
func Ppow2(n uint64) (expr uint64) {

	return Ppow(2, n)
}

//Ppow calls math.Pow twice to provide the result of (base^(base^n))
func Ppow(base uint64, n uint64) (expr uint64) {
	expr = uint64(math.Pow(float64(base), (math.Pow(float64(base), float64(n)))))
	return
}
