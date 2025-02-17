def get_maximal_number_of_kids(n: int) -> int:
    # Using arithmetic sequence sum formula: n >= k*(k+1)/2
    # where k is number of kids
    k = int((-1 + (1 + 8*n)**0.5) / 2)
    return k

def get_candies_for_kids(n: int, k: int) -> list:
    # First k-1 kids get 1,2,3,...,k-1 candies
    candies = list(range(1, k))
    # Last kid gets remaining candies
    last_kid_candies = n - (k * (k-1) // 2)
        
    candies.append(last_kid_candies)
    return candies

intput_n = int(input())
k = get_maximal_number_of_kids(intput_n)
candies = get_candies_for_kids(intput_n, k)

print(k)
print(" ".join([str(c) for c in candies]))