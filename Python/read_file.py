import sys

class Snake:

	def __init__(self, index, length, map):
		self.index = index
		self.length= length
		self.map = map
	
	def find_max_path(self, map, length):
		rows = len(map)
		cols = len(map[0])
		directions = [(0, 1), (1, 0), (0, -1), (-1, 0)]  # right, down, left, up
		
		def wrap_around(row, col):
			# Wrap around the map edges
			if row < 0:
				row = rows - 1
			elif row >= rows:
				row = 0
			if col < 0:
				col = cols - 1
			elif col >= cols:
				col = 0
			return row, col
		
		def dfs(row, col, moves_left, visited, path):
			if moves_left == 0:
				return 0, []
			max_points = 0
			max_path = []
			for d in directions:
				r = row + d[0]
				c = col + d[1]
				r, c = wrap_around(r, c)
				if (r, c) not in visited:
					visited.add((r, c))
					path.append((r, c))
					points, sub_path = dfs(r, c, moves_left - 1, visited, path)
					path.pop()
					visited.remove((r, c))
					try:
						if map[r][c] == "*":
							points = map[r][c] + dfs(*teleport[r, c], moves_left-1, visited, path)[0]
						points += map[r][c]
						if points > max_points:
							max_points = points
							max_path = sub_path
					except:
						pass
			return max_points, [(row, col)] + max_path
		
		max_score = 0
		max_path = []
		teleport = {}
		for i in range(rows):
			for j in range(cols):
				try:
					if map[i][j] == "*":
						teleport[i, j] = None
				except:
					pass
		for i in range(rows):
			for j in range(cols):
				for k in range(1, length + 1):
					visited = set()
					visited.add((i, j))
					path = [(i, j)]
					score, sub_path = dfs(i, j, k - 1, visited, path)
					if score > max_score:
						max_score = score
						max_path = sub_path
						for point in path[1:]:
							map[point[0]][point[1]] = "f"
		moves = []
		for i in range(1, len(max_path)):
			prev = max_path[i-1]
			curr = max_path[i]
			if curr[0] > prev[0]:
				moves.append("R")
			elif curr[0] < prev[0]:
				moves.append("L")
			elif curr[1] > prev[1]:
				moves.append("D")
			elif curr[1] < prev[1]:
				moves.append("U")
			if prev in teleport.values():
				for pos, dest in teleport.items():
					if dest == prev:
						moves.append(dest)
						break
			map[curr[0]][curr[1]] = "f"
		moves.insert(0, max_path[0])
		return moves

	def ft_move(self):
		moves = self.find_max_path(self.map, self.length + 1)
		return moves


def	ft_readfile(filename):
	with open(filename, mode="rt") as  f:
		count = 0
		map = []
		for line in f:
			if not count:
				config = line.rstrip().split()
			elif count == 1:
				snake_len = line.rstrip().split()
			else:
				map.append(list(int(x) for x in line.rstrip().split() if x.isdigit()))
			count += 1
	snakes = [Snake(x, int(y), map) for x, y in enumerate(snake_len)]
	return snakes

def	ft_init_snakes():
	snakes = ft_readfile(sys.argv[1])
	for x in snakes:
		moves = x.ft_move()
		with open("result.txt", "at") as f:
			for out_put in moves:
				if isinstance(out_put, tuple):
					a, b = out_put
					f.write(str(a))
					f.write(" ")
					f.write(str(b))
					f.write(" ")
				else:
					f.write(out_put)
					f.write(" ")
			f.write("\n")

if __name__ == "__main__":
	ft_init_snakes()