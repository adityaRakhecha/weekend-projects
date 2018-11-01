import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_setRGB" height=500 width=500></applet>
*/

public class ex_setRGB extends Applet implements ActionListener
{
	Label L1, L2, L3;
	Button B1;
	TextField T1, T2, T3;

	public void init()
	{
		L1 = new Label("Red");
		L2 = new Label("Green");
		L3 = new Label("Blue");

		B1 = new Button("OK");

		T1 = new TextField(10);
		T2 = new TextField(10);
		T3 = new TextField(10);

		add(L1);
		add(T1);
		add(L2);
		add(T2);
		add(L3);
		add(T3);
		add(B1);

		B1.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == B1)
		{
			int r,g,b;
			r = Integer.parseInt(T1.getText());
			g = Integer.parseInt(T2.getText());
			b = Integer.parseInt(T3.getText());
			Color c1 = new Color(r,g,b);
			setBackground(c1);
		}
		repaint();
	}

}
