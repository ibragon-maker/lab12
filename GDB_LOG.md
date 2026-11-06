# GDB log

One dated section per week. Paste the commands you used and the output you saw, then explain what it means in your own words. Pasted output with no explanation earns partial credit at most.

## Week 12 (Lab 12)

### The constructor chain

Commands, in the order you typed them, with one line on what each did:

Backtrace inside `Hangman::Hangman` (paste it):

Backtrace inside `Game::Game` (paste it):

Where `finish` returned to:

Order of destructor breakpoints when the program ended:

Construction order and destruction order, as read from the backtraces:

### What a base pointer shows

`print hangman` (paste it):

`print *g` (paste it):

What is different, and why:

`ptype Hangman` and `ptype g` (paste them):

One sentence on what `ptype Hangman` revealed about inheritance:

# GDB Debugging Log & Lab Notes

## Task 4: Constructor and Destructor Chain Tracing

1. **Start GDB and set breakpoint:** 
   - `break Hangman::Hangman` set successfully.

2. **Which constructor is running, and who called it?**
   - `Hangman::Hangman` runs first, and it is called from `main` in `app/main.cpp`.

3. **Which constructor is on top now after stepping into the base initializer?**
   - `Game::Game` is on top because the derived constructor initializes the base class first.

4. **Where do you land after `finish`?**
   - You land back inside the `Hangman::Hangman` constructor body/exit, which then returns control back to `main`.

5. **Record the order of destructors:**
   - The derived destructor (`Hangman::~Hangman`) runs first, followed immediately by the base destructor (`Game::~Game`) when the program exits.

---

## Task 5: Dungeon and Blackjack Notes

* **Why you did not need to write a custom copy constructor or destructor:**
  - Because these classes only wrap an existing game function and hold a primitive integer (`m_times_played`), the compiler-generated default copy constructor and destructor handle member-wise copying and cleanup safely without any manual dynamic memory management (no raw pointers or `new`/`delete`).

---

## Task 8: Base Pointer and Type Inspection (`whatis` and `ptype`)

1. **`whatis minesweeper` result:**
   - `type = Minesweeper`

2. **`ptype minesweeper` result:**
   - Displays the class layout: inherits from `Game`, contains `int m_times_played;`, and exposes constructor, `play(void)`, and `times_played(void) const`.

3. **`whatis g` and `ptype g` (Base Pointer `Game *g = &hangman;`):**
   - `whatis g` reports `Game *` (the declared base pointer type).
   - `ptype` on the derived object explicitly reveals the inheritance relationship (`: public Game`) and lists both the base structure and class-specific members.
