import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_colorCheckboxes" height=500 width=500></applet>
*/

public class ex_colorCheckboxes extends Applet implements ItemListener
{
	Label L1;
	Checkbox op1, op2, op3, op4;
	Font f1, f2, f3, f4;
	
	public void init()
	{
		f1 = new Font("Arial", Font.BOLD, 20);
		f2 = new Font("Arial", Font.ITALIC, 20);
		f3 = new Font("Arial", Font.PLAIN, 20);
		f4 = new Font("Arial", Font.BOLD+Font.ITALIC, 20);

		L1 = new Label("Hello");

		op1 = new Checkbox("Bold");
		op2 = new Checkbox("Italic");
		op3 = new Checkbox("Bold Italic");
		op4 = new Checkbox("Regular");

		add(L1);
		add(op1);
		add(op2);
		add(op3);
		add(op4);

		op1.addItemListener(this);
		op2.addItemListener(this);
		op3.addItemListener(this);
		op4.addItemListener(this);
	}

	public void itemStateChanged(ItemEvent ie)
	{
		if(ie.getSource() == op2)
		{
			if(op2.getState() == true)
			{
				//System.out.println("STATE OP2= "+op2.getState());
				L1.setFont(f2);
			}
			else if(op2.getState() == false)
			{
				//System.out.println("STATE op2 = "+op2.getState());
				L1.setFont(f3);	
			}
		}

		if(ie.getSource() == op1)
		{
			if(op1.getState() == true)
			{
				//System.out.println("STATE OP2= "+op1.getState());	
				L1.setFont(f1);
			}
			else if(op1.getState() == false)
			{
				//System.out.println("STATE op2 = "+op1.getState());
				L1.setFont(f3);	
			}
		}

		if(ie.getSource() == op3)
		{
			if(op3.getState() == true)
			{
				//System.out.println("STATE OP2= "+op3.getState());
				op1.setState(false);
				op2.setState(false);		
				L1.setFont(f4);
			}
			else if(op3.getState() == false)
			{	
				//System.out.println("STATE op2 = "+op3.getState());
				L1.setFont(f3);	
			}
		}

		if(ie.getSource() == op4)
		{
			if(op4.getState() == true)
			{
				//System.out.println("STATE OP2= "+op4.getState());
				op1.setState(false);
				op2.setState(false);
				op3.setState(false);		
				L1.setFont(f3);
			}
			
		}
		repaint();
	}
}
