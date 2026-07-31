# Competition Robot

An autonomous robot built for a Georgia Tech design competition. Once the round starts, it runs
a fixed sequence of tasks with no human input.

![Final design overview](media/final_design_overview.png)

## The competition

- 4 person team, one semester
- Minecraft themed arena with four scoring tasks
- Hard limits on actuators, power, size and materials
- No human control after the start signal

## Final design

Two mechanisms did the work.

**Extend and Block**, also called the crossbow arms, falling arms, or wall bouncer. All four
names describe the same system:

- A long arm drops across the arena with a bouncer at the tip
- Elastic band powered hands extend outward to push objects aside
- A shared string then winds both arms back at once, dragging targets in
- One winding mechanism moves both arms together, so the two motions cost one actuator

**Passive claw and lift**, for placing a payload on top of the tower:

- A container holds the claw fingers open
- Pressing the claw down onto an object lets the container ride up, and an elastic band snaps the
  fingers shut
- Grabbing the object is what triggers the claw, so it needs no motor or servo of its own
- A segmented lift, pulled by one DC motor winding nylon line, raises the whole claw to tower
  height and holds it there

## Dropped along the way

- **Deployable cart:** built and tested as a prototype, then removed before the final robot

## How it works

- Pneumatic cylinders drive the main motions
- An Arduino runs a state machine that fires each mechanism in order on timed delays
- The sequence is open loop, so nothing corrects itself once the round starts
- That put the burden on mechanical tolerances, which had to be tight enough to repeat the same
  run every time rather than work once on the bench

## Tools

- Arduino, C++, myDuino library
- Pneumatic cylinders and solenoids
- DC motors
- 3D printed parts
- CAD for the full assembly

## Files

- `code/` Arduino sketches, including the final competition sequence
- `media/` design overview, renders, and a claw test clip
