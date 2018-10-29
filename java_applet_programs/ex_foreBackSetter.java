//Java applet program to select foreground and background color
import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_foreBackSetter" height=500 width=500></applet>
*/

public class ex_foreBackSetter extends Applet implements ActionListener, ItemListener
{
	String msg = "";
	Label L1;
	Button B1, B2, B3, B4;
	CheckboxGroup cbg;
	Checkbox op1, op2;

	public void init()
	{
		cbg = new CheckboxGroup();
		op1 = new Checkbox("Foreground", cbg, true);
		op2 = new Checkbox("Background", cbg, false);

		L1 = new Label("Hello World");

		B1 = new Button("RED");
		B2 = new Button("YELLOW");
		B3 = new Button("GREEN");
		B4 = new Button("BLUE");

		add(L1);
		add(op1);
		add(B1);
		add(B2);
		add(op2);
		add(B3);
		add(B4);
		
		B1.addActionListener(this);
		B2.addActionListener(this);
		B3.addActionListener(this);
		B4.addActionListener(this);
	}


	public void itemStateChanged(ItemEvent ie)
	{
		repaint();
	}

	public void actionPerformed(ActionEvent ae)
	{
		if(ae.getSource() == B1 && op1.getState() == true)
		{
			setForeground(Color.RED);

		}
		if(ae.getSource() == B2 && op1.getState() == true)
		{
			setForeground(Color.YELLOW);

		}
		if(ae.getSource() == B3 && op2.getState() == true)
		{
			setBackground(Color.GREEN);
		}
		if(ae.getSource() == B4 && op2.getState() == true)
		{
			setBackground(Color.BLUE);
		}
		repaint();
	}

	public void paint(Graphics g)
	{
		msg = "Current selection: ";
		msg += cbg.getSelectedCheckbox().getLabel();
		g.drawString(msg, 200, 100);
	}
}
