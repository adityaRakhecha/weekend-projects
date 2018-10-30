import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_SelectCheckBoxes" height=500 width=500></applet>
*/

public class ex_SelectCheckBoxes extends Applet implements ItemListener
{
	String msg = "";
	Checkbox sAll, op1, op2, op3, op4;

	public void init()
	{
		sAll = new Checkbox("Select all", false);
		op1 = new Checkbox("Option 1", true);
		op2 = new Checkbox("Option 2", false);
		op3 = new Checkbox("Option 3", false);
		op4 = new Checkbox("Option 4", false);

		add(sAll);
		add(op1);
		add(op2);
		add(op3);
		add(op4);

		sAll.addItemListener(this);
		op1.addItemListener(this);
		op2.addItemListener(this);
		op3.addItemListener(this);
		op4.addItemListener(this);
	}

	public void itemStateChanged(ItemEvent ie)
	{
		if(ie.getSource() == sAll)
		{
			if(sAll.getState() == true)
			{
				op1.setState(true);
				op2.setState(true);
				op3.setState(true);
				op4.setState(true);
			}
			else
			{
				op1.setState(false);
				op2.setState(false);
				op3.setState(false);
				op4.setState(false);
			}
		}
		
		repaint();
	}
}
