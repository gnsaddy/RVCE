package testapplet;
import java.awt.*;
import java.applet.*;
/*
<applet code="TestApplet" width=200 height=60>
</applet>
*/
public class TestApplet extends Applet {
    public void paint(Graphics g) {
        g.drawString("A Simple Applet", 20, 20);
    }
}