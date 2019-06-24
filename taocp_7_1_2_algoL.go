package taocp

import (
	"fmt"
	"math"
)

/*AlgoL is the implementation of 7.1.2 Algorithm L (Find normal lengths).
This algorithm determines L(f) for all normal truth tables 0 ≤ f < 2^(2^n-1),
by building lists of all nonzero normal functions of length r for r ≥ 0.
*/
func AlgoL(n uint64) {
	var c uint64

	// L1. Initialize.
	var fTotal = Ppow2(n) / 2
	fmt.Printf("n: %d ppower: %d\n", n, fTotal)
	L := make([]uint64, fTotal)

	for i := range L {
		L[i] = math.MaxUint64
	}
	L[0] = 0

	type set64 map[uint64]bool

	//To check how many list will be needed.
	//for n = 4, seems the maximum length is 7 or 8?
	var list [10]set64
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
