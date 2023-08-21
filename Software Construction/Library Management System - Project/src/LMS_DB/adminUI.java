package LMS_DB;
import javax.swing.*;
import javax.swing.border.*;
import java.awt.*;
import java.awt.event.*;

public class adminUI extends JFrame implements ActionListener{
    String n;
	adminUI(String n){
		this.n=n;
        String blue = "#3566b5";

        JPanel p1 = new JPanel();
        p1.setLayout(new GridLayout());
        p1.setBounds(5,10,700,50);
        JLabel label = new JLabel("DRSM LIBRARY MANAGEMENT SYSTEM");
        label.setForeground(Color.decode(blue));
        label.setFont(new Font("Times New Roman",Font.BOLD,32));
        p1.add(label);


        JPanel p2 = new JPanel();
        p2.setLayout(new GridLayout());
        p2.setBounds(650,12,220,50);
        JLabel name = new JLabel(n);
        name.setForeground(Color.BLACK);
        name.setHorizontalAlignment(SwingConstants.RIGHT);
        name.setFont(new Font("Calibri",Font.BOLD,20));
        p2.add(name);

        JButton logout = new JButton("Logout");
        logout.setBackground(Color.decode(blue));
        logout.setForeground(Color.white);
        logout.setFont(new Font("Times New Roman", Font.PLAIN, 15));
        logout.addActionListener(this);

        JPanel p3 = new JPanel();
        p3.setBounds(880,18,80,30);
        p3.setLayout(new GridLayout());
        p3.add(logout);

        JButton add = new JButton("Add Staff");
        add.setBackground(Color.decode(blue));
        add.setForeground(Color.white);
        add.setFont(new Font("Times New Roman", Font.PLAIN, 20));
        add.addActionListener(this);

        JButton update = new JButton("Update Staff");
        update.setBackground(Color.decode(blue));
        update.setForeground(Color.white);
        update.setFont(new Font("Times New Roman", Font.PLAIN, 20));
        update.addActionListener(this);

        JButton search = new JButton("Search Staff");
        search.setBackground(Color.decode(blue));
        search.setForeground(Color.white);
        search.setFont(new Font("Times New Roman", Font.PLAIN, 20));
        search.addActionListener(this);
        
        JPanel p4 = new JPanel();
        p4.setLayout(new GridLayout(4,1,0,10));
        p4.setBounds(340,170,320,200);
        p4.add(add);
        p4.add(update);
        p4.add(search);



        setTitle("DRSM LMS");
        setSize(1000,600);
        setVisible(true);
        setLayout(null);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        add(p1);
        add(p2);
        add(p3);
        add(p4);
    }
    
    @Override
	public void actionPerformed(ActionEvent e){
        JButton b = (JButton)e.getSource();
        String btn = b.getText();
        if(btn == "Add Staff"){
            dispose();
			new addStaff(n);
        }
        if(btn == "Update Staff"){
            dispose();
			new updateStaff(n);
        }
        if(btn == "Search Staff"){
            dispose();
			new searchStaff(n);
        }
        if(btn =="Logout"){
            dispose();
			new home();
        }
    }
    public static void main(String[] args) {
//        adminUI obj = new adminUI();
    }
}
