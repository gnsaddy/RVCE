package testapplet;

import java.awt.event.*;
import java.applet.*;
import java.awt.*;
/*
	<applet code="Program8" width=300 height=300 >
	</applet>
	*/

public class Program8 extends Applet implements KeyListener
{
    int x=20,y=30;
    String msg="key events";
    public void init()
    {
        addKeyListener(this);
    }
    public void keyPressed(KeyEvent e)
    {
        showStatus("key pressed");
        int key=e.getKeyCode();
        switch(key)
        {
            case KeyEvent.VK_UP:
                msg+="<UP ARROW>";
                showStatus("move to up");
                break;
            case KeyEvent.VK_DOWN:
                msg+="<DOWN ARROW>";
                showStatus("move to down");
                break;
            case KeyEvent.VK_LEFT:
                msg+="<LEFT ARROW>";
                showStatus("move to left");
                break;
            case KeyEvent.VK_RIGHT:
                msg+="<RIGHT ARROW>";
                showStatus("move to right");
                break;
            case KeyEvent.VK_ENTER:
                msg+="<BUTTON ENTER>";
                showStatus("enter key pressed");
                break;
        }
        repaint();
    }
    public void keyReleased(KeyEvent e)
    {
        showStatus("key released");
    }
    public void keyTyped(KeyEvent e)
    {
        msg+=e.getKeyChar();
        repaint();
    }
    public void paint(Graphics g)
    {
        g.drawString(msg,x,y);
    }
}