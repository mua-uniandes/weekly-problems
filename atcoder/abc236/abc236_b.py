Number = int(input())
numbers = list(str(input()).split(" "))
numbers = map(int, numbers)

numero_esperado = sum(range(1, Number + 1)) * 4
suma_total_numbers = sum(numbers)

print(numero_esperado - suma_total_numbers)