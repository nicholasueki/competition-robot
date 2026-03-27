# Competition Robot — Autonomous Electromechanical Task Sequencer

An autonomously operating robot built for a timed engineering design competition. Executes a precise multi-step mechanical task sequence using encoder feedback, pneumatic actuators, and timed motor control — with no human input after the start signal.

---

## Objective

Design and build a robot that can complete a specific mechanical task sequence in a timed competition environment — with no human input after the start signal. The challenge: coordinate motors, solenoids, and pneumatic pistons in the right order, at the right speed, reliably enough to score under pressure.

---

## What I Built

The control system is an Arduino-based state machine that drives the robot through a scripted sequence:

- **Interrupt-driven encoders** on pins 2 and 3 track wheel rotation for movement accuracy
- **PWM motor control** with variable speed (0–255) for precise forward/backward positioning
- **Solenoid/pneumatic actuation** sequences with carefully tuned delays for arm extension, wall interaction, and payload release
- **Multi-phase execution** — the program coordinates separate motor and actuator phases in sequence, with each stage gated by timing and encoder counts

The code went through significant iteration from an initial prototype (`task1.ino`) to the final competition version, refining the actuation timing and motor speed profiles based on physical testing.

---

## Challenges

**Timing sensitivity** — The robot's success depended on millisecond-level timing between motor phases and solenoid triggers. Small inconsistencies in surface friction or battery voltage could throw off the whole sequence, requiring repeated physical calibration.

**Encoder reliability under load** — Interrupt-driven encoder counts occasionally missed pulses under high motor current, requiring debounce logic and conservative speed profiles to maintain positional accuracy.

**No feedback after start** — The open-loop nature of competition robots means there's no error correction mid-run. Every edge case had to be anticipated and hardcoded — there's no "retry."

---

## Tech Stack

- **Microcontroller:** Arduino (C++)
- **Libraries:** myDuino (custom hardware abstraction layer)
- **Control:** PWM motor control, interrupt service routines (ISR) for encoder counting
- **Actuators:** DC motors, solenoids, pneumatic pistons
