import random

def dist(p1, p2):
  x1, y1 = p1
  x2, y2 = p2
  return ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5

def evaluate(sol, graph):
  total = 0
  for i in range(len(sol) - 1):
    p1, p2 = graph[sol[i]], graph[sol[i + 1]]
    total += dist(p1, p2)
  total += dist(graph[sol[-1]], graph[sol[0]])
  return total

def init_pop(graph, size):
  n = len(graph)
  pop = []
  for _ in range(size):
    sol = list(range(n))
    random.shuffle(sol)
    pop.append(sol)
  return pop

def select(population):
  return random.choices(population, k=2)

def cross(parents):
  parent1, parent2 = parents
  num_pts = len(parent1)
  start = random.randint(0, num_pts - 2)
  end = random.randint(start + 1, num_pts - 1)
  child = [-1] * num_pts
  child[start: end + 1] = parent1[start: end + 1]
  remaining_points = [point for point in parent2 if point not in child]
  remaining_index = 0
  for i in range(num_pts):
    if child[i] == -1:
      child[i] = remaining_points[remaining_index]
      remaining_index += 1
  return child

def mutate(sol, ratio):
  mutated_sol = sol.copy()
  for i in range(len(mutated_sol)):
    if random.random() < ratio:
      j = random.randint(0, len(mutated_sol) - 1)
      mutated_sol[i], mutated_sol[j] = mutated_sol[j], mutated_sol[i]
  return mutated_sol

def next_gen(pop, cross_ratio, mut_ratio):
  new_pop = []
  while len(new_pop) < len(pop):
    prnts = select(pop)
    chld = cross(prnts) if random.random() < cross_ratio else random.choice(prnts)
    mut_chld = mutate(chld, mut_ratio)
    new_pop.append(mut_chld)
  return new_pop

def genetic(graph, pop_size, num_gens, cross_ratio, mut_ratio):
  pop = init_pop(graph, pop_size)
  best_sol = None
  best_dist = float('inf')
  for _ in range(num_gens):
    for sol in pop:
      dist = evaluate(sol, graph)
      if dist < best_dist:
        best_sol = sol
        best_dist = dist
    pop = next_gen(pop, cross_ratio, mut_ratio)
  best_sol.append(best_sol[0])
  return best_sol, best_dist

def get_graph():
  G = [[0, 3],
      [7, 5],
      [6, 0],
      [4, 3],
      [1, 0],
      [5, 3],
      [2, 2],
      [4, 1]]
  return G

graph = get_graph()
pop_size = 100
num_gens = 100
cross_ratio = 1.0
mutate_ratio = 0.01

best_solution, best_distance = genetic(graph, pop_size, num_gens, cross_ratio, mutate_ratio)

print("이동 순서 : ", best_solution)
print("이동 거리 : ", best_distance)