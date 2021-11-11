# ProjectAP: DoodleJump

1 Introduction

This year’s project consists of designing and implementing an interactive game, inspired by Doodle Jump1
, in
C++ and using the SFML2 graphics library. The main goal of this project is to demonstrate that you are able
to create a well-designed architecture, fully utilize advanced C++ features and provide high-quality code that
implements the requirements. Of course, it’s great if you add creative extra features or fancy graphics and
animations, but make sure the basics work well first and you have a good, extendable codebase to work with.

2 Gameplay

The game consists of three main entities: a player, various platforms and potential bonuses. The player is always jumping up and
down automatically, without any user interaction. The user can
however move the player character to the left or to the right by
pressing the A or left arrow and D or right arrow keys respectively.
If this movement is done correctly, the player will jump on top of a
higher platform, helping it move further up in the world. Hitting a
platform from below allows the player to completely pass through
it unhindered. But when landing on it from above, the player
will bounce off the platform, allowing it to reach a new maximum
height. The goal of this game is therefore for the player to climb as
high as possible, without falling off the world. When the player falls
to the bottom of the screen, where there is no platform to stand on,
the game ends. A current score is shown on the top of the screen
(or anywhere else) during gameplay and an all-time high-score is
shown when the game ends. Each time the player reaches a new
maximum height, the current view of the world is moved upwards
such that this newly reached height is in the middle of the screen.
All platforms that are no longer within view are removed from the
world and new platforms are generated for the section of the world
that has recently come into view. In theory, this world generation
extends upwards infinitely, as long as the player does not fall off
the platforms.

There are 4 different platform types that can be generated:

Static platforms: occur the most often and simply stay in a fixed position within the world. (Green)

Horizontal platforms: move back and forth horizontally across the screen. (Blue)

Vertical platforms: move back and forth vertically between a fixed minimum and maximum height. (Yellow)

Temporary platforms: disappear after they have been jumped on once. (White)

On top of some of these platforms, bonuses can also be present, with which the player can interact to gain one
of two benefits:

Springs: When jumping on one of these, the player is given an extra boost, making the jump 5x as high.

Jetpacks: These allow the player to shoot up by a much more considerable distance (up to you to decide).