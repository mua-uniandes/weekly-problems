n = int(input())
cad = input()

afuera = ""
adentro = ""

# Adentro de paréntesis
inside = False;

for c in cad:
    if (c == '('):
        inside = True
        afuera += "_"
    elif (c == ')'):
        inside = False
        adentro += "_"
    else:
        if inside:
            adentro += c;
        else:
            afuera += c;

# primer valor
cuenta = 0
elems_afuera = afuera.split("_")
for x in elems_afuera:
    cuenta = max(cuenta, len(x))
print(cuenta, end=" ")

cuenta = 0
elems_adentro = adentro.split("_")
for x in elems_adentro:
    if (len(x) > 0):
        cuenta = cuenta + 1

# segundo valor
print(cuenta)