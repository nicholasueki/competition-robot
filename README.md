# Competition Robot — Constraint-Driven Autonomous Design

A fully autonomous robot designed for a timed engineering competition with strict limits on actuators and power sources. Every mechanism had to earn its place — no wasted motors, no wasted energy. The result was a machine built almost entirely around passive mechanical systems triggered by a single DC motor.

---

## Objective

Complete four distinct tasks in sequence with no human input after the start signal: knock over target figures, push objects away, retrieve objects, and — the hardest — place a payload on top of a tall central tower. The real constraint was doing all of this with a limited actuator budget, which forced every mechanism to be as simple and energy-efficient as possible.

---

## What I Designed and Built

### Elastic Band Claw (passive actuator — no motor required)

The tower placement task was the hardest challenge in the competition. Most teams either skipped it, used a dedicated motor for the gripper, or built spring-loaded mechanisms from mousetraps. Our approach needed none of that.

The claw uses a container to hold the fingers in the open position. When the claw is pressed down onto the target object, the container rides up, releasing the fingers — and the elastic band wrapped around them snaps them shut, securing the object. No trigger motor. No servo. Just the claw meeting the object closes it automatically.

The elevator — a multi-segment assembly driven by a single DC motor coiling nylon fishing line — then pulls the entire claw assembly straight up and holds it at tower height. The motor winds, the segments extend, the payload crests the tower. One motor does the full job.

### Crossbow Arms (dual-function retrieval system)

A pair of extendable arms designed to first push objects aside, then retrieve objects by pulling them in. Each arm has elastic-band-powered "hands" that extend outward on deployment. A shared string then winds both arms back simultaneously — the inward pull drags the target objects into position. One winding mechanism controls both arms in sync.

### Control System

Arduino-based state machine sequencing all mechanisms with timed delays. With passive actuators handling the mechanical work, the software just needed to fire events in the right order and hold positions long enough for the mechanisms to complete.

---

## Challenges

**Actuator budget** — Every mechanism had to be justified. Designing the claw to close passively (using the act of grabbing as the trigger) was the key insight that freed up an actuator for the elevator lift itself.

**Elevator reliability** — A fishing-line-driven multi-segment elevator has a lot of ways to bind or mis-sequence. Getting the segment geometry right so each stage extended cleanly before the next took significant physical iteration.

**Arm synchronization** — Winding both crossbow arms back with a single string required careful routing so tension was distributed evenly — uneven pull caused the robot to torque sideways instead of retrieving the object.

**Open-loop execution** — Once started, there's no error correction. Every mechanical tolerance had to be tight enough that the sequence worked reliably across multiple runs, not just in testing.

---

## Tech Stack

- **Microcontroller:** Arduino (C++)
- **Libraries:** myDuino
- **Actuators:** DC motor (elevator + arm wind), solenoids, pneumatic pistons
- **Passive mechanisms:** Elastic band claw, elastic band arm extensions, nylon fishing line drive
- **Fabrication:** 3D printed elevator segments, 3D printed claw assembly, custom arm geometry
