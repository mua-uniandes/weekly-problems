from collections import defaultdict
import sys
import time
import queue


class SiloState:
    def __init__(self, silos: list[str], c: int, d: int) -> None:
        self.silos = silos
        self.d = d # distance from the initial state
        self.c = c
        # So permutations are considered the same
        self.hash = sum(hash(silo) for silo in silos)

    def one_char(self, s):
        for c in s:
            if c != s[0]:
                return False
        return True

    def is_sorted(self, grain_count: dict):
        """Check if the silos are sorted"""
        return all(
            # empty or
            len(silo) == 0 or 
            # have 1 type of grain - and all the sacks for that grain
            (self.one_char(silo) and len(silo) == grain_count[silo[0]]) 
            for silo in self.silos)

    def __hash__(self):
        return self.hash
    
    def __eq__(self, other):
        return hash(self) == hash(other)
    
    def __str__(self):
        s = f" = {self.d}\n"
        for h in range(self.c -1, -1, -1):
            for silo in self.silos:
                if h < len(silo):
                    s += silo[h]
                else:
                    s += '.'
            s += "\n"
        s += "-"*len(self.silos) + "\n"
        return s

    def adjacent_states(self):
        """Get a list of all adjacent states"""
        states = []
        for i, origin in enumerate(self.silos):
            for j, dest in enumerate(self.silos):
                if i == j:
                    continue
                # try moving a grain lot from silo i to silo j
                # j has to have space for the grain
                # i has to be non-empty, j has to be empty or have the same grain in the top
                if len(origin) > 0 and len(dest) < self.c and  (
                    len(dest) == 0 or origin[-1] == dest[-1]
                ):
                    # Create a new state
                    new_silos = self.silos.copy()
                    # move from i to j
                    new_silos[j] += new_silos[i][-1]
                    new_silos[i] = new_silos[i][:-1]
                    # increment distance
                    new_state = SiloState(new_silos, self.c, self.d + 1)
                    states.append(new_state)
        return states

def sort_silos(silos: list, grain_count: dict, c: int) -> int:
    """Process the silos to sort them"""
    visited: set[SiloState] = set()
    que: queue.Queue[SiloState] = queue.Queue()
    is_in_queue: set[SiloState] = set() # to quickly verify queue
    initial = SiloState(silos, c=c, d=0)
    que.put(initial)
    is_in_queue.add(initial)
    n = 0
    # BFS
    while not que.empty():
        n += 1
        state = que.get()
        is_in_queue.remove(state)
        visited.add(state)
        if state.is_sorted(grain_count):
            # print(state)
            return state.d
        # traverse all adjacent states
        states = state.adjacent_states()
        for state2 in states:
            if state2 not in is_in_queue and state2 not in visited:
                que.put(state2)
                is_in_queue.add(state2)
    return -1

# Read input
if __name__ == "__main__":
    _s, _c = input().split()
    s, c = int(_s), int(_c)


    while s != 0 and c != 0:
        silos: list = [[] for _ in range(s)]
        grain_count: dict = defaultdict(int)
        # Read c lines
        for _ in range(c):
            line = input()
            # from top to bottom
            for i, g in enumerate(line):
                if g != '.':
                    silos[i].insert(0, g)
                    grain_count[g] += 1
        silos = ["".join(silo) for silo in silos]
        t = time.time()
        r = sort_silos(silos, grain_count, c)
        print(r if r != -1 else "Camelot Will Starve!")
        if len(sys.argv) > 1 and sys.argv[1] == "-m":
            print(f"\t{s}\t{c}\t{(time.time() - t):3f}")
        _s, _c = input().split()
        s, c = int(_s), int(_c)
