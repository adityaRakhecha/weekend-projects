import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_setBackgroundRGB" height=500 width=500></applet>
*/

public class ex_setBackgroundRGB extends Applet implements ItemListener
{
	Choice C1, C2, C3;

	public void init()
	{
		C1 = new Choice();
		C2 = new Choice();
		C3 = new Choice();
		
		for(int i = 0; i < 256; i++)
			C1.addItem(String.valueOf(i));

		for(int i = 0; i < 256; i++)
			C2.addItem(String.valueOf(i));

		for(int i = 0; i < 256; i++)
			C3.addItem(String.valueOf(i));
		C1.select(14);
		C2.select(214);
		C3.select(114);

		add(C1);
		add(C2);
		add(C3);

		C1.addItemListener(this);
		C2.addItemListener(this);
		C3.addItemListener(this);
	}

	public void itemStateChanged(ItemEvent ie)
	{
		if(ie.getSource() == C1 || ie.getSource() == C2 || ie.getSource() == C3)
		{
			int r,g,b;
			r = Integer.parseInt(C1.getSelectedItem());
			g = Integer.parseInt(C2.getSelectedItem());
			b = Integer.parseInt(C3.getSelectedItem());
			Color c1 = new Color(r,g,b);
			setBackground(c1);
		}

		repaint();
	}
}
