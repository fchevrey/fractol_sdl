project fractol of 42 school
the purpose is to display fractals and enabled the controller to :
- change the fractal on runtime, 
- zoom deeply on it,
- change colors 
- move around

to acelerate render, I implement multi-threading using pthread c library.

the programm display 3 fractals  : Mandelbroath, Julia and burningship

The controls are :
- c	  :	change color
- 'f'	  :	change fractal
- '*'   :	precision +
- '/'	  :	precision -
- '+'	  :	zoom up
- '-'	  :	zoom down
- 'ESC' : Quit

arrows	    :	move
mouse Wheel	:	zoomm at a precise point

on JULIA :
mouse move change the value of the fractal
L	:	lock the mouse position

some screenshots : 

Burningship
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Burningship.png)
Julia
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Julia2.png)
Mandelbroath
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Mandelbroath2.png)

![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Mandelbroath3.png)
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Mandelbroath4.png)
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Mandelbroath5.png)
![alt text](https://github.com/fchevrey/fractol_sdl/blob/master/Screenshots/Julia.png)
