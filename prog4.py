from datetime import datetime, timezone

start = int(datetime.now(timezone.utc).timestamp() * 1_000_000)
# arr of 8 in 30
baseline = ["8"] * 30
to_change = [
    [1],
    [],
    list(range(13,17)) + list(range(24,26)),
    list(range(9,20)) + list(range(22, 25)),
    list(range(7, 13))+ list(range(20,24)),
    list(range(6,10)) + list(range(18, 25)),
    list(range(6,9)) + list(range(16, 19)) + list(range(21,24)),
    list(range(6,9)) + list(range(14,17)) + list(range(22, 25)),
    list(range(6,10)) + list(range(21, 24)),
    list(range(7,10)) + list(range(18,24)),
    list(range(6,10)) + list(range(10, 22)),
    list(range(4,6)) + list(range(11, 19)),
    [],[-1]
]
for t in range(0,1000000):
    for i in range(0,14):
        this_line = baseline.copy()
        for each in to_change[i]:
            this_line[each] = 1 if i != 0 else 0
    
end = int(datetime.now(timezone.utc).timestamp() * 1_000_000)
time_taken = end -  start
print("Time taken in micro seconds", time_taken)
print("Time taken in milli seconds", time_taken/1000)
print("Time taken in seconds", time_taken/1_000_000)