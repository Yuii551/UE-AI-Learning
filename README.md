# Sentinel Lab

A learning-focused Unreal Engine 5 C++ AI sandbox built on the First Person template. Guards patrol a graybox level, pursue a visible player, investigate remembered player locations and reported noises, and return to patrol. The focus is decision flow, reusable ownership, interruption, and debugging rather than presentation or a complete game.

Developed with **UE 5.8.2**, C++, Blueprints, Behavior Trees, Blackboard, AI Perception, and NavMesh navigation. This is a single-player prototype in progress.

## Current behavior

- Ordered patrol routes with independent progression per Guard, including routes shared by multiple Guards.
- Safe handling of missing routes, empty routes, and invalid point references.
- Patrol advancement after arrival, with a separate delayed recovery path for failed movement.
- Sight detection filtered to player-controlled Pawns, with viewing-angle and wall-occlusion checks.
- Pursuit that interrupts patrol when the player becomes visible.
- Last-known-location investigation after sight loss, followed by a wait, memory cleanup, and patrol resumption.
- Hearing-based investigation using a reported noise location without identifying its emitter as the player target.
- Delayed investigation cleanup when a destination cannot be reached.

The intended Behavior Tree priority is:

```text
Chase visible player
  -> Investigate last seen player location
  -> Investigate accepted noise
  -> Patrol
  -> Idle/retry when no patrol destination exists
```

Hearing events are ignored while sight or remembered player information has priority.

## Architecture

| Element | Responsibility |
| --- | --- |
| `AGuardCharacter` | Owns the Guard's patrol component as a default subobject. |
| `APatrolRoute` | Stores an ordered array of level Target Point references. |
| `UPatrolComponent` | Owns one Guard's current index, wraps progression, and skips invalid entries using a bounded search. |
| `AGuardAIController` | Validates its Pawn in `OnPossess`, starts the Behavior Tree, and converts sight/hearing events into Blackboard knowledge. |
| `BT_Guard` / `BB_Guard` | Coordinate behavior priorities, movement, waiting, interruptions, and recovery. |
| C++ Behavior Tree tasks | Select and advance patrol points, and clear player/noise memory. |
| Target-memory service | Refreshes the remembered player location approximately every 0.2 seconds while the latest perception result confirms sight. |

Source is in [Source/SentinelLab](Source/SentinelLab). The primary AI assets are in [Content/AI/Guard](Content/AI/Guard).

The route holds shared configuration; each Guard holds its own progression. Selection preserves a valid destination until arrival. A patrol interruption therefore leaves the destination available for resumption. Failure recovery explicitly abandons an unreachable point rather than treating it as reached.

Player knowledge and noise knowledge are separate:

| Blackboard keys | Meaning |
| --- | --- |
| `PatrolPoint` | Current patrol destination. |
| `TargetActor`, `HasLineOfSight` | Player identity and current visibility state. |
| `LastKnownTargetLocation`, `HasLastKnownTargetLocation` | Remembered observed position and whether player memory exists. |
| `InvestigationLocation`, `HasInvestigationLocation` | Accepted noise position and whether noise memory exists. |

After sight loss, the memory service stops sampling the player's live position. This avoids using hidden movement as observed knowledge. Perception is updated on its own schedule, so memory reflects its latest sight result rather than an additional trace every service tick.
