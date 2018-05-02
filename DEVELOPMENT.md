# Development

## April 21, 2018
Today I did some research on the logistics of the game and looked how I can use the libraries available to help me with the project amd got started with some of the code.

## April 22, 2018
Today I started to do the actual code and will start on the basic flight mechanics of the bird with the jumping and realistic gravity and such. Gravity is based on a singular variable speed and will have a constant value being added to it, which gives it a feel of there being gravity.

## April 23, 2018
Implemented Gravity and tweaked values to have optimal jumping. Now begun to add basic piping structures.

## April 24, 2018
Today I updated the README.md to show how another person can run the program locally to get the same results. Also added the pipes and kind of got it to work in the sense that now it moves across the screen in a predictable manner. One thing that didnt work was the random height generator. I originally wanted it to work so that the gaps from the walls will be randomized but instead it generated a single number that was constant for most of the time and that was bad. NEED TO FIX later. In the bird class I added a bit more functions so that I can acess the info from that classa  lot better and help through.

## April 25, 2018
Nothing done.

## April 26, 2018
Today I mainly focoused on getting the pipes to work. The pipes are the next main thing that I should focous on going forward with the project because they are an integral portion of the game in general. One thing that I added to the pipes is the getters so I can use them for other portions of the project such as collision detection. I was fliddling around with it more to see if I can get a fix in for the random number, still havn't found a solution.

## April 27, 2018
I did nothing today.

## April 28, 2018
I did nothing today.

## April 29, 2018
Today I also worked more on the pipe random number generator, was looking through google to solve it, still coudn't find it. I instead worked on figuring out what to do when the pipe went off the screen. I was thinking if I could do something where I could have the pipe loop around the screen but after some  testing decided against it. I tried to remove the pipes when they went off screen because they are if no use to me. After testing aroudn with that a bit more, I coudn't get that also to work. After more testing I simply settled on having the pipe present and not delete it when it went off screen. If i have more time later I might work on fixing the issue.

## April 30, 2018
Today I finally fixed the pipe spawning issue. Turns out I was using the wrong code, I had the max and min variables swapped so it was multiuplying the random number by 1 and adding the max value onto it which messed everything up. After swapping the values, everything worked to perfection and the pipes spawn as they should which is a real benefit.

## May 1, 2018
Today I worked on getting the collision detection. So I brainstormed over this idea and the best solution that came to mind was to find the y space between the both pipes and when I did an if statemnt that constricted the bounds of the bird being travelled to the x location of the current pipe and the y location of the pipe. It worked. Now the game has collision detection which is really nice. The only things left is the pause menu and the death screen and I should be done.

## May 2, 2018
Today I worked on getting the sounds incorporated and the animations all sorted out. I was able to get the animations done easily by simply setting the bird animation to vary on the speed of the bird. I also got the sound to work by having the sound pay everytime the space bar was pressed. This added the sound of the bird flapping.
