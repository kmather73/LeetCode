func twoSum(nums []int, target int) []int {
    x := make([]int, 0, 2)
    m := make(map[int]int)
    
    for i, num := range nums {
        j, e := m[target-num]
        if e {
            x = append(x, i)
            x = append(x, j)
            break
        }
        m[num] = i
    }

    return x
}
