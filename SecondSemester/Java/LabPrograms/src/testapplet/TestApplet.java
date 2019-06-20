package testapplet;
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
/*
<applet code="TestApplet" width=300 height=400>
</applet>
*/
public class TestApplet extends Applet implements KeyListener
{
    int X=20,Y=30;
    String msg="KeyEvents--->";
    public void init()
    {
        addKeyListener(this);
        requestFocus();
        setBackground(Color.green);
        setForeground(Color.blue);
    }
    public void keyPressed(KeyEvent k)
    {
        showStatus("KeyDown");
        int key=k.getKeyCode();
        switch(key)
        {
            case KeyEvent.VK_UP:
                showStatus("Move to Up");
                break;
            case KeyEvent.VK_DOWN:
                showStatus("Move to Down");
                break;
            case KeyEvent.VK_LEFT:
                showStatus("Move to Left");
                break;
            case KeyEvent.VK_RIGHT:
                showStatus("Move to Right");
                break;
        }
        repaint();
    }
    public void keyReleased(KeyEvent k)
    {
        showStatus("Key Up");
    }
    public void keyTyped(KeyEvent k)
    {
        msg+=k.getKeyChar();
        repaint();
    }
    public void paint(Graphics g)
    {
        g.drawString(msg,X,Y);
    }
}