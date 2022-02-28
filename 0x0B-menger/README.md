# 0x0B. Menger sponge
```
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
#########         #########
# ## ## #         # ## ## #
#########         #########
###   ###         ###   ###
# #   # #         # #   # #
###   ###         ###   ###
#########         #########
# ## ## #         # ## ## #
#########         #########
###########################
# ## ## ## ## ## ## ## ## #
###########################
###   ######   ######   ###
# #   # ## #   # ## #   # #
###   ######   ######   ###
###########################
# ## ## ## ## ## ## ## ## #
###########################
```
## 🍎📚 Resources 📚🍎
* [Minecraft Menger sponge](https://youtu.be/d-dI_pu_Z0g)
* [science project menger sponge, for fun](https://youtu.be/UAY6b9DqX6U)
* [slicing a menger sponge](https://youtu.be/fWsmq9E4YC0)
* [Processing menger sponge coding challenge](https://youtu.be/LG8ZK-rRkXo)


## 0. 2D Menger sponge
### Write a function that draws a 2D Menger Sponge
* Prototype: void menger(int level);
* Where level is the level of the Menger Sponge to draw
* If level is lower than 0, your function must do nothing
* You’re allowed to use the math library. Your program will be compiled using the ld flag -lm
### Format:
#### Here, we will only draw a 2D version of the Menger sponge. 
* A level N sponge is a 3x3 square of level N-1 sponges, except for the center one, which is left empty.
* A level 0 sponge is represented by the # character.
### Examples:
* A level 0 sponge is a simple 1x1 square
* A level 1 sponge is a 3x3 square of level 0 sponges, except for the center one, which is left empty
* A level 2 sponge is a 3x3 square of level 1 sponges, except for the center one, which is left empty
### The size of a level N Menger sponge is calculated as follows: 3^N