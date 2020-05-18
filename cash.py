from cs50 import get_float

COINS = [25, 10, 5, 1]
total_coins = 0

change = (get_float("Change owed: ") * 100)

if change < 0:
    exit()

for coin in COINS:
    total_coins += (change - (change % coin))/coin
    change = (change % coin)

print(total_coins)