import sys

#I finally made city groups.
#If there are place that he cannot go by any route, 
#it means that city is not contained in current group.
#In short, if there exist any city that connects two city group, we can regard those groups as one group
def get_groups(number: int) -> list:
    groups: list[set] = [{-1}] # -1 is a dummy set
    for city in range(number):
        # insert index that stores True(connected city number) to set
        connection: set = set(idx for idx, status in enumerate(list(map(int, sys.stdin.readline().rstrip().split(' ')))) if status) 
        connection.add(city)
        groups.append(connection)
        for gidx, group in enumerate(groups):
            if not connection.isdisjoint(group): # If there is any intersection
                groups[gidx] = group | connection # Modify group in groups to union of group, connection
                break 

    del groups[0] # Delete dummy set
    return groups
            

def go_trip_together(plans: set, groups: list) -> bool:
    status: bool = False
    for group in groups:
        if group & plans == plans: # If all planed cities are in one group
          status = True
    return status

# inputs
cities: int = int(sys.stdin.readline())
plancities: int = int(sys.stdin.readline())
groups: list = get_groups(cities)
plans: list = set(i - 1 for i in map(int, sys.stdin.readline().rstrip().split(' '))) # minus 1 for every item, so we can regard every city as an index
status: bool = go_trip_together(plans, groups)
# output
sys.stdout.write('YES' if status else "NO")
