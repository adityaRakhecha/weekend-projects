import java.applet.*;
import java.awt.*;
import java.awt.event.*;

/**
<applet code="ex_AddSwap" height=500 width=500></applet>
*/

public class ex_AddSwap extends Applet implements ActionListener, ItemListener
{
	String msg = "";
	Checkbox Add, Swap;
	CheckboxGroup cbg;

	Button B1, B2;
	TextField T1, T2, T3;
	Label L1, L2;

	public void init()
	{
		
		cbg = new CheckboxGroup();
		Add = new Checkbox("Add", cbg, true);
		Swap = new Checkbox("Swap", cbg, false);

		L1 = new Label("Enter Number1: ");
		L2 = new Label("Enter Number2: ");
		T1 = new TextField(12);
		T2 = new TextField(12);
		T3 = new TextField(12);

		B1 = new Button("Add");
		B2 = new Button("Swap");

		add(L1);
		add(T1);
		add(L2);
		add(T2);

		add(T3);
		add(Add);
		add(B1);
		add(Swap);
		add(B2);
		B1.addActionListener(this);
		B2.addActionListener(this);

	}

	public void itemStateChanged(ItemEvent ie)
	{
		repaint();
	}

	public void actionPerformed(ActionEvent ae)
	{
		int a = Integer.parseInt(T1.getText());
		int b = Integer.parseInt(T2.getText());

		if(ae.getSource() == B1 && Add.getState() == true)
		{
			
			String str = String.valueOf(a+b);
			T3.setText(str);

		}
		if(ae.getSource() == B2 && Swap.getState() == true)
		{
			int c = a;
			a = b;
			b = c;
			String str1 = String.valueOf(a);
			String str2 = String.valueOf(b);
			T1.setText(str1);
			T2.setText(str2); 
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
