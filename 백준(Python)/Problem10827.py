# --------------------------------------
# a^b
# --------------------------------------

from decimal import Decimal
from decimal import getcontext

inp = input().split()

getcontext().prec = 1101
a = Decimal(inp[0])
b = Decimal(inp[1])

print("{f}".format(pow(a, b)))