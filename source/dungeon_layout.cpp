//   ________________________________________________________
//   | 0,0 Z    | 0,1 Z    | 0,2 Z    | 0,3 Z    | 0,4 Z    |
//   |              M01       Hint 30    M03       Reward   |
//   |  START!                                              |
//   |                                                      |
//   |__      __|__________|__      __|__________|__\/\/\/__|
//   | 1,0 C    | 1,1 C    | 1,2 C    | 1,3 C    | 1,4 C    |
//   |  Reward  |  Key11   X             M13                |
//   |          |  Reward  X  PUZZLE               REST     |
//   |          |          X                       (heal)   |
//   |__      __|__      __|__________|__________|__      __|
//   | 2,0 Z    | 2,1 Z    | 2,2 Both | 2,3 Z    | 2,4 Z    |
//   |             M21     |  M22     X  Key23   |  Trap    |
//   |  REST               |          X          |          |
//   |  (heal)             |          X          |          |
//   |__      __|__________|__________|__      __|__      __|
//   | 3,0 Z    | 3,1 Z    | 3,2 C    | 3,3 C    | 3,4 C    |
//   |          X  Key31   |  Key32   |  Trap    |  M34     |
//   |  PUZZLE  X          |          |          |          |
//   |          X  reward  |  reward  |          |  reward  |
//   |__      __|__________|__XXXXXX__|__      __|__      __|
//   | 4,0 C    | 4,1 C    | 4,2 C    | 4,3 Z    | 4,4 C    |
//   |  Trap       M41        Hint 42               Hint 12 |
//   |                                  REST                |
//   |             reward     PUZZLE    (heal)              |
//   |__________|__________|__________|__________|__________|
//
//
//
// KEY:
//
// XXX = locked door
//
// M__ = monster (numbers correspond to room address for variable naming)
//
// Hint __ = hint for room _,_
//
// Z = Zach's room
// C = Cade's room
//
// Future: More Friendly UI | Random Maze Generation | 