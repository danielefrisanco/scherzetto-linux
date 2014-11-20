 
#include <X11/Xlib.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
#include <string.h> 
#include <time.h> 
#include <unistd.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>

void mouseClick(int button)
{
	Display *display = XOpenDisplay(NULL);

	XEvent event;
	
	if(display == NULL)
	{
		fprintf(stderr, "Errore nell'apertura del Display !!!\n");
		exit(EXIT_FAILURE);
	}
	
	memset(&event, 0x00, sizeof(event));
	
	event.type = ButtonPress;
	event.xbutton.button = button;
	event.xbutton.same_screen = True;
	
	XQueryPointer(display, RootWindow(display, DefaultScreen(display)), &event.xbutton.root, &event.xbutton.window, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
	
	event.xbutton.subwindow = event.xbutton.window;
	
	while(event.xbutton.subwindow)
	{
		event.xbutton.window = event.xbutton.subwindow;
		
		XQueryPointer(display, event.xbutton.window, &event.xbutton.root, &event.xbutton.subwindow, &event.xbutton.x_root, &event.xbutton.y_root, &event.xbutton.x, &event.xbutton.y, &event.xbutton.state);
	}
	
	if(XSendEvent(display, PointerWindow, True, 0xfff, &event) == 0) fprintf(stderr, "Error\n");
	
	XFlush(display);
	
	usleep(100000);
	
	event.type = ButtonRelease;
	event.xbutton.state = 0x100;
	
	if(XSendEvent(display, PointerWindow, True, 0xfff, &event) == 0) fprintf(stderr, "Error\n");
	
	XFlush(display);
	
	XCloseDisplay(display);
}
int main(){//(int argc,char * argv[]) {
int i=0;
    int x , y;
	/*
x=atoi(argv[1]);
y=atoi(argv[2]);*/

    Display *display = XOpenDisplay(0);
	
 Window root = DefaultRootWindow(display);
 
Screen*  scrn = DefaultScreenOfDisplay(display);
int height = scrn->height;
int width  = scrn->width;
 srand (time(NULL));
 while (true ){
    XWarpPointer(display, None, root, 0, 0, 0, 0, x, y);

XFlush(display);
	x= rand() % width;
	y= rand() % height;
 usleep(300000);
 //mouseClick(Button1);
 }
XFlush(display);


    XCloseDisplay(display);
    return 0;
}



/*


ALTRO MODO




Display *display = NULL;
xdo_t *xdo = NULL;

void mouse_left_down(int x, int y)
{
  xdo_mousemove(xdo, x, y, 0)
  xdo_mousedown(xdo, CURRENTWINDOW, Button1); 
}

void mouse_left_up(int x, int y)
{
  xdo_mouseup(xdo, CURRENTWINDOW, Button1, 1, 0); 
}

void mouse_left_double_click(int x, int y)
{
  xdo_mousemove(xdo, x, y, 0);
  xdo_click_multiple(xdo, CURRENTWINDOW, Button1, 1, 0);
  doubleclick = TRUE;
}

int main()
{

  display = XOpenDisplay(NULL);
  if(display == NULL)
  {
    fprintf(stderr, "can't open display!\n");
    return -1;
  }
  xdo = xdo_new((char*) display);

  //some task here
  // ...

  return 0;
}




*/
